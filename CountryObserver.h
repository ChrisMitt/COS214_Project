#ifndef COUNTRYOBSERVER_H
#define COUNTRYOBSERVER_H
#include "Alliance.h"
#include "State.h"
#include <iostream>
using namespace std;

class Alliance;

class CountryObserver{
  public:
    CountryObserver();
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
  protected:
    int id;
    string name;
    static int total; // Total number of countries
    bool allianceState; // True if the country is part of an alliance, false if it is not
    State* state; // Conflict/Peace/Negotiating
    Alliance* subject; // The alliance the country is part of, which it observes
};

#endif
