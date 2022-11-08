//
// Created by Christof on 2022/10/28.
//

#include "PersonFactory.h"
#include "UnitFactory.h"
#include "Person.h"
#include "CountryObserver.h"
#include <string>
#include <iostream>

using namespace std;

PersonFactory::PersonFactory()
{
    cout<<"The Person Enlisting station is open."<<endl;
}

PersonFactory::~PersonFactory()
{
    cout<<"The Person Enlisting station is now closed."<<endl;
}

Vehicle* PersonFactory::createVehicle(CountryObserver* co, string vehicleType)
{
    return NULL;
}

Person* PersonFactory::createPerson(CountryObserver* co, string personType)
{
    if(personType=="soldier"){
        Soldier* createdSoldier = new Soldier(
                        co->getName()+" soldier-"+to_string(++co->unitID), 
                        "in battle", 
                        co->army->soldiers.instanceHP, 
                        co, 
                        co->army->soldiers.instanceDMG 
                    );
        return createdSoldier;

    }else if(personType=="medic"){
        Medic* createdMedic = new Medic(
                        co->getName()+" medic-"+to_string(++co->unitID), 
                        "in battle", 
                        co->army->medics.instanceHP, 
                        co
                    );
        return createdMedic;

    }else if(personType=="mechanic"){
        Mechanic* createdMechanic = new Mechanic(
                        co->getName()+" mechanic-"+to_string(++co->unitID), 
                        "in battle", 
                        co->army->mechanics.instanceHP, 
                        co
                    );
        return createdMechanic;
    }

    cout<<"Create person error\n";
    return NULL;
}
