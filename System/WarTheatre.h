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
    list<Soldier*> allSoldiers;//combined attacker and defender soldiers
    list<Tank*> allTanks;//combined attacker and defender tanks

public:
/**
 * @brief  Construct a new War Theatre object
 * 
 */
    WarTheatre(/* args */);
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
    void fillLists();//allSoldiers, allTanks etc..
    /**
     * @brief a normal member
     * 
     * @param d 
     * @param a 
     * @param area 
     * @param country 
     */
    void battle( list<CountryObserver*> d, list<CountryObserver*> a, string area, string country );
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
};
