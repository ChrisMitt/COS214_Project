//
// Created by chris on 2022/11/01.
//

#include "Status.h"

Status::Status() {
    healthChanged = false;
}

Status::Status(const Status& status) {
    healthChanged = status.healthChanged;
}

void Status::setHealthChanged() {
    healthChanged = true;
}

void Status::showStatus() {
    if(healthChanged == true){
        cout<< "Health has Changed" <<endl;
    }
    else{
        cout<< "Nothing has changed" <<endl;
    }
}
