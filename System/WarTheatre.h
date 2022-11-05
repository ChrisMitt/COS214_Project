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

class WarTheatre
{
private:
    list<Alliance*> allAlliances;
    Squad* defenders;
    Squad* attackers;

    //used by fight methods
    list<Soldier*> allSoldiers;//combined attacker and defender soldiers
    list<Tank*> allTanks;//combined attacker and defender tanks

public:
    WarTheatre(/* args */);
    WarTheatre(list<Alliance*> as);
    ~WarTheatre();
    void fillLists();//allSoldiers, allTanks etc..
    void battle( list<CountryObserver*> d, list<CountryObserver*> a, string area, string country );
    void fight();
    void soldiersFight();
    void tanksFight();
    void medicsHeal();
    void mechanicsRepair();
    void tankAttack(Tank* damageDealer, Squad* enemySquad);
    void removeDeadUnits();
};
