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
    cout<<"The Person Enlisting station is open."<<endl;
}

PersonFactory::~PersonFactory()
{
    cout<<"The Person Enlisting station is close."<<endl;
}

Person* PersonFactory::createPerson(string personType, string subType)
{
    if (personType == "soldier")
    {
        Soldier* createdSoldier = new Soldier(subType, "enlisted", new Research);
        return createdSoldier;
    }
    else if (personType == "medic")
    {
        Medic* createdMedic = new Medic(subType, "enlisted");
        return createdMedic;
    }
    else
    {
        Mechanic* createdMechanic = new Mechanic(subType, "enlisted");
        return createdMechanic;
    }
}
