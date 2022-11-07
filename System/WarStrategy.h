//
// Created by Akani Hlungwani
// Edited by Rebecca Oosthuizen

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
    protected:

       /** 
       * A protected variable.
       * A String that holds the name of the Strategy.
       */
        string strategy_name;

        
       /** 
       * A protected variable.
       * A Boolean that stores the status of the Strategy.
       */
        bool status;

    public:

        /**
       * A constructor.
       * Default War Startegy constructor.
       */
        WarStrategy(bool s);

       /**
       * A destructor.
       * War Strategy destructor.
       */
        ~WarStrategy();

       /**
       * A pure virtual member.
       */
        virtual void RulesofEngagement() = 0; 

        /**
       * A normal member.
       */
        string getName(); 

        /**
       * A normal member.
       */
        bool getStatus();       

         /**
       * A normal member.
       */
        void setStatus(bool s);   

};


#endif