#ifndef DIPLOMACY_H
#define DIPLOMACY_H

#include "WarStrategy.h"
#include <iostream>

using namespace std;

class Diplomacy : public WarStrategy
{
private:
    /* data */

public:
    Diplomacy();
    ~Diplomacy();
    void RulesofEngagement();

};


#endif