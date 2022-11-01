//
// Created by chris on 2022/10/30.
//

#ifndef COS214_PROJECT_VEHICLE_H
#define COS214_PROJECT_VEHICLE_H

#include <string>

using namespace std;
class Vehicle {
public:
    Vehicle();
    Vehicle(string, string);
    void clone();
    string getType();
    string getState();
    virtual ~Vehicle();

private:
    string state;
    string type;
    int armour;
    int damage;
};

class Plane : public Vehicle{
public:
    Plane();
    Plane(string, string);
    int bombingRun(); //attack
    int dogFight(); //defend

private:
    int armour;
    int bomb;
    int strafe;
};

class Tank : public Vehicle{
public:
    Tank();
    Tank(string, string);
    int fire(); //attack
    int returnFire(); //defend

private:
    int armour;
    int damage;
};

class Ship : public Vehicle{
public:
    Ship();
    Ship(string, string);
    int shellFire(); //attack
    int counter(); //defend

private:
    int armour;
    int shell;
    int canon;
};


#endif //COS214_PROJECT_VEHICLE_H
