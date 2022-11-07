//
// Created by chris on 2022/11/01.
//

#ifndef COS214_PROJECT_SOLDIERSTATE_H
#define COS214_PROJECT_SOLDIERSTATE_H

#include "UnitBackup.h"

/**
 * @brief a SoldierState class
 * 
 */
class SoldierState{
public:
/**
 * @brief Construct a new Soldier State object
 * 
 */
    SoldierState();
    /**
     * @brief Get the Memento object
     * 
     * @return UnitBackup* 
     */
    UnitBackup* getMemento();
    /**
     * @brief Set the Memento object
     * @param UnitBackup
     */
    void setMemento(UnitBackup*);

private:
/**
 * @brief a private object
 * a UnitBackup object
 */
    UnitBackup* memento;
};


#endif //COS214_PROJECT_SOLDIERSTATE_H
