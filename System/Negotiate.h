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
*  @brief A Negotiate class. ConcreteStrategy Class for the StrategyPattern .
*/
class Negotiate : public WarStrategy
{
    private:

    public:

        /**
        * @brief A constructor.
        * Default Negotiate constructor.
        */
        Negotiate(bool s);

        /**
        * @brief A destructor.
        * Negotiate destructor.
        */
        ~Negotiate();

        /**
        * @brief A normal member.
        */
        void RulesofEngagement();
};

#endif