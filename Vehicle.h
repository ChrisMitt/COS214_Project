//
// Created by chris on 2022/10/30.
//

#ifndef COS214_PROJECT_VEHICLE_H
#define COS214_PROJECT_VEHICLE_H

#include <string>
#include "UnitBackup.h"
#include "Decorator.h"

using namespace std;
class Vehicle {
public:
    Vehicle();
    Vehicle(string, string, RnD*);
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

private:
    string state;
    string type;
    int armour;
    int damage;
    Status* status;
    RnD* upgrade;
};

class Plane : public Vehicle{
public:
    Plane();
    Plane(string, string, RnD*);
    int bombingRun(); //attack
    int dogFight(); //defend

private:
    int armour;
    int bomb;
    int strafe;
    RnD* upgrade;
};

class Tank : public Vehicle{
public:
    Tank();
    Tank(string, string, RnD*);
    int fire(); //attack
    int returnFire(); //defend

private:
    int armour;
    int damage;
    RnD* upgrade;
};

class Ship : public Vehicle{
public:
    Ship();
    Ship(string, string, RnD*);
    int shellFire(); //attack
    int counter(); //defend

private:
    int armour;
    int shell;
    int canon;
    RnD* upgrade;
};


#endif //COS214_PROJECT_VEHICLE_H
