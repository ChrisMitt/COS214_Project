#ifndef FIGHT_H
#define FIGHT_H

#include "WarStrategy.h"
#include <iostream>

using namespace std;

class Fight : public WarStrategy
{
private:
    /* data */
public:
    Fight();
    ~Fight();
    void RulesofEngagement();
};

#endif