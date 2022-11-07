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
    upgrade = nullptr;
}

Vehicle::Vehicle(string t, string s, RnD* up) {
    type = t;
    state = s;
    armour = 200;
    damage = 75;
    upgrade = up;
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
    return upgrade->research();
}

int Vehicle::getArmour(){
    return armour;
}

int Vehicle::getDamage(){
    if(this->research() == 25){
        return (damage + research());
    }
    else {
        return damage;
    }
}

int Vehicle::getHealth(){
    if(this->research() == 50){
        return (health + research());
    }
    else {
        return health;
    }
}

Vehicle::~Vehicle(){
    delete upgrade;
    delete this;
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
        cout<<getType()<<" blocked all of the damage\n";
    }else{
        int oldHealth = health;

        if(research() == 50){
            amount -= research();
        }

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

Plane::Plane(string t, string s, RnD* up) : Vehicle(t, s, up){
    armour = 75;
    bomb = 150;
    strafe = 50;
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

Tank::Tank(string t,string s, RnD* up) : Vehicle(t, s, up){
    armour = 150;
    damage = 100;
    upgrade = up;
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

Ship::Ship(string t, string s, RnD* up) : Vehicle(t, s, up) {
    armour = 300;
    shell = 250;
    canon = 150;
    upgrade = up;
}

Ship::Ship(string t, string s, int a, int d, int h, int sh, int ca) : Vehicle(t, s, a, d, h), shell(sh), canon(ca) {
    
}

int Ship::shellFire() {
    return this->shell;
}

int Ship::counter() {
    return this->canon;
}
