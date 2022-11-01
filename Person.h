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

using namespace std;
class Person {
public:
    Person();
    Person(string, string);
    string getType();
    string getStatus();
    virtual ~Person();

protected:
    virtual void interact() = 0;
    virtual Person* clone() = 0;

private:
    string type;
    string state;
    int health;
};


class Soldier : public Person{
public:
    Soldier();
    Soldier(string, string);
    int attack();
    int defend();
    virtual void interact();
    virtual Soldier* clone();

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
