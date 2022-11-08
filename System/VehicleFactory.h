//
// Created by Christof on 2022/10/28.
//

#ifndef PROJ_FACTORIES_VEHICLEFACTORY_H
#define PROJ_FACTORIES_VEHICLEFACTORY_H

#include <string>
#include "UnitFactory.h"

using namespace std;

/**
 * @brief a noramal member
 * 
 */
class VehicleFactory : public UnitFactory {
public:
/**
 * @brief Construct a new Vehicle Factory object
 * 
 */
    VehicleFactory();
    /**
     * @brief Destroy the Vehicle Factory object
     * 
     */
    ~VehicleFactory();
    /**
    * @brief Create a Person object
    * @param string
    * @param string
    * @return Person*
    */
    Person* createPerson(CountryObserver* co, string type);
    /**
     * @brief Create a Vehicle object
     * @param string
     * @param string
     * @return Vehicle* 
     */
    Vehicle* createVehicle(CountryObserver* co, string type);
};


#endif //PROJ_FACTORIES_CONCRETEVEHICLEFACTORY_H
