//
// Created by chris on 2022/10/31.
//

#include "Person.h"
#include <iostream>

Person::Person() {
    type = "Civilian";
    state = "N/A";
    health = 100;
    status = new Status();
}

Person::Person(string t, string s) {
    type = t;
    state = s;
    health = 100;
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
    delete this;
}

Soldier::Soldier() : Person(){
}

Soldier::Soldier(string t, string s, RnD* up) : Person(t, s){
    damage = 25;
    upgrade = up;
}

int Soldier::attack() {
    return this->damage;
}

int Soldier::defend() {
    return this->damage;
}

int Soldier::research() {
    upgrade->research();
}

void Soldier::interact() {
    std::cout<<"ready for weapons upgrade" <<std::endl;
}

Soldier* Soldier::clone() {
    return new Soldier(*this);
}

Medic::Medic() : Person(){
}

Medic::Medic(string t, string s) : Person(t, s){
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

Mechanic::Mechanic(string t, string s) : Person(t, s){
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