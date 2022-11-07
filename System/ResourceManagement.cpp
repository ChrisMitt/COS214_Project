//
// Created by chris on 2022/11/05.
//

#include "ResourceManagement.h"

ResourceManagement::ResourceManagement() {
    this->next = 0;
}

void ResourceManagement::add(ResourceManagement* rm) {
    if(next){
        next->add(rm);
    }
    else{
        next = rm;
    }
}

int ResourceManagement::createUpgradedUnit(int i, Country* co) {
    if(i >= 0){
        if(next){
            next->createUpgradedUnit(i, co);
        }
        else{
            cout<< "Country has depleted its resources. Unable to produce more units." <<endl;
        }
    }
    else{
        cout<< "Unit type " << i << " was created.";
    }
}

UnitProducer::UnitProducer(int v, int t) : ResourceManagement() {
    value = v;
    unitType = t;
}

int UnitProducer::createUpgradedUnit(int i, Country* co) {
    if(i == this->unitType) {
        if (this->value <= co->resources) {
            if (i == 0) {
                cout << "Country has depleted its resources. Unable to produce more units." << endl;
                return 0;
            } else {
                cout << "Unit type " << i << " was created." << endl;
                int resource = co->resources;
                resource = resource - value;
                co->resources = resource;
                return i;
            }
        } else {
            cout << i << " not enough resources to produce. pass on." << endl;
            ResourceManagement::createUpgradedUnit(i, co);
        }
    }
    else{
        ResourceManagement::createUpgradedUnit(i, co);
    }
}
