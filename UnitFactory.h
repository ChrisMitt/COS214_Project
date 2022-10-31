//
// Created by Christof on 2022/10/28.
//

#ifndef PROJ_FACTORIES_UNITFACTORY_H
#define PROJ_FACTORIES_UNITFACTORY_H

#include <string>
#include "Person.h"
#include "Vehicle.h"

using namespace std;

class UnitFactory {
public:
    UnitFactory();
    virtual ~UnitFactory();
    virtual Person* createPerson(string) = 0;
    virtual Vehicle* createVehicle(string) = 0;

protected:
    string getName();
};


#endif //PROJ_FACTORIES_ABSTRACTUNITFACTORY_H
