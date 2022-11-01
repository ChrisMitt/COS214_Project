//
// Created by chris on 2022/11/01.
//

#ifndef COS214_PROJECT_UNITBACKUP_H
#define COS214_PROJECT_UNITBACKUP_H

#include "Status.h"

class UnitBackup {
public:
    UnitBackup(int, Status*);
    int getHealth();
    Status* getStatus();

private:
    int health;
    Status* status;
};


#endif //COS214_PROJECT_UNITBACKUP_H
