//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef NEGOTIATE_H
#define NEGOTIATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "WarStrategy.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*  A Negotiate class. ConcreteStrategy Class for the StrategyPattern .
*/
class Negotiate : public WarStrategy
{
    private:

    public:

        /**
        * A constructor.
        * Default Negotiate constructor.
        */
        Negotiate(bool s);

        /**
        * A destructor.
        * Negotiate destructor.
        */
        ~Negotiate();

        /**
        * A normal member.
        * @see Negotiate()
        * @see ~Negotiate()
        */
        void RulesofEngagement();
};

#endif