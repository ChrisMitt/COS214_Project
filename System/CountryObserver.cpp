//
// Created by Rebecca on 2022/10/31.
// Edited by Charl on 2022/10/31
#include<bits/stdc++.h>
#include "CountryObserver.h"
#include <algorithm>

using namespace std;


int CountryObserver::total = 0;

CountryObserver::CountryObserver() 
{
    id = total++;
    setState(new peaceState());
    allianceState = 0;
    subject = NULL;
}

CountryObserver::~CountryObserver(){
    delete army;
}

void CountryObserver::setName(string s) 
{
    name = s;
}

string CountryObserver::getName() 
{
    return name;
}

void CountryObserver::setSubject(Alliance* s) 
{
    subject = s;
}

Alliance* CountryObserver::getSubject() 
{
    return subject;
}

int CountryObserver::getID() 
{
    return id;
}

void CountryObserver::setState(State* s) 
{
    state = s;
}

State* CountryObserver::getState() 
{
    return state;
}

void CountryObserver::setAllianceState(bool i) 
{
    allianceState = i;
}

bool CountryObserver::getAllianceState() 
{
    return allianceState;
}

void CountryObserver::setEntities(string countryName) //sets the army for the country
{
    army = new Army();
    fillArmyStruct();//populate the army struct according to country name
    createArmy();//create the army for the country
}

void CountryObserver::fillArmyStruct(){
    if(name=="Afghanistan"){
        army->medics.amount=10;
        army->soldiers.amount=20;
        army->mechanics.amount=5;
    }
    if(name=="France"){
        
    }
}

void CountryObserver::createArmy(){
    //medics
    for(int i=0; i < army->medics.amount; i++){
        medics.push_back( new Medic(name+" medic #"+to_string(i+1), "in battle", army->medics.instanceHP, this) );
        //eg France medic #1, in battle
    }
    //soldiers
    for(int i=0; i < army->soldiers.amount; i++){
        soldiers.push_back( new Soldier(name+" soldier #"+to_string(i+1), "in battle", army->soldiers.instanceHP, this, army->soldiers.instanceDMG ) );
        //eg France soldier #1, in battle
    }
    //mechanics
    for(int i=0; i < army->mechanics.amount; i++){
        mechanics.push_back( new Mechanic(name+" mechanic #"+to_string(i+1), "in battle", army->mechanics.instanceHP, this) );
        //eg France mechanic #1, in battle
    }
    //tanks
    for(int i=0; i < army->tanks.amount; i++){
        tanks.push_back( 
            new Tank(
                name+" tank #"+to_string(i+1), 
                "in battle", 
                army->tanks.instanceArmour, 
                army->tanks.instanceDMG, 
                army->tanks.instanceHP,
                this
            ) 
        );
        //eg Germany Sherman #1, in battle
    }
    //ships
    for(int i=0; i < army->ships.amount; i++){
        ships.push_back( 
            new Ship(
                name+" ship #"+to_string(i+1) ,
                "in battle", 
                army->ships.instanceArmour, 
                army->ships.instanceDMG, 
                army->ships.instanceHP,
                this
            ) 
        );
        //eg Germany ship #1, in battle
    }

    //Planes
    for(int i=0; i < army->planes.amount; i++){
        planes.push_back( 
            new Plane(
                name+" plane #"+to_string(i+1), 
                "in battle", 
                army->planes.instanceArmour, 
                army->planes.instanceDMG, 
                army->planes.instanceHP,
                this
            ) 
        );
        //eg Germany ship #1, in battle
    }
}

void CountryObserver::printArmy(){
    cout<< "======= " << name << " army =======\n";
    cout<< "1.GROUND:\n";
    cout<<"  "<<medics.size()<<"X medics\n";
    cout<<"  "<<soldiers.size()<<"X soldiers\n";
    cout<<"  "<<mechanics.size()<<"X mechanics\n";
    cout<<"  "<<tanks.size()<<"X "<<army->tanks.name<<" tanks\n";
    cout<<"  "<<ships.size()<<"X ships\n";
    cout<<"  "<<planes.size()<<"X planes\n";

    cout<<endl;
}

void CountryObserver::printMedics(){
    vector<Medic*>::iterator it;
    for(it=medics.begin(); it!=medics.end(); it++){
        cout<<"      ";
        cout<<(*it)->getType()<<", ";
        cout<<(*it)->getState()<<", ";
        cout<<"HP: "<<(*it)->getHealth()<<endl;
    }
}

void CountryObserver::printSoldiers(){
    vector<Soldier*>::iterator it;
    for(it=soldiers.begin(); it!=soldiers.end(); it++){
        cout<<"      ";
        cout<<(*it)->getType()<<", ";
        cout<<(*it)->getState()<<", ";
        cout<<"HP: "<<(*it)->getHealth();
        cout<<", DMG: "<<(*it)->getDamage()<<endl;
    }
}

void CountryObserver::printMechanics(){
    vector<Mechanic*>::iterator it;
    for(it=mechanics.begin(); it!=mechanics.end(); it++){
        cout<<"      ";
        cout<<(*it)->getType()<<", ";
        cout<<(*it)->getState()<<", ";
        cout<<"HP: "<<(*it)->getHealth()<<endl;
    }
}

void CountryObserver::printTanks(){
    vector<Tank*>::iterator it;
    for(it=tanks.begin(); it!=tanks.end(); it++){
        cout<<"      ";
        
        cout<<(*it)->getType()<<", ";
        cout<<(*it)->getState()<<", ";
        cout<<"HP: "<<(*it)->getHealth();
        cout<<"Armour: "<<(*it)->getArmour();
        cout<<"Damage: "<<(*it)->getDamage()<<endl;
    }
    cout<<tanks.size()<<"X ";
}

bool CountryObserver::removeSoldier(Soldier* s){
    auto it = soldiers.begin();
    bool found = false;
    for(it; it!=soldiers.end() && !found ; it++){
        if((*it)==s && !found){
            soldiers.erase(it);
            found=true;
            return true;
        }
    }
    return false;
}

bool CountryObserver::removeTank(Tank* t){
    auto it = tanks.begin();
    bool found = false;
    for(it; it!=tanks.end() && !found ; it++){
        if((*it)==t && !found){
            tanks.erase(it);
            found=true;
            return true;
        }
    }
    return false;
}

bool CountryObserver::removeShip(Ship* s){
    ships.erase( remove(ships.begin(), ships.end(), s), ships.end() );
    return false;
}

bool CountryObserver::removePlane(Plane* p){
    planes.erase( remove(planes.begin(), planes.end(), p), planes.end() );
    return false;
}

