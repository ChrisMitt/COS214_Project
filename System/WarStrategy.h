//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>

////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 *  A WarStrategy class. Abstract class that represents the Startegy Class in the Strategy Pattern.
 */
class WarStrategy
{
    public:

       /** 
       * A private variable.
       * A String that holds the name of the Strategy.
       */
        string startegy_name;

        
       /** 
       * A private variable.
       * A Boolean that stores the status of the Strategy.
       */
        bool status;

    public:

        /**
       * A constructor.
       * Default War Startegy constructor.
       */
        WarStrategy();

       /**
       * A destructor.
       * War Strategy destructor.
       */
        ~WarStrategy();

       /**
       * A pure virtual member.
       */
        virtual void RulesofEngagement() = 0; 

};


#endif