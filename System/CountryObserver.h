//
// Created by Rebecca on 2022/10/31.
// Edited by Charl on 2022/11/02
#ifndef COUNTRYOBSERVER_H
#define COUNTRYOBSERVER_H
#include "Alliance.h"
#include "State.h"
#include "Person.h"
#include <iostream>
#include <vector>
#include "UnitFactory.h"
#include "PersonFactory.h"
#include "VehicleFactory.h"

using namespace std;


/**
 * @brief CountryObserver class, an obseverclass for countries
 * 
 */
//The default/minimum values for any country's army
/**
 * @brief he default/minimum values for any country's army
 * 
 */
struct Army
{

    struct{
        int amount = 5;
        int instanceHP = 100;
    } medics;
    struct{
        int amount = 10;
        int instanceHP = 200;
        int instanceDMG = 160;
    } soldiers;
    struct{
        int amount=4;
        int instanceHP = 150;
    } mechanics;
    struct{
        string name="Sherman";
        int amount=4;
        int instanceHP=2000;
        int instanceDMG=2000;
        int instanceArmour=400;//take 400 less damage from each shot
    } tanks;
    struct{
        int amount=2;
        int instanceHP=10000;
        int instanceDMG=6000;
        int instanceArmour=800;//take 400 less damage from each shot
    } ships;
    struct{
        string name = "Spitfire";
        int amount=5;
        int instanceHP=1000;
        int instanceDMG=1400;
        int instanceArmour=500;//take 400 less damage from each shot
    } planes;
};

class Alliance;

class CountryObserver{
  public:
  /**
   * @brief Construct a new Country Observer object
   * 
   */
    CountryObserver();
    /**
     * @brief Destroy the Country Observer object
     * 
     */
    ~CountryObserver();
    /**
     * @brief Set the Name object
     * @param string
     */
    void setName(string);
    /**
     * @brief Get the Name object
     * 
     * @return string 
     */
    string getName();
    /**
     * @brief 
     * 
     * @return int 
     */
    int getID();
    /**
     * @brief Set the State object
     * @param State*
     *
    void setState(State*);
    /**
     * @brief Get the State object
     * 
     * @return State* 
     */
    State* getState();
    /**
     * @brief Get the Alliance State object
     * 
     * @return true 
     * @return false 
     */
    bool getAllianceState();
    /**
     * @brief Set the Alliance State object
     * @param bool
     */
    void setAllianceState(bool);
    /**
     * @brief Set the Subject object
     * @param Alliance*
     */
    void setSubject(Alliance*);
    /**
     * @brief Get the Subject object
     * 
     * @return Alliance* 
     */
    Alliance* getSubject();
    /**
     * @brief a pure virtual member
     * 
     */
    virtual void update() = 0;
    //War Theatre
    /**
     * @brief a pure virtual member
     * 
     */
    virtual void fight()=0;
    /**
     * @brief a pure virtual memner
     * 
     * @param c 
     */
    virtual void add(CountryObserver* c)=0;
    /**
     * @brief Set the Entities object
     * 
     * @param countryName 
     */
    void setEntities(string countryName);//sets the military forces based on the country
    /**
     * @brief a normal member
     * 
     */
    void fillArmyStruct();
    /**
     * @brief Create a Army object
     * 
     */
    void createArmy();
    /**
     * @brief a normal member
     * 
     */
    void printArmy();
    /**
     * @brief 
     * 
     */
    void printMedics();
    /**
     * @brief a normal memeber
     * 
     */
    void printSoldiers();
    /**
     * @brief a normal member
     * 
     */
    void printMechanics();
    /**
     * @brief a normal member
     * 
     */
    void printTanks();
    /**
     * @brief remove soldiers, remove tank, remove ship, remove plane member functions
     * 
     * @param s 
     * @return true 
     * @return false 
     */
    bool removeSoldier(Soldier* s);

    /**
     * @brief remove soldiers, remove tank, remove ship, remove plane member functions
     * 
     * @param t pionter represents a Tank 
     * @return true 
     * @return false 
     */
    bool removeTank(Tank* t);

    /**
     * @brief remove soldiers, remove tank, remove ship, remove plane member functions
     * 
     * @param s pionter represents a Ship 
     * @return true 
     * @return false 
     */
    bool removeShip(Ship* s);

    /**
     * @brief remove soldiers, remove tank, remove ship, remove plane member functions
     * 
     * @param t pionter represents a Plane 
     * @return true 
     * @return false 
     */
    bool removePlane(Plane* s);

    //1.Ground
    /**
     * a public variable
     * a vector that holds the medic
     * 
     */
    vector<Medic*> medics;

    /**
     * a public variable
     * a vector that holds the soldiers
     * 
     */
    vector<Soldier*> soldiers;

    /**
     * a public variable
     * a vector that holds the mechanics
     * 
     */
    vector<Mechanic*> mechanics;

    /**
     * a public variable
     * a vector that holds the tanks
     * 
     */
    vector<Tank*> tanks;
    //2.Navy
    /**
     * a public variable
     * a vector that holds the ships
     * 
     */
    vector<Ship*> ships;
    //3.Air
    /**
     * a public variable
     * a vector that holds the planes
     * 
     */
    vector<Plane*> planes;

    /**
     * a public variable
     * The resources which a country can spend on troop creation
     * 
     */
    int resources; // The resources which a country can spend on troop creation
    //Army stats
    Army* army;
    static int unitID;
  protected:

    /**
     * a protected variable
     * Holds the Id of a Country
     * 
     */
    int id;

    /**
     * a protected variable
     * Holds the Name of a Country
     * 
     */
    string name;

    /**
     * a protected variable
     * Static integer. Total number of countries
     * 
     */
    static int total; // Total number of countries

    /**
     * a protected variable
     * True if the country is part of an alliance, false if it is not
     * 
     */
    bool allianceState; // True if the country is part of an alliance, false if it is not

    /**
     * a protected variable
     * Hold the States. Conflict/Peace/Negotiating
     * 
     */
    State* state; // Conflict/Peace/Negotiating

    /**
     * a protected variable
     * The alliance the country is part of, which it observes
     * 
     */
    Alliance* subject; // The alliance the country is part of, which it observes

};

#endif