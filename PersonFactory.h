//
// Created by Christof on 2022/10/28.
//

#ifndef PROJ_FACTORIES_PERSONFACTORY_H
#define PROJ_FACTORIES_PERSONFACTORY_H

#include <string>
#include "UnitFactory.h"

using namespace std;

class PersonFactory : public UnitFactory {
public:
    PersonFactory();
    ~PersonFactory();
    Vehicle* createVehicle(string, string);
    Person* createPerson(string, string);
};

#endif //PROJ_FACTORIES_CONCRETEPERSONFACTORY_H
