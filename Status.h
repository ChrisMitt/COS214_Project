//
// Created by chris on 2022/11/01.
//

#ifndef COS214_PROJECT_STATUS_H
#define COS214_PROJECT_STATUS_H

#include <iostream>

using namespace std;

class Status {
public:
    Status();
    Status(const Status&);
    void setHealthChanged();
    void showStatus();

private:
    bool healthChanged;

};


#endif //COS214_PROJECT_STATUS_H
