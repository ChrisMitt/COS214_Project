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
    upgrade = nullptr;
}

Vehicle::Vehicle(string t, string s, RnD* up) {
    type = t;
    state = s;
    armour = 200;
    damage = 75;
    upgrade = up;
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

int Vehicle::getAmour(){
    return this->armour;
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
    return new UnitBackup(this->getAmour(), this->getStatus());
}

int Vehicle::research() {
    upgrade->research();
}

Vehicle::~Vehicle(){
    delete upgrade;
    delete this;
}

Plane::Plane() : Vehicle(){
}

Plane::Plane(string t, string s, RnD* up) : Vehicle(t, s, up){
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

Tank::Tank(string t,string s, RnD* up) : Vehicle(t, s, up){
    armour = 150;
    damage = 100;
    upgrade = up;
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

int Ship::shellFire() {
    return this->shell;
}

int Ship::counter() {
    return this->canon;
}
