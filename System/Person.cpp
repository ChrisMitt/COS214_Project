//
// Created by chris on 2022/10/31.
//
//
// Edited by Charl on 2022/11/04
//

#include "Person.h"
#include "Vehicle.h"
#include "CountryObserver.h"
#include <iostream>

Person::Person() {
    type = "Civilian";
    state = "N/A";
    health = 100;
    status = new Status();
    country=NULL;
}

Person::Person(string t, string s, int h, CountryObserver* c) : type(t), state(s), health(h){
    country=c;
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
    
}

CountryObserver* Person::getCountry(){
    return country;
}

bool Person::isAlive(){
    return (health>0);
}

Soldier::Soldier() : Person(){
}

Soldier::Soldier(string t, string s, RnD* up) : Person(t, s){
    damage = 25;
    upgrade = up;
}

Soldier::Soldier(string t, string s, int h, CountryObserver* c, int d) : Person(t, s, h, c), damage(d){
    
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
    return health;
    /*if(this->research() == 50){
        return (health + research());
    }
    else{
        return health;
    }*/
}

Soldier* Soldier::clone() {
    return new Soldier(*this);
}

Medic::Medic() : Person(){
}

Medic::Medic(string t, string s, int h, CountryObserver* c) : Person(t, s, h, c){
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

Mechanic::Mechanic(string t, string s, int h, CountryObserver* c) : Person(t, s, h, c){
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

void Soldier::doDamage(Person* victim){
    if( damage >= victim->getHealth() ){
        cout<< type << " shoots and kills " << victim->getType()<<endl;
    }else{
        cout<< type << " shoots and damages " << victim->getType()<<endl;
    }
    victim->takeDamage(damage);
}

void Person::takeDamage(int amount){
    int oldHealth=health;

    /*if(research() == 50){
        amount -= research();
    }*/

    health-=amount;
    if(health<0){
        health=0;
    }else{
        
    }
}