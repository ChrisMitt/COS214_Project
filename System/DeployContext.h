#pragma once

#include "DeployType.h"

using namespace std;
/**
 * @brief a deployContext class, 
 * 
 */
class DeployContext
{
private:
/**
 * @brief a DeployType pointer object
 * 
 */
    DeployType*d;
public:
/**
 * @brief Construct a new Deploy Context object
 * 
 * @param d 
 */
    DeployContext(DeployType* d);
    /**
     * @brief Destroy the Deploy Context object
     * 
     */
    ~DeployContext();
    /**
     * @brief a normal member
     * 
     */
    void go();
};
