
//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef DIPLOMACY_H
#define DIPLOMACY_H

/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "WarStrategy.h"
#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*  @brief A Diplomacy class. ConcreteStrategy Class for the StrategyPattern .
*/
class Diplomacy : public WarStrategy
{
    private:
   
    public:

        /**
        * @brief A constructor.
        * Default Diplomacy constructor.
        */
        Diplomacy(bool s);

        /**
        * @brief A destructor.
        * Diplomacy destructor.
        */
        ~Diplomacy();

        /**
        * @brief A normal member.
        */
        void RulesofEngagement();

};


#endif