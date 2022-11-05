//
// Created by chris on 2022/10/30.
//
//
// Edited by Charl on 2022/11/04
//

#ifndef COS214_PROJECT_VEHICLE_H
#define COS214_PROJECT_VEHICLE_H

#include <string>
#include "UnitBackup.h"
#include "Decorator.h"

class Person;
using namespace std;
class Vehicle {
public:
    Vehicle();
    Vehicle(string, string, RnD*);
    Vehicle(string t, string s, int a=200, int d=75, int h=1000);
    void clone();
    string getType();
    string getState();
    UnitBackup* makeBackup();
    int getAmour();
    void setArmour(int);
    Status* getStatus();
    void restore(UnitBackup*);
    int research();
    virtual ~Vehicle();
    int getHealth();
    int getArmour();
    int getDamage();
    void doDamage(Vehicle* victim);
    void doDamage(Person* victim);
    void takeDamage(int amount);

protected:
    string type;
    string state;
    int armour;
    int damage;
    Status* status;
    RnD* upgrade;
    int health;
};

class Plane : public Vehicle{
public:
    Plane();
    Plane(string, string, RnD*);
    Plane(string t, string s, int a=200, int d=75, int h=1000, int b=150, int st=50);
    int bombingRun(); //attack
    int dogFight(); //defend

private:
    //int armour;
    int bomb;
    int strafe;
    RnD* upgrade;
};

class Tank : public Vehicle{
public:
    Tank();
    Tank(string, string, RnD*);
    Tank(string t, string s, int a=200, int d=75, int h=1000);
    int fire(); //attack
    int returnFire(); //defend

private:
    RnD* upgrade;
    //int armour;
    //int damage;
};

class Ship : public Vehicle{
public:
    Ship();
    Ship(string, string, RnD*);
    Ship(string t, string s, int a=200, int d=200, int h=1000, int sh=250, int ca=150);
    int shellFire(); //attack
    int counter(); //defend

private:
    //int armour;
    int shell;
    int canon;
    RnD* upgrade;
};


#endif //COS214_PROJECT_VEHICLE_H
