#include <stdlib.h>
#include <time.h>
#include "WarTheatre.h"

using namespace std;

WarTheatre::WarTheatre(/* args */){

}

WarTheatre::WarTheatre(list<Alliance*> as){

}

void WarTheatre::fillLists(){
    //Soldiers
    int maxSoldiersSize=0;
    defenders->getSoldiers().size() >= attackers->getSoldiers().size() ? maxSoldiersSize = defenders->getSoldiers().size() : maxSoldiersSize = attackers->getSoldiers().size();
    for(int i=0; i<maxSoldiersSize; i++){
        
    }
}

WarTheatre::~WarTheatre(){

}

void WarTheatre::battle(list<CountryObserver*> d, list<CountryObserver*> a, string area, string country){
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

    Alliance* dAlliance = d.front()->getSubject();
    defenders = new Squad(d, dAlliance->getName());
    
    cout<<"=============================\n";
    cout<<"DEFENDERS: \n";
    defenders->printSquad();
    cout<<"\n=============================\n";

    Alliance* aAlliance = a.front()->getSubject();
    attackers = new Squad(a, aAlliance->getName());
    
    cout<<"=============================\n";
    cout<<"ATTACKERS: \n";
    attackers->printSquad();
    cout<<"\n=============================\n";

    fight();
}

void WarTheatre::fight(){
    soldiersFight();
    tanksFight();
    //medicsHeal();

    // Losers do resource management
    createResources(/*CountryObserver* dm*/);


}

void WarTheatre::soldiersFight(){
    cout<<"== 1: SOLDIERS FIGHTING =="<<endl;
    bool done=false;
    int i=0;
    srand( time(NULL) );
    while(done==false){
        if(i < defenders->getSoldiers().size()){
            Soldier* defender = defenders->getSoldiers()[i];
            int randAttackerIndex = rand() % attackers->getSoldiers().size();
            Soldier* randomAttacker = attackers->getSoldiers()[randAttackerIndex];
            defender->doDamage( randomAttacker );
            if(randomAttacker->getHealth()==0){
                attackers->remove(randomAttacker);
            }
            if(attackers->getSoldiers().size()==0){
                done=true;
            }
        }
        
        if( i < attackers->getSoldiers().size()){
            Soldier* attacker = attackers->getSoldiers()[i];
            int randDefenderIndex = rand() % defenders->getSoldiers().size();
            Soldier* randomDefender = defenders->getSoldiers()[randDefenderIndex];
            attacker->doDamage( randomDefender );
            if(randomDefender->getHealth()==0){
                defenders->remove(randomDefender);
            }
            if(defenders->getSoldiers().size()==0){
                done=true;
            }
        }

        i++;

        if(i>=attackers->getSoldiers().size() && i>=defenders->getSoldiers().size()){
            done=true;
        }
    }
}

void WarTheatre::tanksFight(){
    /*cout<<"2: TANKS FIGHTING"<<endl;
    bool done=false;
    int i=0;
    while( 
        (defenders->getTanks().size()>0 && ( attackers->getTanks().size()>0 || attackers->getSoldiers().size()>0 )
        ||
        attackers->getTanks().size()>0 && ( defenders->getTanks().size()>0 || defenders->getSoldiers().size()>0 ))
        &&
        i<defenders->getTanks().size() || i<attackers->getTanks().size()
     ){
        if( i < defenders->getTanks().size()){
            Tank* defenderTank = defenders->getTanks()[i];
            tankAttack(defenderTank, attackers);
        }
        if( i < attackers->getTanks().size() ){
            Tank* attackerTank = attackers->getTanks()[i];
            tankAttack(attackerTank, defenders);
        }
        i++;
    }*/

    cout<<"== 2: TANKS FIGHTING: ==\n";
    vector<Tank*> allTanks;
}

void WarTheatre::tankAttack(Tank* damageDealer, Squad* enemySquad){//returns true if last enemy tank destroyed
    vector<Tank*> enemyTanks = enemySquad->getTanks();
    vector<Soldier*> enemySoldiers = enemySquad->getSoldiers();
    srand( time(NULL) );
    int chooseAction = rand()%9+1;//1-9 attack other tank, 10 attack soldiers
    if( enemySoldiers.size()==0 || (chooseAction<=9 && enemyTanks.size()>0) ){
        //attack other tank
        int randIndex = rand()%enemyTanks.size();
        Tank* randTank = enemyTanks[randIndex];
        damageDealer->doDamage(randTank);
        if(randTank->getHealth()==0){
            enemySquad->remove(randTank);
        }
    }else{
        cout<<"Tank aiming for soldiers\n";
        //attack soldiers
        int maxKills=5;
        if(enemySoldiers.size()<maxKills) maxKills = enemySoldiers.size();
        int killingAmount = rand()%maxKills+1;//eg: kill 1-5 enemySoldiers
        string plural="s";
        if(killingAmount==0) plural="";
        cout<<damageDealer->getType()<<" Shoots and kills "<<killingAmount<<" soldier"<<plural<<endl;
        for(int i=0; i<killingAmount; i++){
            int randIndex = rand()%enemySoldiers.size();
            Soldier* randSoldier = enemySoldiers[randIndex];
            damageDealer->doDamage(randSoldier);
        }
    }
}

void WarTheatre::createResources(CountryObserver* co) {

    int val = co->resources;
    ResourceManagement* rs = new UnitProducer(4);
    rs->add(new UnitProducer(3));
    rs->add(new UnitProducer(2));
    rs->add(new UnitProducer(1));


}
