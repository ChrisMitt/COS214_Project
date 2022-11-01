//
// Created by Christof on 2022/10/28.
//

#ifndef PROJ_FACTORIES_VEHICLEFACTORY_H
#define PROJ_FACTORIES_VEHICLEFACTORY_H

#include <string>
#include "UnitFactory.h"

using namespace std;

class VehicleFactory : public UnitFactory {
public:
    VehicleFactory();
    ~VehicleFactory();
    Vehicle* createVehicle(string);
};


#endif //PROJ_FACTORIES_CONCRETEVEHICLEFACTORY_H
