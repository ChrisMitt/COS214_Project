<<<<<<< Updated upstream
//
// Created by chris on 2022/11/05.
//

#ifndef COS214_PROJECT_RESOURCEMANAGEMENT_H
#define COS214_PROJECT_RESOURCEMANAGEMENT_H

#include "Person.h"
#include "Vehicle.h"
#include "CountryObserver.h"


class ResourceManagement {
public:
    ResourceManagement();
    void add(ResourceManagement*);
    virtual int createUpgradedUnit(int, CountryObserver*);

private:
    ResourceManagement* next;
};

class UnitProducer : public ResourceManagement{
public:
    UnitProducer(int);
    int createUpgradedUnit(int, CountryObserver*);

private:
    int value;
};


#endif //COS214_PROJECT_RESOURCEMANAGEMENT_H
=======
//
// Created by chris on 2022/11/05.
//

#ifndef COS214_PROJECT_RESOURCEMANAGEMENT_H
#define COS214_PROJECT_RESOURCEMANAGEMENT_H

#include "Person.h"
#include "Vehicle.h"
#include "CountryObserver.h"


class ResourceManagement {
public:
    ResourceManagement();
    void add(ResourceManagement*);
    virtual int createUpgradedUnit(int, CountryObserver*);

private:
    ResourceManagement* next;
};

class UnitProducer : public ResourceManagement{
public:
    UnitProducer(int);
    int createUpgradedUnit(int, CountryObserver*);

private:
    int value;
};


#endif //COS214_PROJECT_RESOURCEMANAGEMENT_H
>>>>>>> Stashed changes
