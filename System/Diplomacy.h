#ifndef DIPLOMACY_H
#define DIPLOMACY_H

#include "WarStrategy.h"
#include <iostream>

using namespace std;

/**
*  A Diplomacy class. ConcreteStrategy Class for the StrategyPattern .
*/

class Diplomacy : public WarStrategy
{
private:
    /* data */

public:

    /**
    * A constructor.
    * Default Diplomacy constructor.
    */

    Diplomacy();

    /**
    * A destructor.
    * Diplomacy destructor.
    */
    ~Diplomacy();

    /**
    * A normal member.
    * @see Diplomacy()
    * @see ~Diplomacy()
    */
    void RulesofEngagement();

};


#endif