//
// Created by chris on 2022/11/05.
//

#ifndef COS214_PROJECT_RESOURCEMANAGEMENT_H
#define COS214_PROJECT_RESOURCEMANAGEMENT_H

#include "Person.h"
#include "Vehicle.h"
#include "CountryObserver.h"
#include "Country.h"


class ResourceManagement {
public:
    ResourceManagement();
    void add(ResourceManagement*);
    virtual int createUpgradedUnit(int, Country*);

private:
    ResourceManagement* next;
};

class UnitProducer : public ResourceManagement{
public:
    UnitProducer(int, int);
    int createUpgradedUnit(int, Country*);

private:
    int value;
    int unitType;
};


#endif //COS214_PROJECT_RESOURCEMANAGEMENT_H
