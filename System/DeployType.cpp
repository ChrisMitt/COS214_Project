#include "DeployType.h"
#include "WarTheatre.h"

DeployType::DeployType(WarTheatre* w)
{
    this->w = w;
    defenders = w->getDefenders();
    attackers = w->getAttackers();
}

DeployType::~DeployType()
{
}

SoldierDeploy::SoldierDeploy(WarTheatre* w) : DeployType(w){

}

void SoldierDeploy::deploy(){
    cout<<"== 1: SOLDIERS FIGHTING =="<<endl;
    if(defenders->getSoldiers().size()==0 || attackers->getSoldiers().size()==0){
        return;
    }
    //for all soldiers do
    for(auto it=w->allSoldiers.begin(); it!=w->allSoldiers.end(); it++){
        Soldier* currSoldier = *it; //current soldier attacking
        //Soldier* currSoldier = allSoldiers[i];
        if(currSoldier->isAlive()){
            Squad* enemySquad; //the enemy squad of the current soldier's squad
            Squad* mySquad;
            //1. set who the enemy squad is
            if( defenders->contains(currSoldier) ){//if curr soldier is a defender
                enemySquad = attackers;
                mySquad = defenders;
            }else if( attackers->contains(currSoldier) ){
                enemySquad = defenders;
                mySquad=attackers;
            }
            if(enemySquad->getSoldiers().size()>0){
                //2. get a random soldier in the enemy squad
                Soldier* enemySoldier = (Soldier*) (w->getRandPerson("soldier", enemySquad));

                //3. do damage to the random enemy
                currSoldier->doDamage(enemySoldier);

                //4. remove the random soldier from the enemy squad, if he died
                if(!enemySoldier->isAlive()){
                    mySquad->increaseSoldiersKilled(1);
                    enemySquad->remove(enemySoldier);
                    w->deadSoldiers.push_back(enemySoldier);
                }
            }
        }
    }
}

TankDeploy::TankDeploy(WarTheatre* w) : DeployType(w){

}

void TankDeploy::deploy(){
    cout<<"== 2: TANKS FIGHTING: ==\n";
    if(defenders->getTanks().size()==0 || attackers->getTanks().size()==0){
        return;
    }
    
    for(auto it=w->allTanks.begin(); it!=w->allTanks.end(); it++){
        Tank* currTank = *it; //current tank attacking
        if(currTank->isAlive()){
            Squad* enemySquad; //the enemy squad of the current tank's squad
            Squad* mySquad;
            //1. set who the enemy squad is
            if( defenders->contains(currTank) ){//if curr tank is a defender
                enemySquad = attackers;
                mySquad=defenders;
            }else if( attackers->contains(currTank) ){
                enemySquad = defenders;
                mySquad=attackers;
            }

            if(enemySquad->getSoldiers().size()!=0 || enemySquad->getTanks().size()!=0 ){
                //2. decide to aim for a tank or for soldiers
                int randNum = rand()%100+1;

                //if decided on tank
                if(enemySquad->getTanks().size()>0 &&  (randNum<=50 || enemySquad->getSoldiers().size()==0) ){
                    if(enemySquad->getTanks().size()>0){
                        //3. hit random enemy tank
                        Tank* enemyTank = (Tank*) (w->getRandVehicle("tank", enemySquad));
                        currTank->doDamage(enemyTank);
                        //4. remove the random tank from the enemy squad, if he died
                        if(!enemyTank->isAlive()){
                            mySquad->increaseTanksKilled(1);
                            enemySquad->remove(enemyTank);
                            w->deadTanks.push_back(enemyTank);
                        }
                    }
                }else{
                    int maxSoldiersHit = 5;
                    if(enemySquad->getSoldiers().size()<maxSoldiersHit){
                        maxSoldiersHit = enemySquad->getSoldiers().size();
                    }
                    int amountHit = rand()%maxSoldiersHit+1;
                    cout<<currTank->getType()<<" kills "<<amountHit<<" enemy soldiers\n";
                    mySquad->increaseSoldiersKilled(amountHit);
                    for(int i=0; i<amountHit; i++){
                        Soldier* randSoldier = (Soldier*)w->getRandPerson("soldier", enemySquad);
                        currTank->doDamage(randSoldier);
                        enemySquad->remove(randSoldier);
                        w->deadSoldiers.push_back(randSoldier);
                    }
                    cout<<"---------------------\n";
                }
            }
        }
    }
}

ShipDeploy::ShipDeploy(WarTheatre* w) : DeployType(w){

}

void ShipDeploy::deploy(){
    cout<<"== 3: SHIPS FIGHTING =="<<endl;
    if(defenders->getShips().size()==0 || attackers->getShips().size()==0){
        return;
    }
    //for all ships do
    for(auto it=w->allShips.begin(); it!=w->allShips.end(); it++){
        Ship* currShip = *it; //current ship attacking
        if(currShip->isAlive()){
            Squad* enemySquad; //the enemy squad of the current ship's squad
            Squad* mySquad;
            //1. set who the enemy squad is
            if( defenders->contains(currShip) ){//if curr ship is a defender
                enemySquad = attackers;
                mySquad=defenders;
            }else if( attackers->contains(currShip) ){
                enemySquad = defenders;
                mySquad=attackers;
            }
            if(enemySquad->getShips().size()>0){
                //2. get a random ship in the enemy squad
                Ship* enemyShip = (Ship*) (w->getRandVehicle("ship", enemySquad));

                //3. do damage to the random enemy
                currShip->doDamage(enemyShip);

                //4. remove the random ship from the enemy squad, if he died
                if(!enemyShip->isAlive()){
                    mySquad->increaseShipsKilled(1);
                    enemySquad->remove(enemyShip);
                    w->deadShips.push_back(enemyShip);
                }
            }
        }
    }
}

PlaneDeploy::PlaneDeploy(WarTheatre* w) : DeployType(w){

}

void PlaneDeploy::deploy(){
    cout<<"== 4: PLANES FIGHTING =="<<endl;
    if(defenders->getPlanes().size()==0 || attackers->getPlanes().size()==0){
        return;
    }
    cout<<"ps: "<<w->allPlanes.size()<<endl;
    for(auto it=w->allPlanes.begin(); it!=w->allPlanes.end(); it++){
        Plane* currPlane = *it; 
        if(currPlane->isAlive()){
            Squad* enemySquad;
            Squad* mySquad;
            //1. set who the enemy squad is
            if( defenders->contains(currPlane) ){
                enemySquad = attackers;
                mySquad=defenders;
            }else if( attackers->contains(currPlane) ){
                enemySquad = defenders;
                mySquad=attackers;
            }
            
            if(
                (enemySquad->getPlanes().size()!=0) ||
                (enemySquad->getTanks().size()!=0) ||
                (enemySquad->getSoldiers().size()!=0) ||
                (enemySquad->getShips().size()!=0)
            )
            {
                //2. decide to aim for a tank, soldiers, boat, or plane
                vector<string> unitTypes;
                if(enemySquad->getPlanes().size()!=0){
                    unitTypes.push_back("plane");
                }
                if(enemySquad->getSoldiers().size()!=0){
                    unitTypes.push_back("soldier");
                }
                if(enemySquad->getTanks().size()!=0){
                    unitTypes.push_back("tank");
                }
                if(enemySquad->getShips().size()!=0){
                    unitTypes.push_back("ship");
                }
                int typeIdx = rand()%unitTypes.size();
                
                if(unitTypes[typeIdx]=="plane"){
                    Plane* enemyPlane= (Plane*) (w->getRandVehicle("plane", enemySquad));
                    currPlane->doDamage(enemyPlane);
                    //4. remove the random plane from the enemy squad, if he died
                    if(!enemyPlane->isAlive()){
                        mySquad->increasePlanesKilled(1);
                        enemySquad->remove(enemyPlane);
                        w->deadPlanes.push_back(enemyPlane);
                    }
                }else if(unitTypes[typeIdx]=="ship"){
                    Ship* enemyShip= (Ship*) (w->getRandVehicle("ship", enemySquad));
                    currPlane->doDamage(enemyShip);
                    //4. remove the random ship from the enemy squad, if he died
                    if(!enemyShip->isAlive()){
                        mySquad->increaseShipsKilled(1);
                        enemySquad->remove(enemyShip);
                        w->deadShips.push_back(enemyShip);
                    }
                }else if(unitTypes[typeIdx]=="tank"){
                    Tank* enemyTank= (Tank*) (w->getRandVehicle("tank", enemySquad));
                    currPlane->doDamage(enemyTank);
                    //4. remove the random tank from the enemy squad, if he died
                    if(!enemyTank->isAlive()){
                        mySquad->increaseTanksKilled(1);
                        enemySquad->remove(enemyTank);
                        w->deadTanks.push_back(enemyTank);
                    }
                }else if(unitTypes[typeIdx]=="soldier"){
                    int maxSoldiersHit = 10;
                    if(enemySquad->getSoldiers().size()<maxSoldiersHit){
                        maxSoldiersHit = enemySquad->getSoldiers().size();
                    }
                    int amountHit = rand()%maxSoldiersHit+1;
                    cout<<currPlane->getType()<<" carpet bombs "<<amountHit<<" enemy soldiers\n";
                    mySquad->increaseSoldiersKilled(amountHit);
                    for(int i=0; i<amountHit; i++){
                        Soldier* randSoldier = (Soldier*)w->getRandPerson("soldier", enemySquad);
                        currPlane->doDamage(randSoldier);
                        enemySquad->remove(randSoldier);
                        w->deadSoldiers.push_back(randSoldier);
                    }
                    cout<<"---------------------\n";
                }
            }

        }
    }
}

MedicDeploy::MedicDeploy(WarTheatre* w) : DeployType(w){

}

void MedicDeploy::deploy(){
    cout<<"== 5: MEDICS DEPLOYED =="<<endl;
    for( auto it = w->allSoldiers.begin(); it!=w->allSoldiers.end(); it++){
        Soldier* currSoldier = (*it);
        if( currSoldier->getHealth()!=0 && currSoldier->getHealth()<200 ){
            if( currSoldier->getCountry()->getSubject()== w->dAlliance ){
                defenders->increaseHospCount(1);
            }else{
                attackers->increaseHospCount(1);
            }
            cout << "Medic healing: " << currSoldier->getType()<<endl;
        }
    }
    /*if( defenders->getSoldiers().size() == 0 || attackers->getSoldiers().size()==0 ){
        return;
    }
    
    for(auto it=w->allMedics.begin(); it!=w->allMedics.end(); it++){
        Medic* currMedic = *it;
        Squad* currSquad;
        if( defenders->contains(currMedic) ){
            currSquad = defenders;
        }else{
            currSquad = attackers;
        }
        cout<<"a\n";
        for(auto tIT=currSquad->getSoldiers().begin(); tIT!=currSquad->getSoldiers().end(); tIT++){
            cout<<"b\n";
            if( (*tIT)!=NULL && ( (*tIT)->getHealth()>0 ) && ( (*tIT)->getHealth()<=50 ) ){
                cout<<"c\n";
                cout<< currMedic->getType() <<" sends " << (*tIT)->getType() << " to the hospital to fight another day\n";
                (*tIT)->setHealth(200);
                currSquad->increaseHospCount(1);
                break;
            }
        }
    }*/
}

MechanicDeploy::MechanicDeploy(WarTheatre* w) : DeployType(w){

}

void MechanicDeploy::deploy(){
    cout<<"== 6: MECHANICS DEPLOYED =="<<endl;
    for( auto it = w->allTanks.begin(); it!=w->allTanks.end(); it++){
        Tank* currTank = (*it);
        if( currTank->getHealth()!=0 && currTank->getHealth()<2000 ){
            if( currTank->getCountry()->getSubject()== w->dAlliance ){
                defenders->increaseTankRepairs(1);
            }else{
                attackers->increaseTankRepairs(1);
            }
            cout << "Mechanic healing: " << currTank->getType()<<endl;
        }
    }

    /*if( defenders->getTanks().size() == 0 && attackers->getTanks().size()==0 ){
        return;
    }
    
    for(auto it=w->allMechanics.begin(); it!=w->allMechanics.end(); it++){
        Mechanic* currMechanic = *it;
        Squad* currSquad;
        if( defenders->contains(currMechanic) ){
            currSquad = defenders;
        }else{
            currSquad = attackers;
        }
        for(auto tIT=currSquad->getTanks().begin(); tIT!=currSquad->getTanks().end(); tIT++){
            if( (*tIT)!=NULL && ( (*tIT)->getHealth()>0 ) && ( (*tIT)->getHealth()<=1000 ) ){
                cout<< currMechanic->getType() <<" repaired " << (*tIT)->getType() << endl;
                (*tIT)->setHealth(2000);
                currSquad->increaseTankRepairs(1);
                break;
            }
        }
    }*/
}
