//
// Created by chris on 2022/11/01.
//

#ifndef COS214_PROJECT_STATUS_H
#define COS214_PROJECT_STATUS_H

#include <iostream>

using namespace std;

/**
 * @brief a Status class
 * 
 */
class Status {
public:
/**
 * @brief Construct a new Status object
 * 
 */
    Status();
    /**
     * @brief Construct a new Status object
     * @param  Status
     * 
     */
    Status(const Status&);
    /**
     * @brief Set the Health Changed object
     * 
     */
    void setHealthChanged();
    /**
     * @brief a normal member
     * 
     */
    void showStatus();

private:
/**
 * @brief a private object
 * a boolean oibject
 */
    bool healthChanged;

};


#endif //COS214_PROJECT_STATUS_H
