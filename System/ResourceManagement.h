//
// Created by chris on 2022/11/05.
//

#ifndef COS214_PROJECT_RESOURCEMANAGEMENT_H
#define COS214_PROJECT_RESOURCEMANAGEMENT_H

#include "Person.h"
#include "Vehicle.h"
#include "CountryObserver.h"
#include "Country.h"

/**
 * @brief a Resource  Management class
 * 
 */
class ResourceManagement {
public:
/**
 * @brief Construct a new Resource Management object
 * 
 */
    ResourceManagement();
    /**
     * @brief a normal member
     * 
     * @param ResourceManagement*
     */
    void add(ResourceManagement*);
    /**
     * @brief Create a Upgraded Unit object
     * 
     * @return int 
     */
    virtual int createUpgradedUnit(int, Country*);

private:
/**
 * @brief ResourceManagement pointer object
 * 
 */
    ResourceManagement* next;
};

/**
 * @brief a UnitProducer class
 * 
 */
class UnitProducer : public ResourceManagement{
public:
/**
 * @brief Construct a new Unit Producer object
 * @param int
 * @param int
 */
    UnitProducer(int, int);
    /**
     * @brief Create a Upgraded Unit object
     * @param int
     * @param Country*
     * @return int 
     */
    int createUpgradedUnit(int, Country*);

private:
    int value;
    int unitType;
};


#endif //COS214_PROJECT_RESOURCEMANAGEMENT_H
