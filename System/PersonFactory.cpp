//
// Created by Christof on 2022/10/28.
//

#include "PersonFactory.h"
#include "UnitFactory.h"
#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

PersonFactory::PersonFactory()
{

}

PersonFactory::~PersonFactory()
{

}

Person* PersonFactory::createPerson(string personType)
{
    if (personType == "soldier")
    {
        Soldier* createdSoldier = new Soldier("soldier", "enlisted");
        return createdSoldier;
    }
    else if (personType == "medic")
    {
        Medic* createdMedic = new Medic("medic", "enlisted");
        return createdMedic;
    }
    else
    {
        Mechanic* createdMechanic = new Mechanic("mechanic", "enlisted");
        return createdMechanic;
    }
}
