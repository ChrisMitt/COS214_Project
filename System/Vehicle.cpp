//
// Created by chris on 2022/10/31.
//

#include "Vehicle.h"
#include <iostream>
#include "Person.h"

Vehicle::Vehicle() {
    type = "War Vehicle";
    state = "Under Construction";
    armour = 50;
    damage = 0;
}

Vehicle::Vehicle(string t, string s, int a, int d, int h) : type(t), state(s), armour(a), damage(d), health(h) {
    
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

int Vehicle::getArmour(){
    return armour;
}

int Vehicle::getDamage(){
    return damage;
}

int Vehicle::getHealth(){
    return health;
}

Vehicle::~Vehicle(){
    delete this;
}

void Vehicle::doDamage(Vehicle* victim){
    cout<<getType()<<" doing "<<damage<<" damage to "<<victim->getType()<<endl;
    victim->takeDamage(damage);
}

void Vehicle::doDamage(Person* victim){
    victim->takeDamage(victim->getHealth());
}

void Vehicle::takeDamage(int amount){
    if(amount<=armour){
        cout<<getType()<<" blocked all of the damage\n";
    }else{
        int oldHealth = health;
        health -= amount-armour;
        if(health<0){
            health=0;
        }
        if(health==0){
            cout<<getType()<<" has been destroyed\n";
        }else{
            cout<<getType()<<" blocked " << armour << " damage, went from " << oldHealth << "HP, to " << health << "HP\n";
        }
    }
    cout<<"-----------------\n";
}

Plane::Plane() : Vehicle(){
}

Plane::Plane(string t, string s, int a, int d, int h, int b, int st) : Vehicle(t, s, a, d, h), bomb(b), strafe(st){
}

int Plane::bombingRun() {
    return this->bomb;
}

int Plane::dogFight() {
    return  this->strafe;
}

Tank::Tank() : Vehicle() {
}

Tank::Tank(string t, string s, int a, int d, int h) : Vehicle(t, s, a, d, h){
    
}

int Tank::fire() {
    return this->damage;
}

int Tank::returnFire() {
    return this->damage;
}

Ship::Ship() : Vehicle(){
}

Ship::Ship(string t, string s, int a, int d, int h, int sh, int ca) : Vehicle(t, s, a, d, h), shell(sh), canon(ca) {
    
}

int Ship::shellFire() {
    return this->shell;
}

int Ship::counter() {
    return this->canon;
}
