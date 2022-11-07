//
// Created by chris on 2022/11/03.
//

#include <iostream>
#include "Decorator.h"

int Research::research() {
    //cout<< "Extra "<< 1 << " added." <<endl;
    //return 25;
}

Upgrade::Upgrade(RnD* up) {
    newUpgrade = up;
}

int Upgrade::research() {
    if(newUpgrade){
        return newUpgrade->research();
    }
}

Upgrade::~Upgrade(){
    delete newUpgrade;
}

ExtraDamage::ExtraDamage(RnD* damage) : Upgrade(damage) {
    this->upgradeType = "damage";
}

int ExtraDamage::research() {
    Upgrade::research();
    return 25;
}

string ExtraDamage::getType() {
    return this->upgradeType;
}

ExtraHealth::ExtraHealth(RnD* health) : Upgrade(health) {
    this->upgradeType = "health";
}

int ExtraHealth::research() {
    Upgrade::research();
    return 50;
}

string ExtraHealth::getType() {
    return this->upgradeType;
}