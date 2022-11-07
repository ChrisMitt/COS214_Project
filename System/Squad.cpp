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
    addShips(co);
    addPlanes(co);
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

void Squad::addShips(CountryObserver* co){
    for(auto it=co->ships.begin(); it!=co->ships.end(); it++){
        Ship* currShip = *it;
        ships.push_back( currShip );
    }
}

void Squad::addPlanes(CountryObserver* co){
    for(auto it=co->planes.begin(); it!=co->planes.end(); it++){
        Plane* currPlane = *it;
        planes.push_back( currPlane );
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
    cout<<"Total ships: "<<ships.size()<<endl;
    cout<<"Total planes: "<<planes.size()<<endl;
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

vector<Ship*> Squad::getShips(){
    return ships;
}

vector<Plane*> Squad::getPlanes(){
    return planes;
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

void Squad::remove(Ship* s){
    auto it = ships.begin();
    bool found = false;
    for(it; it!=ships.end() && !found ; it++){
        if((*it)==s && !found){
            ships.erase(it);
            found=true;
        }
    }
}

void Squad::remove(Plane* p){
    auto it = planes.begin();
    bool found = false;
    for(it; it!=planes.end() && !found ; it++){
        if((*it)==p && !found){
            planes.erase(it);
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

bool Squad::contains(Ship* s){
    return ( find(ships.begin(), ships.end(), s) != ships.end() );
}

bool Squad::contains(Plane* p){
    return ( find(planes.begin(), planes.end(), p) != planes.end() );
}

bool Squad::contains(Medic* m){
    return ( find(medics.begin(), medics.end(), m) != medics.end() );
}

bool Squad::contains(Mechanic* m){
    return ( find(mechanics.begin(), mechanics.end(), m) != mechanics.end() );
}