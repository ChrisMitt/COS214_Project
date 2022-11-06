#include "Squad.h"
#include <algorithm>

Squad::Squad()
{
}

Squad::Squad(list<CountryObserver*> countries, string allianceName)
{
    involvedCountries=countries;
    list<CountryObserver*>::iterator it;
    for(it=countries.begin(); it!=countries.end(); it++){
        CountryObserver* co = *it;
        addTroops(co);
    }
}

Squad::~Squad()
{
    
}

void Squad::addTroops(CountryObserver* co){
    addMedics(co);
    addSoldiers(co);
    addMechanics(co);
    addTanks(co);
}

void Squad::addMedics(CountryObserver* co){
    for(auto it=co->medics.begin(); it!=co->medics.end(); it++){
        Medic* currMedic = *it;
        medics.push_back( currMedic );//this is a shallow copy, since it doesn't make sense to deep copy a person
    }
}

void Squad::addSoldiers(CountryObserver* co){
    for(auto it=co->soldiers.begin(); it!=co->soldiers.end(); it++){
        Soldier* currSoldier = *it;
        soldiers.push_back( currSoldier );//this is a shallow copy, since it doesn't make sense to deep copy a person
    }
}

void Squad::addMechanics(CountryObserver* co){
    for(auto it=co->mechanics.begin(); it!=co->mechanics.end(); it++){
        Mechanic* currMechanic = *it;
        mechanics.push_back( currMechanic );//this is a shallow copy, since it doesn't make sense to deep copy a person
    }
}

void Squad::addTanks(CountryObserver* co){
    for(auto it=co->tanks.begin(); it!=co->tanks.end(); it++){
        Tank* currTank = *it;
        tanks.push_back( currTank );
    }
}

void Squad::printSquad(){
    cout<<"Alliance: "<<involvedCountries.front()->getSubject()<<endl;
    cout<<"Countries involved: ";
    for(auto it=involvedCountries.begin(); it!=involvedCountries.end(); it++){
        cout<<(*it)->getName();;
        if( it!=involvedCountries.end() ) cout<<", ";
    }
    cout<<endl;
    cout<<"Total medics: "<<medics.size()<<endl;
    cout<<"Total soldiers: "<<soldiers.size()<<endl;
    cout<<"Total mechanics: "<<mechanics.size()<<endl;
    cout<<"Total tanks: "<<tanks.size()<<endl;
}

vector<Medic*> Squad::getMedics(){
    return medics;
}

vector<Soldier*> Squad::getSoldiers(){
    return soldiers;
}

vector<Mechanic*> Squad::getMechanics(){
    return mechanics;
}

vector<Tank*> Squad::getTanks(){
    return tanks;
}

void Squad::remove(Soldier* s){
    vector<Soldier*>::iterator it=soldiers.begin();
    bool found=false;
    for(it; it!=soldiers.end() && !found ; it++){
        if((*it)==s && !found){
            soldiers.erase(it);
            found=true;
        }
    }
}

void Squad::remove(Tank* t){
    auto it = tanks.begin();
    bool found = false;
    for(it; it!=tanks.end() && !found ; it++){
        if((*it)==t && !found){
            tanks.erase(it);
            found=true;
        }
    }
}

bool Squad::contains(Soldier* s){
    return ( find(soldiers.begin(), soldiers.end(), s) != soldiers.end() );
}

bool Squad::contains(Tank* t){
    return ( find(tanks.begin(), tanks.end(), t) != tanks.end() );
}