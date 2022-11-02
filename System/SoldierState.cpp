//
// Created by chris on 2022/11/01.
//

#include "SoldierState.h"

SoldierState::SoldierState() {
    memento = 0;
}

UnitBackup* SoldierState::getMemento() {
    return memento;
}

void SoldierState::setMemento(UnitBackup* m) {
    memento = m;
}
