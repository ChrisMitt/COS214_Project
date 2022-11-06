//
// Created by Christof on 2022/10/28.
//

#ifndef PROJ_FACTORIES_PERSONFACTORY_H
#define PROJ_FACTORIES_PERSONFACTORY_H

#include <string>
#include "UnitFactory.h"

using namespace std;
/**
 * @brief a personFactory class. a concrete factory for the unifactory class
 * a concretefactory class for the abstract factory design pattern
 * 
 */
class PersonFactory : public UnitFactory {
public:
/**
 * @brief Construct a new Person Factory object
 * 
 */
    PersonFactory();
    /**
     * @brief Destroy the Person Factory object
     * 
     */
    ~PersonFactory();
    //Vehicle* createVehicle(string, string);
    /**
     * @brief Create a Person object
     * 
     * @return Person* 
     */
    Person* createPerson(string, string);
};

#endif //PROJ_FACTORIES_CONCRETEPERSONFACTORY_H
