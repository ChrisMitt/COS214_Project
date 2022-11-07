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
#include "ResourceManagement.h"
#include "DeployContext.h"
#include "ArmyGeneral.h"
using namespace std;


/**
 * @brief a Wartheatre calss. this where the war takes place
 * 
 */

class WarTheatre
{
private:
    ArmyGeneral* general;
    ConcreteSquadBuilder* squadBuilder;
/**
 * @brief a list of Alliances 
 * 
 */
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

    //Context of Strategy dp
    list<DeployContext*> deployments;
    Alliance* dAlliance;
    Alliance* aAlliance;
public:
/***/
    list<Alliance*> allAlliances;
    vector<Soldier*> allSoldiers;//combined attacker and defender soldiers
    list<Soldier*> deadSoldiers;
    vector<Tank*> allTanks;//combined attacker and defender tanks
    list<Tank*> deadTanks;
    list<Ship*> allShips;
    list<Ship*> deadShips;
    list<Plane*> allPlanes;
    list<Plane*> deadPlanes;
    list<Medic*> allMedics;
    list<Mechanic*> allMechanics;
    /**
     * @brief Get the Defenders object
     * 
     * @return Squad* 
     */
    Squad* getDefenders();
    /**
     * @brief Get the Attackers object
     * 
     * @return Squad* 
     */
    Squad* getAttackers();
    void printResult();


    string country;
    string area;

public:
/**
 * @brief  Construct a new War Theatre object
 * 
 */
    WarTheatre(list<Alliance*>  aa);
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
     * @param damageDealer 
     * @param enemySquad 
     */
    void tankAttack(Tank* damageDealer, Squad* enemySquad);
    /**
     * @brief a normal memeber
     * 
     */
    void removeDeadUnits();
    /**
     * @brief Create a Resources object
     * 
     */
    void createResources(Country*);
    /**
     * @brief Get the Rand Person object
     * 
     * @param type 
     * @param squad 
     * @return Person* 
     */
    Person* getRandPerson(string type, Squad* squad);
    /**
     * @brief Get the Rand Vehicle object
     * 
     * @param type 
     * @param squad 
     * @return Vehicle* 
     */
    Vehicle* getRandVehicle(string type, Squad* squad);
    void deleteUnits();
    void clearLists();
};
