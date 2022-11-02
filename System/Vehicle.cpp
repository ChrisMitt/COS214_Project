//
// Created by chris on 2022/10/31.
//

#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle() {
    type = "War Vehicle";
    state = "Under Construction";
    armour = 50;
    damage = 0;
}

Vehicle::Vehicle(string t, string s) {
    type = t;
    state = s;
    armour = 200;
    damage = 75;
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

Vehicle::~Vehicle(){
    delete this;
}

Plane::Plane() : Vehicle(){
}

Plane::Plane(string t, string s) : Vehicle(t, s){
    armour = 75;
    bomb = 150;
    strafe = 50;
}

int Plane::bombingRun() {
    return this->bomb;
}

int Plane::dogFight() {
    return  this->strafe;
}

Tank::Tank() : Vehicle() {
}

Tank::Tank(string t,string s) : Vehicle(t, s){
    armour = 150;
    damage = 100;
}

int Tank::fire() {
    return this->damage;
}

int Tank::returnFire() {
    return this->damage;
}

Ship::Ship() : Vehicle(){
}

Ship::Ship(string t, string s) : Vehicle(t, s) {
    armour = 300;
    shell = 250;
    canon = 150;
}

int Ship::shellFire() {
    return this->shell;
}

int Ship::counter() {
    return this->canon;
}
