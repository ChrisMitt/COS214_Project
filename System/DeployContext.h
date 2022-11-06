#pragma once

#include "DeployType.h"

using namespace std;

class DeployContext
{
private:
    DeployType*d;
public:
    DeployContext(DeployType* d);
    ~DeployContext();
    void go();
};
