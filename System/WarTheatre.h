//
// Created by Charl 2022/11/02
//

#pragma once

#include <iostream>
#include "CountryObserver.h"
#include "Country.h"
#include "Alliance.h"
#include "State.h"
#include <list>
#include <iterator>
#include "CountryComposite.h"
#include "Squad.h"
using namespace std;


/**
 * @brief a Wartheatre calss. this where the war takes place
 * 
 */

class WarTheatre
{
private:
/**
 * @brief a list of Alliances 
 * 
 */
    list<Alliance*> allAlliances;
    /**
     * @brief A squad pointer object
     * 
     */
    Squad* defenders;
     /**
     * @brief A squad pointer object
     * 
     */
    Squad* attackers;

    //used by fight methods
    vector<Soldier*> allSoldiers;//combined attacker and defender soldiers
    vector<Tank*> allTanks;//combined attacker and defender tanks
    list<Soldier*> deadSoldiers;
    list<Tank*> deadTanks;
    string country;
    string area;

public:
/**
 * @brief  Construct a new War Theatre object
 * 
 */
    WarTheatre(list<CountryObserver*> d, list<CountryObserver*> a, string area, string country, list<Alliance*>  aa);
    /**
     * @brief Construct a new War Theatre object
     * 
     * @param as 
     */
    WarTheatre(list<Alliance*> as);
    /**
     * @brief Destroy the War Theatre object
     * 
     */
    ~WarTheatre();
    /**
     * @brief a normal member
     * 
     */
    void printInit();
    void fillLists();//allSoldiers, allTanks etc..
    /**
     * @brief a normal member
     * 
     * @param d 
     * @param a 
     * @param area 
     * @param country 
     */
    void battle();
    /**
     * @brief a normal member
     * 
     */
    void fight();
    /**
     * @brief a normal member
     * 
     */
    void soldiersFight();
    /**
     * @brief a normal member
     * 
     */
    void tanksFight();
    /**
     * @brief a normal member
     * 
     */
    void medicsHeal();
    /**
     * @brief a normal member
     * 
     */
    void mechanicsRepair();
    /**
     * @brief a normal member
     * 
     * @param damageDealer 
     * @param enemySquad 
     */
    void tankAttack(Tank* damageDealer, Squad* enemySquad);
    /**
     * @brief a normal memeber
     * 
     */
    void removeDeadUnits();
    Person* getRandPerson(string type, Squad* squad);
    Vehicle* getRandVehicle(string type, Squad* squad);
    void deleteUnits();
    void clearLists();
};
