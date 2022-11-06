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

int ResourceManagement::createUpgradedUnit(int i, CountryObserver* co) {
    if(i > 0){
        if(next){
            next->createUpgradedUnit(i, co);
        }
        else{
            cout<< "Can't produce an units" <<endl;
        }
    }
    else{
        cout<< "Unit " << i << " was created";
    }
}

UnitProducer::UnitProducer(int v) : ResourceManagement() {
    value = v;
}

int UnitProducer::createUpgradedUnit(int i, CountryObserver* co) {
    if(i >= co->resources){
        cout<< value << " unit producer creates unit " << value <<endl;
        return i;
    }
    else {
        cout << i << " not enough resources to produce. pass on." << endl;
        ResourceManagement::createUpgradedUnit(i, co);
    }
}
