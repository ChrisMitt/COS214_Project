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
    void clone();
    virtual ~Person();

protected:
    virtual void interact() = 0;

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

protected:
    virtual void interact();

private:
    int damage;
};

class Medic : public Person{
public:
    Medic();
    Medic(string, string);
    void heal(Person);

protected:
    virtual void interact();

};

class Mechanic : public Person{
public:
    Mechanic();
    Mechanic(string, string);
    void repair(Vehicle);

protected:
    virtual void interact();

};

#endif //COS214_PROJECT_PERSON_H
