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
class Squad
{
private:
    list<CountryObserver*> involvedCountries;
    //1.GROUND
    vector<Medic*> medics;
    vector<Soldier*> soldiers;
    vector<Mechanic*> mechanics;
    vector<Tank*> tanks; 

    //2.AIR
    vector<Plane*> planes;

    //3.NAVY
    vector<Ship*> ships;


    string area;//land, sea, or mountains
    //land wil allow troops and air
    //sea will allow boats and air
    //mountains will only allow air
public:
    Squad(/* args */);
    Squad(list<CountryObserver*> countries, string allianceName);
    ~Squad();

    void addTroops(CountryObserver* co);
    void addMedics(CountryObserver* co);
    void addSoldiers(CountryObserver* co);
    void addMechanics(CountryObserver* co);
    void addTanks(CountryObserver* co);
    void addPlanes(CountryObserver* co);
    void addShips(CountryObserver* co);

    void printSquad();

    vector<Medic*> getMedics();
    vector<Soldier*> getSoldiers();
    vector<Mechanic*> getMechanics();
    vector<Tank*> getTanks();
    vector<Plane*> getPlanes();
    vector<Ship*> getShips();

    void remove(Soldier*);
    void remove(Tank*);
};
