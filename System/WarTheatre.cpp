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

    deployments.push_back( new DeployContext( new SoldierDeploy(this) ) );
    deployments.push_back( new DeployContext( new TankDeploy(this) ) );
    deployments.push_back( new DeployContext( new ShipDeploy(this) ) );
    deployments.push_back( new DeployContext( new PlaneDeploy(this) ) );
    deployments.push_back( new DeployContext( new MedicDeploy(this) ) );
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
