#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "WarTheatre.h"

using namespace std;

WarTheatre::WarTheatre(list<Alliance*> aa){
    list<CountryObserver*> d;
    list<CountryObserver*> a;

    bool valid=false;
    int input=0;
    int i=0;
    while(!valid){
        system("clear");
        cout<<"\nWhich alliance will be defending?\n";
        for(auto it=aa.begin(); it!=aa.end(); it++){
            cout<<"["<<i+1<<"]"<<" "<<(*it)->getName()<<endl;
            i++;
        }
        cin>>input;
        if(input==1){
            valid=true;
            d = aa.front()->getCountryList();
            a = aa.back()->getCountryList();
        }else if(input==2){
            valid=true;
            d = aa.back()->getCountryList();
            a = aa.front()->getCountryList();
        }else{
            cout<<"Invalid input\n";
        }
    }
    valid=false;

    while(!valid){
        system("clear");
        i=0;
        cout<<"\nWhere should the battle take place?\n";
        for(auto it=d.begin(); it!=d.end(); it++){
            cout<<"["<<i+1<<"]"<<" "<<(*it)->getName()<<endl;
            i++;
        }
        cin>>input;
        if(input>=1 && input<=d.size()){
            valid=true;
            auto it=d.begin();
            advance(it, input-1);
            country = (*it)->getName();
        }else{
            cout<<"Invalid input"<<endl;
        }
    }
    valid=false;

    while(!valid){
        system("clear");
        i=0;
        cout<<"\nSelect the area where the battle will take place\n";
        cout<<"[1] Land: Ground and air units will fight here\n";
        cout<<"[2] Sea: Navy and air units will fight here\n";
        cout<<"[3] Mountains: Only air units will fight here\n";
        cin>>input;
        if(input==1){
            valid=true;
            area="land";
        }else if(input==2){
            valid=true;
            area="sea";
        }else if(input==3){
            valid=true;
            area="mountains";
        }else{
            cout<<"Invalid input"<<endl;
        }
    }
    valid=false;

    srand( time(NULL) );

    dAlliance = d.front()->getSubject();
    defenders = new Squad(d, dAlliance->getName());
    
    aAlliance = a.front()->getSubject();
    attackers = new Squad(a, aAlliance->getName());

    allAlliances=aa;

    deployments.push_back( new DeployContext( new SoldierDeploy(this) ) );
    deployments.push_back( new DeployContext( new TankDeploy(this) ) );
    deployments.push_back( new DeployContext( new ShipDeploy(this) ) );
    deployments.push_back( new DeployContext( new PlaneDeploy(this) ) );
    deployments.push_back( new DeployContext( new MedicDeploy(this) ) );
    deployments.push_back( new DeployContext( new MechanicDeploy(this) ) );
}

void WarTheatre::printInit(){
    system("clear");
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

    cout<<"\n=============================\n";
    cout<<"DEFENDERS: " << dAlliance->getName() <<endl;
    defenders->printSquad();
    cout<<"\n=============================\n";
    cout<<"ATTACKERS: " << aAlliance->getName() <<endl;
    attackers->printSquad();
    cout<<"\n=============================\n";
    
    bool valid=false;
    while(!valid){
        cout<<"ENTER [1] TO CONTINUE"<<endl;
        int input;
        cin>>input;
        if(input==1){
            valid=true;
        }else{
            system("clear");
            cout<<"Invalid input"<<endl;
        }
    }
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

    //Ships
    int maxShipSize=0;
    defenders->getShips().size() >= attackers->getShips().size() ? maxShipSize = defenders->getShips().size() : maxShipSize = attackers->getShips().size();
    for(int i=0; i<maxShipSize; i++){
        if(i<defenders->getShips().size()){
            allShips.push_back(defenders->getShips()[i]);
        }
        if(i<attackers->getShips().size()){
            allShips.push_back( attackers->getShips()[i] );
        }
    }

    //Planes
    int maxPlaneSize=0;
    defenders->getPlanes().size() >= attackers->getPlanes().size() ? maxPlaneSize = defenders->getPlanes().size() : maxPlaneSize = attackers->getPlanes().size();
    for(int i=0; i<maxPlaneSize; i++){
        if(i<defenders->getPlanes().size()){
            allPlanes.push_back(defenders->getPlanes()[i]);
        }
        if(i<attackers->getPlanes().size()){
            allPlanes.push_back( attackers->getPlanes()[i] );
        }
    }

    //Medics
    int maxMedicSize=0;
    defenders->getMedics().size() >= attackers->getMedics().size() ? maxMedicSize = defenders->getMedics().size() : maxMedicSize = attackers->getMedics().size();
    for(int i=0; i<maxMedicSize; i++){
        if(i<defenders->getMedics().size()){
            allMedics.push_back(defenders->getMedics()[i]);
        }
        if(i<attackers->getMedics().size()){
            allMedics.push_back( attackers->getMedics()[i] );
        }
    }

    //Mechanics
    int maxMechanicSize=0;
    defenders->getMechanics().size() >= attackers->getMechanics().size() ? maxMechanicSize = defenders->getMechanics().size() : maxMechanicSize = attackers->getMechanics().size();
    for(int i=0; i<maxMechanicSize; i++){
        if(i<defenders->getMechanics().size()){
            allMechanics.push_back(defenders->getMechanics()[i]);
        }
        if(i<attackers->getMechanics().size()){
            allMechanics.push_back( attackers->getMechanics()[i] );
        }
    }
}

WarTheatre::~WarTheatre(){
    for(auto it = deployments.begin(); it!=deployments.end(); it++){
        delete (*it);
    }
}

void WarTheatre::battle(){
    fillLists();
    printInit();
    fight();
    printResult();
    //clearLists();
    deleteUnits();
}

void WarTheatre::fight(){
    for(auto it = deployments.begin(); it!=deployments.end(); it++){
        (*it)->go();
        cout<<endl<<endl;
    }
}



Person* WarTheatre::getRandPerson(string type, Squad* squad){
    if(type=="soldier"){
        int randSoldIdx = rand() % squad->getSoldiers().size();
        Soldier* randSold = squad->getSoldiers()[randSoldIdx];
        return randSold;
    }
    return nullptr;
}

Vehicle* WarTheatre::getRandVehicle(string type, Squad* squad){
    if(type=="tank"){
        int randTankIdx = rand() % squad->getTanks().size();
        Tank* randTank = squad->getTanks()[randTankIdx];
        return randTank;
    }
    if(type=="ship"){
        int randShipIdx = rand() % squad->getShips().size();
        Ship* randShip = squad->getShips()[randShipIdx];
        return randShip;
    }
    if(type=="plane"){
        int randPlaneIndex = rand() % squad->getPlanes().size();
        Plane* randPlane = squad->getPlanes()[randPlaneIndex];
        return randPlane;
    }

    return nullptr;
}

void WarTheatre::clearLists(){
    delete defenders;
    delete attackers;
}

void WarTheatre::printResult(){
    int defenderFirePower;
    int attackerFirePower;

    cout<< "\n\n#############################\n";
    cout << "######## R E S U L T ########\n";
    if(defenders->calcFirepower() > attackers->calcFirepower() ){
        cout << dAlliance->getName() << " won the battle!" <<endl;
    }else{
        cout << aAlliance->getName() << " won the battle!" <<endl;
    }
    cout<<"a result of having the largest remaining firepower"<<endl;
    cout<< "#############################\n\n";

    cout << "- DEFENDERS: " << dAlliance->getName() << "-" << endl;
    cout << "REMAINING FIREPOWER: " << defenders->calcFirepower() << endl;
    cout << "Enemy soldiers killed: " << defenders->getSoldiersKilled() <<endl;
    cout << "Enemy tanks killed: " << defenders->getTanksKilled() <<endl;
    cout << "Enemy ships killed: " << defenders->getShipsKilled() <<endl;
    cout << "Enemy planes killed: " << defenders->getPlanesKilled() <<endl;
    cout << "Friendly soldiers hospitalized: "<< defenders->getHospCount() <<endl;
    cout << "Friendly tank repairs: "<< defenders->getTankRepairs() <<endl;
    
    cout<<endl<<"------------------------"<<endl;

    cout << "- ATTACKERS: " << aAlliance->getName() << " -" << endl;
    cout << "REMAINING FIREPOWER: " << attackers->calcFirepower() << endl;
    cout << "Enemy soldiers killed: " << attackers->getSoldiersKilled() <<endl;
    cout << "Enemy tanks killed: " << attackers->getTanksKilled() <<endl;
    cout << "Enemy ships killed: " << attackers->getShipsKilled() <<endl;
    cout << "Enemy planes killed: " << attackers->getPlanesKilled() <<endl;
    cout << "Friendly soldiers hospitalized: "<< attackers->getHospCount() <<endl;
    cout << "Friendly tank repairs: "<< attackers->getTankRepairs() <<endl;
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

    //ships
    for(auto it=deadShips.begin(); it!=deadShips.end(); it++){
        (*it)->getCountry()->removeShip(*it);
    }
    for(auto it=deadShips.begin(); it!=deadShips.end(); it++){
        delete (*it);
    }

    //planes
    for(auto it=deadPlanes.begin(); it!=deadPlanes.end(); it++){
        (*it)->getCountry()->removePlane(*it);
    }
    for(auto it=deadPlanes.begin(); it!=deadPlanes.end(); it++){
        delete (*it);
    }
}

Squad* WarTheatre::getDefenders(){
    return defenders;
}

Squad* WarTheatre::getAttackers(){
    return attackers;
}

void WarTheatre::createResources(Country* co) {

    int unitType = (rand()%4)+1;
    int val = co->resources;
    ResourceManagement* rs = new UnitProducer(60, 4);
    rs->add(new UnitProducer(40, 3));
    rs->add(new UnitProducer(20, 2));
    rs->add(new UnitProducer(2, 1));

    int ret = rs->createUpgradedUnit(unitType, co);
    int choice = (rand()%1);


    switch (ret) {
        case 0:
            break;
        {case 1:
            Soldier* upgradedSoldier;
            if(choice==1){
                upgradedSoldier = new Soldier("//", "Deployed", new ExtraHealth(new Research));
            }
            else{
                upgradedSoldier = new Soldier("Heavy", "Deployed", new ExtraDamage(new Research));
            }
            co->soldiers.push_back(upgradedSoldier);
            break;}

        {case 2:
            Tank* upgradedTank;
            if(choice==1){
                upgradedTank = new Tank("Tiger", "Deployed", new ExtraHealth(new Research));
            }
            else{
                upgradedTank = new Tank("Tiger", "Deployed", new ExtraDamage(new Research));
            }
            co->tanks.push_back(upgradedTank);
            break;}

        {case 3:
            Plane* upgradedPlane;
            if(choice==1){
                upgradedPlane = new Plane("Bomber", "Deployed", new ExtraHealth(new Research));
            }
            else{
                upgradedPlane = new Plane("Fighter", "Deployed", new ExtraDamage(new Research));
            }
            co->planes.push_back(upgradedPlane);
            break;}

        {case 4:
            Ship* upgradedShip;
            if(choice==1){
                upgradedShip = new Ship("Cruiser", "Deployed", new ExtraHealth(new Research));
            }
            else{
                upgradedShip = new Ship("Destroyer", "Deployed", new ExtraDamage(new Research));
            }
            co->ships.push_back(upgradedShip);
            break;}
    }
}
