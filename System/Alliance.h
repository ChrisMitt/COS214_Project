//
// Created by Rebecca on 2022/10/31.
//

#ifndef ALLIANCE_H
#define ALLIANCE_H

#include <list>
#include <iostream>
#include "CountryObserver.h"
#include "State.h"
using namespace std;

class CountryObserver;

class Alliance {
  public:
    Alliance(string);
    string getName();
    int getID();
    void addCountry(CountryObserver*);
    void removeCountry(CountryObserver*);
    void removeCountry(int);
    void setState(State*);
    State* getState();
    void showAlliance();
    list<CountryObserver*> getCountryList();
    void notify();
  private:
    int id;
    string name;
    static int total; // Total number of alliances
    list<CountryObserver*> countryList; // List of countries in the alliance
    State* state; // Conflict/Peace/Negotiating
};

#endif