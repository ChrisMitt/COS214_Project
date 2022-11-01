#ifndef NEGOTIATE_H
#define NEGOTIATE_H

#include "WarStrategy.h"
#include <iostream>

using namespace std;

class Negotiate : public WarStrategy
{
private:
    /* data */
public:
    Negotiate();
    ~Negotiate();
    void RulesofEngagement();
};

#endif