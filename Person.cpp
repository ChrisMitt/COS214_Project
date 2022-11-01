//
// Created by chris on 2022/10/31.
//

#include "Person.h"
#include <iostream>

Person::Person() {
    type = "Civilian";
    state = "N/A";
    health = 100;
}

Person::Person(string t, string s) {
    type = t;
    state = s;
    health = 100;
}

string Person::getType() {
    return this->type;
}

string Person::getStatus() {
    return this->state;
}


Person::~Person() {
    delete this;
}

Soldier::Soldier() : Person(){
}

Soldier::Soldier(string t, string s) : Person(t, s){
    damage = 25;
}

int Soldier::attack() {
    return this->damage;
}

int Soldier::defend() {
    return this->damage;
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
