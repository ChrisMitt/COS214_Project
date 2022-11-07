//
// Created by chris on 2022/10/31.
//
//
// Edited by Charl on 2022/11/04
//

#include "Person.h"
#include "Vehicle.h"
#include <iostream>

Person::Person() {
    type = "Civilian";
    state = "N/A";
    health = 100;
    status = new Status();
}

Person::Person(string t, string s, int h) : type(t), state(s), health(h){
    status = new Status();
}

string Person::getType() {
    return this->type;
}

string Person::getState() {
    return this->state;
}

void Person::setHealth(int h) {
    this->health = health + h;
}

int Person::getHealth() {
    return this->health;
}

Status* Person::getStatus() {
    return this->status;
}

void Person::restore(UnitBackup* mem) {
    health = mem->getHealth();
    status = mem->getStatus();
}

Person::~Person() {
    cout<<"Person destructor called"<<endl;
    delete this;
}

Soldier::Soldier() : Person(){
}

Soldier::Soldier(string t, string s, RnD* up) : Person(t, s){
    damage = 25;
    upgrade = up;
}

Soldier::Soldier(string t, string s, int h, int d) : Person(t, s, h), damage(d){
    
}

int Soldier::attack() {
    return this->damage;
}

int Soldier::defend() {
    return this->damage;
}

int Soldier::research() {
    return upgrade->research();
}

void Soldier::interact() {
    std::cout<<"ready for weapons upgrade" <<std::endl;
}

int Soldier::getHealth() {
    if(this->research() == 50){
        return (health + research());
    }
    else{
        return health;
    }
}

Soldier* Soldier::clone() {
    return new Soldier(*this);
}

Medic::Medic() : Person(){
}

Medic::Medic(string t, string s, int h) : Person(t, s, h){
}

void  Medic::heal(Person* p) {
    //apply memento here
    std::cout << p->getType() << " is healed" << std::endl;
}

void Medic::interact() {
    std::cout<<"ready for healing upgrade" <<std::endl;
}

Medic* Medic::clone() {
    return new Medic(*this);
}

UnitBackup* Medic::getMemento() {
    return memento;
}

void Medic::setMemento(UnitBackup* mem) {
    memento = mem;
}

UnitBackup* Soldier::makeBackup(){
    return new UnitBackup(this->getHealth(), this->getStatus());
}

Mechanic::Mechanic() : Person(){
}

Mechanic::Mechanic(string t, string s, int h) : Person(t, s, h){
}

void  Mechanic::repair(Vehicle* v) {
    //apply memento here
    std::cout << v->getType() << " is repaired" << std::endl;
}

void Mechanic::interact() {
    std::cout<<"ready for repairing upgrade" <<std::endl;
}

Mechanic* Mechanic::clone() {
    return new Mechanic(*this);
}

UnitBackup* Mechanic::getMemento() {
    return memento;
}

void Mechanic::setMemento(UnitBackup* mem) {
    memento = mem;
}

int Soldier::getDamage(){
    if(this->research() == 25){
        return (damage + research());
    }
    else{
        return damage;
    }
}

void Soldier::doDamage(Soldier* victim){
    cout<< type << " doing " << getDamage() << " damage to " <<victim->getType() << endl;
    victim->takeDamage(getDamage());
}

void Soldier::takeDamage(int amount){
    int oldHealth=health;

    if(research() == 50){
        amount -= research();
    }

    health-=amount;
    if(health<0){
        health=0;
        cout<< type <<" died a brave death"<<endl;
    }else{
        cout<< type <<" went from "<< oldHealth <<"HP, to "<<health<<"HP\n";
    }
    cout<<"------------------"<<endl;
}