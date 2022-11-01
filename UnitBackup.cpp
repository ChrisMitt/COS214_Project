//
// Created by chris on 2022/11/01.
//

#include "UnitBackup.h"

UnitBackup::UnitBackup(int h, Status* s) {
    this->health = h;
    this->status = s;
}

int UnitBackup::getHealth() {
    return this->health;
}

Status* UnitBackup::getStatus() {
    return this->status;
}
