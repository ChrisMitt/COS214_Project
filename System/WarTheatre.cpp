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

}

void WarTheatre::battle(){
    fillLists();
    printInit();
    fight();
    
    //clearLists();
    deleteUnits();
}

void WarTheatre::fight(){
    //soldiersFight();
    tanksFight();
    //medicsHeal();
}

void WarTheatre::soldiersFight(){
    cout<<"== 1: SOLDIERS FIGHTING =="<<endl;
    if(defenders->getSoldiers().size()==0 || attackers->getSoldiers().size()==0){
        return;
    }
    //for all soldiers do
    for(auto it=allSoldiers.begin(); it!=allSoldiers.end(); it++){
        Soldier* currSoldier = *it; //current soldier attacking
        //Soldier* currSoldier = allSoldiers[i];
        if(currSoldier->isAlive()){
            Squad* enemySquad; //the enemy squad of the current soldier's squad
            //1. set who the enemy squad is
            if( defenders->contains(currSoldier) ){//if curr soldier is a defender
                enemySquad = attackers;
            }else if( attackers->contains(currSoldier) ){
                enemySquad = defenders;
            }
            //2. get a random soldier in the enemy squad
            Soldier* enemySoldier = (Soldier*) (getRandPerson("soldier", enemySquad));

            //3. do damage to the random enemy
            currSoldier->doDamage(enemySoldier);

            //4. remove the random soldier from the enemy squad, if he died
            if(!enemySoldier->isAlive()){
                enemySquad->remove(enemySoldier);
                deadSoldiers.push_back(enemySoldier);
            }
        }
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
            //2. get a random tank in the enemy squad
            Tank* enemyTank = (Tank*) (getRandVehicle("tank", enemySquad));

            //3. do damage to the random enemy
            currTank->doDamage(enemyTank);

            //4. remove the random tank from the enemy squad, if he died
            if(!enemyTank->isAlive()){
                enemySquad->remove(enemyTank);
                deadTanks.push_back(enemyTank);
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
