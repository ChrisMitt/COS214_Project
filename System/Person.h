//
// Created by chris on 2022/10/31.
//
/**
 *
 */
#ifndef COS214_PROJECT_PERSON_H
#define COS214_PROJECT_PERSON_H

#include <string>
#include "Vehicle.h"
#include "UnitBackup.h"
#include "SoldierState.h"

using namespace std;

class Person {
public:
    Person();
    Person(string, string);
    string getType();
    string getState();
    int getHealth();
    void setHealth(int);
    Status* getStatus();
    void restore(UnitBackup*);
    virtual ~Person();

protected:
    virtual void interact() = 0;
    virtual Person* clone() = 0;

private:
    string type;
    string state;
    int health;
    Status* status;
};


class Soldier : public Person{
public:
    Soldier();
    Soldier(string, string);
    int attack();
    int defend();
    virtual void interact();
    virtual Soldier* clone();
    UnitBackup* makeBackup();

private:
    int damage;
};

class Medic : public Person{
public:
    Medic();
    Medic(string, string);
    void heal(Person*);
    virtual void interact();
    virtual Medic* clone();
    UnitBackup* getMemento();
    void setMemento(UnitBackup*);

private:
    UnitBackup* memento;
};

class Mechanic : public Person{
public:
    Mechanic();
    Mechanic(string, string);
    void repair(Vehicle*);
    virtual void interact();
    virtual Mechanic* clone();

};

#endif //COS214_PROJECT_PERSON_H
