//
// Created by chris on 2022/11/01.
//

#ifndef COS214_PROJECT_SOLDIERSTATE_H
#define COS214_PROJECT_SOLDIERSTATE_H

#include "UnitBackup.h"

class SoldierState{
public:
    SoldierState();
    UnitBackup* getMemento();
    void setMemento(UnitBackup*);

private:
    UnitBackup* memento;
};


#endif //COS214_PROJECT_SOLDIERSTATE_H
