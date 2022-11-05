//
// Created by Christof on 2022/10/28.
//

#include "VehicleFactory.h"
#include "UnitFactory.h"
#include "Vehicle.h"
#include <string>
#include <iostream>

using namespace std;

VehicleFactory::VehicleFactory()
{
    cout<<"The Vehicle Factory is open to create vehicles."<<endl;
}

VehicleFactory::~VehicleFactory()
{
    cout<<"The Vehicle Factory is closed down."<<endl;
}

Vehicle* VehicleFactory::createVehicle(string vehicleType, string subType)
{
    if (vehicleType == "tank")
    {
        Tank* createdTank = new Tank(subType, "creating", new Research);
        return createdTank;
    }
    else if (vehicleType == "ship")
    {
        Ship* createdShip = new Ship(subType, "creating", new Research);
        return createdShip;
    }
    else
    {
        Plane* createdPlane = new Plane(subType, "creating", new Research);
        return createdPlane;
    }
    //Soldier* s = new Soldier(0, 0, "", "");
    //return s;
}
