//
// Created by chris on 2022/11/01.
//

#ifndef COS214_PROJECT_UNITBACKUP_H
#define COS214_PROJECT_UNITBACKUP_H

#include "Status.h"

/**
 * @brief a UnitBackup class
 * 
 */
class UnitBackup {
public:
/**
 * @brief Construct a new Unit Backup object
 * 
 * @param
 * 
 * @param Status*
 */
    UnitBackup(int, Status*);
    /**
     * @brief Get the Health object
     * 
     * @return int 
     */
    int getHealth();
    /**
     * @brief Get the Status object
     * 
     * @return Status* 
     */
    Status* getStatus();

private:
    int health;
    Status* status;
};


#endif //COS214_PROJECT_UNITBACKUP_H
