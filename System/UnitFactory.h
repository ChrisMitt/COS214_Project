//
// Created by Christof on 2022/10/28.
//

#ifndef PROJ_FACTORIES_UNITFACTORY_H
#define PROJ_FACTORIES_UNITFACTORY_H

#include <string>
#include "Person.h"
#include "Vehicle.h"


using namespace std;
/**
 * @brief a UnitFactory class. an abstractfactory class for the abstarct factory design pattern
 * 
 */
class CountryObserver;
class UnitFactory {
public:
/**
 * @brief Construct a new Unit Factory object
 * 
 */
    UnitFactory();
    /**
     * @brief Destroy the Unit Factory object
     * 
     */
    virtual ~UnitFactory();
    /**
     * @brief Create a Person object
     * a pure virtual member
     * @return Person* 
     */
    virtual Person* createPerson(CountryObserver* co, string type) = 0;
    /**
     * @brief Create a Vehicle object
     * a pure virtual member
     * @return Vehicle* 
     */
    virtual Vehicle* createVehicle(CountryObserver* co, string type) = 0;

protected:
/**
 * @brief Get the Name object
 * 
 * @return string 
 */
    string getName();
};


#endif //PROJ_FACTORIES_ABSTRACTUNITFACTORY_H
