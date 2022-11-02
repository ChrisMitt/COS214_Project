//
// Created by Rebecca on 2022/10/31.
//

#include "Alliance.h"
#include "CountryObserver.h"
#include <algorithm>
using namespace std;


int Alliance::total = 0;

Alliance::Alliance(string s) 
{
    name = s;
    id = total++;
    state = new peaceState();
}

string Alliance::getName() 
{
    return name;
}

int Alliance::getID() 
{
    return id;
}

void Alliance::addCountry(CountryObserver* c) 
{
    if (c->getAllianceState() == 1) // Check if country is already in alliance
    {
        cout << c->getName() << " is already in an alliance.\n\n";
    }
    else
    {
        countryList.push_back(c); // Add country to alliance if it is not 
        c->setAllianceState(1); // Set country's alliance state to part of an alliance
        cout << c->getName() << " has been added to " << name <<".\n\n";
        c->setSubject(this);
    }
}

void Alliance::removeCountry(CountryObserver* c) 
{
    if ((find(countryList.begin(), countryList.end(), c) != countryList.end()) == 1)// Check if country is in this alliance
    {
        c->setAllianceState(0);// Set country's alliance state to not in an alliance
        countryList.remove(c);// Remove country from alliance
        cout << c->getName() << " has been removed from " << name <<".\n\n";
        c->setSubject(NULL);
    }
    
    else
    {
        cout << c->getName() << " is not in this alliance.\n\n";
    }
}

void Alliance::removeCountry(int i) 
{
    list<CountryObserver*>::iterator ite = countryList.begin();
    advance(ite, (i-1));
    (*ite)->setAllianceState(0);// Set country's alliance state to not in an alliance
    (*ite)->setSubject(NULL);
    cout << (*ite)->getName() << " has been removed from " << name <<".\n\n";
    countryList.remove(*ite);// Remove country from alliance
}

void Alliance::setState(State* s) 
{
    state = s;
    notify();
}

State* Alliance::getState() 
{
    return state;
}

void Alliance::showAlliance() 
{
    int num = 1;
    cout << "----- " << name << " -----\n";
    for (auto ite = countryList.begin(); ite != countryList.end(); ++ite)
    {
        cout << "[" << num << "] " << (*ite)->getName() << endl;
        num++;
    }
}

list<CountryObserver*> Alliance::getCountryList() 
{
    return countryList;
}

void Alliance::notify() 
{
    for (auto ite = countryList.begin(); ite != countryList.end(); ++ite)
    {
        (*ite)->update();
    }
}