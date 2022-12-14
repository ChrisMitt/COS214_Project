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
#include "Person.h"

class Soldier;

class CountryObserver;
class Person;
using namespace std;

/**
 * @brief a Vehicle class. a  an abstract product for the Vehiclefactory class
 * an abtract product class for the abtract factory pattern
 * 
 */
class Vehicle {
public:
/**
 * @brief Construct a new Vehicle object
 * 
 */
    Vehicle(string t, string s, int a=200, int d=75, int h=1000, CountryObserver* c=NULL);
    /**
     * @brief a normal member
     * 
     */
    virtual Vehicle* clone();
    /**
     * @brief Get the Type object
     * 
     * @return string 
     */
    string getType();
    /**
     * @brief Get the State object
     * 
     * @return string 
     */
    string getState();
    /**
     * @brief a noraml member
     * 
     * @return UnitBackup* 
     */
    UnitBackup* makeBackup();
    //int getAmour();
    void setArmour(int);
    /**
     * @brief Get the Status object
     * 
     * @return Status* 
     */
    Status* getStatus();
    /**
     * @brief a normal member
     * @param UnitBackup
     */
    void restore(UnitBackup*);
    /**
     * @brief a noraml member
     * 
     * @return int 
     */
    int research();
    /**
     * @brief Destroy the Vehicle object
     * 
     */
    virtual ~Vehicle();
    /**
     * @brief Get the Health object
     * 
     * @return int 
     */
    int getHealth();
    /**
     * @brief Get the Armour object
     * 
     * @return int 
     */
    int getArmour();
    /**
     * @brief Get the Damage object
     * 
     * @return int 
     */
    int getDamage();
    /**
     * @brief a normal member
     * 
     * @param victim 
     */
    void doDamage(Vehicle* victim);
    /**
     * @brief a noraml member
     * 
     * @param victim 
     */
    void doDamage(Soldier* victim);
    /**
     * @brief a normal member
     * 
     * @param amount 
     */
    void takeDamage(int amount);
    bool isAlive();
    CountryObserver* getCountry();
    void setHealth(int h);
    string type;
    

protected:
/**
 * @brief a string object
 * 
 */
    
/**
 * @brief a string object
 * 
 */
    string state;
/**
 * @brief a integer object
 * 
 */
    int armour;
/**
 * @brief a integer object
 * 
 */
    int damage;
 /**
 * @brief a Status pointer object
 * 
 */
    Status* status;
/**
 * @brief a RnD pointer object
 * 
 */
    RnD* upgrade;
/**
 * @brief a integer object
 * 
 */
    int health;
    CountryObserver* country;
};


/**
 * @brief a Plane Class. a a product of the vehicle clas
 * 
 */
class Plane : public Vehicle{
public:
    Plane* clone();
/**
 * @brief Construct a new Plane object
 * 
 */
    /**
     * @brief Construct a new Plane object
     * 
     * @param t 
     * @param s 
     * @param a 
     * @param d 
     * @param h 
     * @param b 
     * @param st 
     */
    Plane(string t, string s, int a=200, int d=75, int h=1000, CountryObserver* c=NULL, int b=150, int st=50);
    /**
     * @brief a normal member
     * 
     * @return int 
     */
    int bombingRun(); //attack
    /**
     * @brief a noraml member
     * 
     * @return int 
     */
    int dogFight(); //defend

private:
    //int armour;
    int bomb;
    int strafe;
};
/**
 * @brief a Tank class. aproduct of the vehicle class
 * 
 */
class Tank : public Vehicle{
public:
    Tank* clone();
/**
 * @brief Construct a new Tank object
 * 
 */
    Tank(string t, string s, int a=200, int d=75, int h=1000, CountryObserver* c=NULL);
    /**
     * @brief a normal member
     * 
     * @return int 
     */
    int fire(); //attack
    /**
     * @brief a mormal member
     * 
     * @return int 
     */
    int returnFire(); //defend

private:
/**
 * @brief a  RnD pointer object
 * 
 */
    //int armour;
    //int damage;
};

/**
 * @brief a Ship class. aproduct of the vehicle class
 * 
 */
class Ship : public Vehicle{
public:
    Ship* clone();
/**
 * @brief Construct a new Ship object
 * 
 */
    /**
     * @brief Construct a new Ship object
     * 
     * @param t 
     * @param s 
     * @param a 
     * @param d 
     * @param h 
     * @param sh 
     * @param ca 
     */
    Ship(string t, string s, int a=200, int d=200, int h=1000, CountryObserver* c=NULL, int sh=250, int ca=150);
    /**
     * @brief a normal member
     * 
     * @return int 
     */
    int shellFire(); //attack
    /**
     * @brief a normal member
     * 
     * @return int 
     */
    int counter(); //defend

private:
    //int armour;
    /**
     * @brief an integer object
     * 
     */
    int shell;
    /**
     * @brief an integer object
     * 
     */
    int canon;
    /**
     * @brief an  RnD ointer object
     * 
     */
};


#endif //COS214_PROJECT_VEHICLE_H
