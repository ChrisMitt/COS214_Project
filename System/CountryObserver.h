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
using namespace std;

//The default/minimum values for any country's army
struct Army
{
    struct{
        int amount = 0;
        int instanceHP = 100;
    } medics;
    struct{
        int amount = 0;
        int instanceHP = 200;
        int instanceDMG = 120;
    } soldiers;
    struct{
        int amount=0;
        int instanceHP = 150;
    } mechanics;
    struct{
        string name="Sherman";
        int amount=2;
        int instanceHP=20;
        int instanceDMG=1000;
        int instanceArmour=400;//take 400 less damage from each shot
    } tanks;
};

class Alliance;

class CountryObserver{
  public:
    CountryObserver();
    ~CountryObserver();
    void setName(string);
    string getName();
    int getID();
    void setState(State*);
    State* getState();
    bool getAllianceState();
    void setAllianceState(bool);
    void setSubject(Alliance*);
    Alliance* getSubject();
    virtual void update() = 0;
    //War Theatre
    virtual void fight()=0;
    virtual void add(CountryObserver* c)=0;
    void setEntities(string countryName);//sets the military forces based on the country
    void fillArmyStruct();
    void createArmy();
    void printArmy();
    void printMedics();
    void printSoldiers();
    void printMechanics();
    void printTanks();
    //1.Ground
    vector<Medic*> medics;
    vector<Soldier*> soldiers;
    vector<Mechanic*> mechanics;
    vector<Tank*> tanks;
    vector<Ship*> ships;
    vector<Plane*> planes;
  protected:
    int id;
    string name;
    static int total; // Total number of countries
    bool allianceState; // True if the country is part of an alliance, false if it is not
    State* state; // Conflict/Peace/Negotiating
    Alliance* subject; // The alliance the country is part of, which it observes

    //Army stats
    Army* army;

};

#endif
