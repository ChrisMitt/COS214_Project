#ifndef FIGHT_H
#define FIGHT_H

#include "WarStrategy.h"
#include <iostream>

using namespace std;

/**
*  A Fight class. ConcreteStrategy Class for the StrategyPattern .
*/

class Fight : public WarStrategy
{
private:
    /* data */
public:

    /**
    * A constructor.
    * Default Fight constructor.
    */
    Fight();
    
    /**
    * A destructor.
    * Fight destructor.
    */
    ~Fight();

    /**
    * A normal member.
    * @see Fight()
    * @see ~Fight()
    */
    void RulesofEngagement();
};

#endif