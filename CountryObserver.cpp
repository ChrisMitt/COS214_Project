//
// Created by Rebecca on 2022/10/31.
//

#include "CountryObserver.h"
using namespace std;


int CountryObserver::total = 0;

CountryObserver::CountryObserver() 
{
    id = total++;
    setState(new peaceState());
    allianceState = 0;
    subject = NULL;
}

void CountryObserver::setName(string s) 
{
    name = s;
}

string CountryObserver::getName() 
{
    return name;
}

void CountryObserver::setSubject(Alliance* s) 
{
    subject = s;
}

Alliance* CountryObserver::getSubject() 
{
    return subject;
}

int CountryObserver::getID() 
{
    return id;
}

void CountryObserver::setState(State* s) 
{
    state = s;
}

State* CountryObserver::getState() 
{
    return state;
}

void CountryObserver::setAllianceState(bool i) 
{
    allianceState = i;
}

bool CountryObserver::getAllianceState() 
{
    return allianceState;
}