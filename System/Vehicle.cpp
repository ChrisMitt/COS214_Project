//
// Created by chris on 2022/10/31.
//

#include "Vehicle.h"
#include <iostream>
#include "Person.h"

Vehicle::Vehicle(string t, string s, int a, int d, int h, CountryObserver* c) : type(t), state(s), armour(a), damage(d), health(h) {
    country=c;
}

void Vehicle::clone() {
    //apply prototype here
}

string Vehicle::getType() {
    return this->type;
}

string Vehicle::getState() {
    return this->state;
}

void Vehicle::setArmour(int a) {
    armour = armour + a;
}

Status* Vehicle::getStatus() {
    return this->status;
}

void Vehicle::restore(UnitBackup* mem) {
    armour = mem->getHealth();
    status = mem->getStatus();
}

UnitBackup* Vehicle::makeBackup(){
    return new UnitBackup(this->getArmour(), this->getStatus());
}

int Vehicle::research() {
    if(upgrade==NULL) return 0;
    return upgrade->research();
}

int Vehicle::getArmour(){
    return armour;
}

int Vehicle::getDamage(){
    /*if(this->research() == 25){
        return (damage + research());
    }
    else {
        return damage;
    }*/
    return damage;
}

int Vehicle::getHealth(){
    /*if(this->research() == 50){
        return (health + research());
    }
    else {
        return health;
    }*/
    return health;
}

bool Vehicle::isAlive(){
    return (health>0);
}

CountryObserver* Vehicle::getCountry(){
    return country;
}

Vehicle::~Vehicle(){
    //delete upgrade;
}

void Vehicle::doDamage(Vehicle* victim){
    cout<<getType()<<" doing "<<damage<<" damage to "<<victim->getType()<<endl;
    victim->takeDamage(damage);
}

void Vehicle::doDamage(Soldier* victim){
    victim->takeDamage(victim->getHealth());
}

void Vehicle::takeDamage(int amount){
    if(amount<=armour){
        cout<<"    "<<getType()<<" blocked all of the damage\n";
    }else{
        int oldHealth = health;

        /*if(research() == 50){
            amount -= research();
        }*/

        health -= amount-armour;
        if(health<0){
            health=0;
        }
        if(health==0){
            cout<<"    "<<getType()<<" has been destroyed\n";
        }else{
            cout<<"    "<<getType()<<" blocked " << armour << " damage, went from " << oldHealth << "HP, to " << health << "HP\n";
        }
    }
    cout<<"---------------------\n";
}

void Vehicle::setHealth(int h){
    health=h;
}


Plane::Plane(string t, string s, int a, int d, int h, CountryObserver* c, int b, int st) : Vehicle(t, s, a, d, h, c), bomb(b), strafe(st){
}

int Plane::bombingRun() {
    return this->bomb;
}

int Plane::dogFight() {
    return  this->strafe;
}

Tank::Tank(string t, string s, int a, int d, int h, CountryObserver* c) : Vehicle(t, s, a, d, h, c){
    
}

int Tank::fire() {
    return this->damage;
}

int Tank::returnFire() {
    return this->damage;
}

Ship::Ship(string t, string s, int a, int d, int h, CountryObserver* c, int sh, int ca) : Vehicle(t, s, a, d, h, c), shell(sh), canon(ca) {
    
}

int Ship::shellFire() {
    return this->shell;
}

int Ship::counter() {
    return this->canon;
}
