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

}

VehicleFactory::~VehicleFactory()
{

}

Vehicle* VehicleFactory::createVehicle(string vehicleType)
{
    if (vehicleType == "tank")
    {
        Tank* createdTank = new Tank("tank", "creating");
        return createdTank;
    }
    else if (vehicleType == "ship")
    {
        Ship* createdShip = new Ship("ship", "creating");
        return createdShip;
    }
    else
    {
        Plane* createdPlane = new Plane("plane", "creating");
        return createdPlane;
    }
    //Soldier* s = new Soldier(0, 0, "", "");
    //return s;
}
