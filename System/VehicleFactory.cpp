//
// Created by Christof on 2022/10/28.
//

#include "VehicleFactory.h"
#include "UnitFactory.h"
#include "Vehicle.h"
#include "Person.h"
#include <string>
#include <iostream>
#include "CountryObserver.h"

using namespace std;

VehicleFactory::VehicleFactory()
{
    cout<<"The Vehicle Factory is open to create vehicles."<<endl;
}

VehicleFactory::~VehicleFactory()
{
    cout<<"The Vehicle Factory is now closed down."<<endl;
}

Person* VehicleFactory::createPerson(CountryObserver* co, string personType)
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

    return NULL;
}

Vehicle* VehicleFactory::createVehicle(CountryObserver* co, string vehicleType)
{
    if (vehicleType == "tank")
    {
        Tank* createdTank = new Tank(
                co->getName()+" tank-"+to_string(++co->unitID), 
                "in battle", 
                co->army->tanks.instanceArmour, 
                co->army->tanks.instanceDMG, 
                co->army->tanks.instanceHP,
                co
            );
        return createdTank;
    }
    else if (vehicleType == "ship")
    {
        Ship* createdShip = new Ship(
                co->getName()+" ship-"+to_string(++co->unitID), 
                "in battle", 
                co->army->ships.instanceArmour, 
                co->army->ships.instanceDMG, 
                co->army->ships.instanceHP,
                co
            );
        return createdShip;
    }
    else
    {
        Plane* createdPlane = new Plane(
                co->getName()+" plane-"+to_string(++co->unitID), 
                "in battle",
                co->army->planes.instanceArmour, 
                co->army->planes.instanceDMG, 
                co->army->planes.instanceHP,
                co
            );
        return createdPlane;
    }
}
