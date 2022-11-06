//
// Created by Charl 2022/11/04
//

#pragma once

#include<vector>
#include<list>
#include "Person.h"
#include "CountryObserver.h"

using namespace std;

//Product for Builder dp
/**
 * @brief a Squad class. a Product for Builder dp
 * 
 */
class Squad
{
private:
/**
 * @brief a list CountryObservers
 * 
 */
    list<CountryObserver*> involvedCountries;

    //1.GROUND
    /**
     * @brief a vector of medic persons
     * 
     */
    vector<Medic*> medics;
    /**
     * @brief a vector of soldier persons
     * 
     */
    vector<Soldier*> soldiers;
    /**
     * @brief a vector of mechanic persons
     * 
     */
    vector<Mechanic*> mechanics;
    /**
     * @brief a vector of tanks vehicles
     * 
     */
    vector<Tank*> tanks; 

    //2.AIR
    /**
     * @brief a vector of plane vehicles
     * 
     */
    vector<Plane*> planes;

    //3.NAVY
    /**
     * @brief a vector of ship vehicles
     * 
     */
    vector<Ship*> ships;

/**
 * @brief a string object
 * land, sea, or mountains
 * land wil allow troops and air
 * sea will allow boats and air
 *mountains will only allow air
 */
    string area;//land, sea, or mountains
    //land wil allow troops and air
    //sea will allow boats and air
    //mountains will only allow air
public:
/**
 * @brief construct a new Squad object
 * 
 */
    Squad(/* args */);
    /**
     * @brief Construct a new Squad object
     * 
     * @param countries 
     * @param allianceName 
     */
    Squad(list<CountryObserver*> countries, string allianceName);
    /**
     * @brief Destroy the Squad object
     * 
     */
    ~Squad();
/**
 * @brief a normal member
 * 
 * @param co 
 */
    void addTroops(CountryObserver* co);
    /**
     * @brief a normal member
     * 
     * @param co 
     */
    void addMedics(CountryObserver* co);
    /**
     * @brief a normal member
     * 
     * @param co 
     */
    void addSoldiers(CountryObserver* co);
    /**
     * @brief a normal member
     * 
     * @param co 
     */
    void addMechanics(CountryObserver* co);
    /**
     * @brief a normal member
     * 
     * @param co 
     */
    void addTanks(CountryObserver* co);
    /**
     * @brief a normal member
     * 
     * @param co 
     */
    void addPlanes(CountryObserver* co);
    /**
     * @brief a mnormal member
     * 
     * @param co 
     */
    void addShips(CountryObserver* co);
/**
 * @brief a normal member
 * 
 */
    void printSquad();
/**
 * @brief Get the Medics object
 * 
 * @return vector<Medic*> 
 */
    vector<Medic*> getMedics();
    /**
     * @brief Get the Soldiers object
     * 
     * @return vector<Soldier*> 
     */
    vector<Soldier*> getSoldiers();
    /**
     * @brief Get the Mechanics object
     * 
     * @return vector<Mechanic*> 
     */
    vector<Mechanic*> getMechanics();
    /**
     * @brief Get the Tanks object
     * 
     * @return vector<Tank*> 
     */
    vector<Tank*> getTanks();
    /**
     * @brief Get the Planes object
     * 
     * @return vector<Plane*> 
     */
    vector<Plane*> getPlanes();
    /**
     * @brief Get the Ships object
     * 
     * @return vector<Ship*> 
     */
    vector<Ship*> getShips();
/**
 * @brief a normal member
 * 
 */
    void remove(Soldier*);
    /**
     * @brief a normal member
     * 
     */
    void remove(Tank*);
    bool contains(Soldier* s);
    bool contains(Tank* t);
};
