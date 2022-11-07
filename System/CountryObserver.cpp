//
// Created by Rebecca on 2022/10/31.
// Edited by Charl on 2022/10/31
#include "CountryObserver.h"
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
}

void CountryObserver::createArmy(){
    //medics
    for(int i=0; i < army->medics.amount; i++){
        medics.push_back( new Medic(name+" medic #"+to_string(i+1), "in battle", army->medics.instanceHP) );
        //eg France medic #1, in battle
    }
    //soldiers
    for(int i=0; i < army->soldiers.amount; i++){
        soldiers.push_back( new Soldier(name+" soldier #"+to_string(i+1), "in battle", army->soldiers.instanceHP, army->soldiers.instanceDMG ) );
        //eg France soldier #1, in battle
    }
    //mechanics
    for(int i=0; i < army->mechanics.amount; i++){
        mechanics.push_back( new Mechanic(name+" mechanic #"+to_string(i+1), "in battle", army->mechanics.instanceHP) );
        //eg France mechanic #1, in battle
    }
    //tanks
    for(int i=0; i < army->tanks.amount; i++){
        tanks.push_back( 
            new Tank(
                name+" " + army->tanks.name + " #"+to_string(i+1), 
                "in battle", 
                army->tanks.instanceArmour, 
                army->tanks.instanceDMG, 
                army->tanks.instanceHP
            ) 
        );
        //eg Germany Sherman #1, in battle
    }
}

void CountryObserver::printArmy(){
    cout<< "======= " << name << " army =======\n";
    cout<< "1.GROUND:\n";
    cout<<"  "<<medics.size()<<"X  medics\n";
    cout<<"  "<<soldiers.size()<<"X soldiers\n";
    cout<<"  "<<mechanics.size()<<"X mechanics\n";
    cout<<"  "<<tanks.size()<<"X "<<army->tanks.name<<" tanks\n\n";
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