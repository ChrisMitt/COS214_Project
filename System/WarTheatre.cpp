#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "WarTheatre.h"

using namespace std;

WarTheatre::WarTheatre(list<CountryObserver*> d, list<CountryObserver*> a, string area, string country, list<Alliance*> aa){
    this->area = area;
    this->country = country;
    srand( time(NULL) );

    Alliance* dAlliance = d.front()->getSubject();
    defenders = new Squad(d, dAlliance->getName());
    
    

    Alliance* aAlliance = a.front()->getSubject();
    attackers = new Squad(a, aAlliance->getName());

    allAlliances=aa;

    deploySoldiers = new DeployContext( new SoldierDeploy(this) );
    deployTanks = new DeployContext( new TankDeploy(this) );
}

WarTheatre::WarTheatre(list<Alliance*> as){

}

void WarTheatre::printInit(){
    cout << "***********************************\n";
    cout << "****** W A R  T H E A T R E *******\n";
    cout << "***********************************\n";
    cout << "Country: " <<country<<endl;
    cout << "Area - ";
    if(area=="land"){
        cout<<"LAND: ground and air units can fight here\n";
    }else if(area=="sea"){
        cout<<"SEA: navy and air units can fight here\n";
    }else if(area=="mountains"){
        cout<<"MOUNTAINS: only air units can fight here\n";
    }
    cout << "***********************************\n";

    cout<<"=============================\n";
    cout<<"DEFENDERS: \n";
    defenders->printSquad();
    cout<<"\n=============================\n";
    cout<<"ATTACKERS: \n";
    attackers->printSquad();
    cout<<"\n=============================\n";
}

void WarTheatre::fillLists(){
    //Soldiers
    int maxSoldiersSize=0;
    defenders->getSoldiers().size() >= attackers->getSoldiers().size() ? maxSoldiersSize = defenders->getSoldiers().size() : maxSoldiersSize = attackers->getSoldiers().size();
    //allSoldiersSize = defenders->getSoldiers().size() + attackers->getSoldiers().size();
    for(int i=0; i<maxSoldiersSize; i++){
        if(i<defenders->getSoldiers().size()){
            allSoldiers.push_back( defenders->getSoldiers()[i] );
        }
        if(i<attackers->getSoldiers().size()){
            allSoldiers.push_back( attackers->getSoldiers()[i] );
        }
    }

    //Tanks
    int maxTanksSize=0;
    defenders->getTanks().size() >= attackers->getTanks().size() ? maxTanksSize = defenders->getTanks().size() : maxTanksSize = attackers->getTanks().size();
    for(int i=0; i<maxTanksSize; i++){
        if(i<defenders->getTanks().size()){
            allTanks.push_back(defenders->getTanks()[i]);
        }
        if(i<attackers->getTanks().size()){
            allTanks.push_back( attackers->getTanks()[i] );
        }
    }
}

WarTheatre::~WarTheatre(){
    delete deploySoldiers;
    delete deployTanks;
}

void WarTheatre::battle(){
    fillLists();
    printInit();
    fight();
    
    //clearLists();
    deleteUnits();
}

void WarTheatre::fight(){
    deploySoldiers->go();
    deployTanks->go();
    //medicsHeal();
}



Person* WarTheatre::getRandPerson(string type, Squad* squad){
    if(type=="soldier"){
        int randSoldIdx = rand() % squad->getSoldiers().size();
        Soldier* randSold = squad->getSoldiers()[randSoldIdx];
        return randSold;
    }
    return nullptr;
}

void WarTheatre::tanksFight(){
    cout<<"== 2: TANKS FIGHTING: ==\n";
    if(defenders->getTanks().size()==0 || attackers->getTanks().size()==0){
        return;
    }
    
    for(auto it=allTanks.begin(); it!=allTanks.end(); it++){
        Tank* currTank = *it; //current tank attacking
        if(currTank->isAlive()){
            Squad* enemySquad; //the enemy squad of the current tank's squad
            //1. set who the enemy squad is
            if( defenders->contains(currTank) ){//if curr tank is a defender
                enemySquad = attackers;
            }else if( attackers->contains(currTank) ){
                enemySquad = defenders;
            }

            //2. decide to aim for a tank or for soldiers
            int randNum = rand()%100+1;

            //if decided on tank
            if(enemySquad->getTanks().size()>0 &&  (randNum<=50 || enemySquad->getSoldiers().size()==0) ){
                if(enemySquad->getTanks().size()>0){
                    //3. hit random enemy tank
                    Tank* enemyTank = (Tank*) (getRandVehicle("tank", enemySquad));
                    currTank->doDamage(enemyTank);
                    //4. remove the random tank from the enemy squad, if he died
                    if(!enemyTank->isAlive()){
                        enemySquad->remove(enemyTank);
                        deadTanks.push_back(enemyTank);
                    }
                }
            }else{
                int maxSoldiersHit = 5;
                if(enemySquad->getSoldiers().size()<maxSoldiersHit){
                    maxSoldiersHit = enemySquad->getSoldiers().size();
                }
                int amountHit = rand()%maxSoldiersHit+1;
                cout<<currTank->getType()<<" kills "<<amountHit<<" enemy soldiers\n";
                for(int i=0; i<maxSoldiersHit; i++){
                    Soldier* randSoldier = (Soldier*)getRandPerson("soldier", enemySquad);
                    currTank->doDamage(randSoldier);
                    enemySquad->remove(randSoldier);
                    deadSoldiers.push_back(randSoldier);
                }
            }
        }
    }
}

Vehicle* WarTheatre::getRandVehicle(string type, Squad* squad){
    if(type=="tank"){
        int randTankIdx = rand() % squad->getTanks().size();
        Tank* randTank = squad->getTanks()[randTankIdx];
        return randTank;
    }
    return nullptr;
}

void WarTheatre::clearLists(){
    delete defenders;
    delete attackers;
}

//This will delete the units globally
void WarTheatre::deleteUnits(){
    //soldiers
    for(auto it=deadSoldiers.begin(); it!=deadSoldiers.end(); it++){
        (*it)->getCountry()->removeSoldier(*it);
    }
    for(auto it=deadSoldiers.begin(); it!=deadSoldiers.end(); it++){
        delete (*it);
    }

    //tanks
    for(auto it=deadTanks.begin(); it!=deadTanks.end(); it++){
        (*it)->getCountry()->removeTank(*it);
    }
    for(auto it=deadTanks.begin(); it!=deadTanks.end(); it++){
        delete (*it);
    }
}

Squad* WarTheatre::getDefenders(){
    return defenders;
}

Squad* WarTheatre::getAttackers(){
    return attackers;
}
