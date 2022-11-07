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
 *  @brief A WarStrategy class. Abstract class that represents the Startegy Class in the Strategy Pattern.
 */
class WarStrategy
{
    protected:

       /** 
       * @brief A protected variable.
       * A String that holds the name of the Strategy.
       */
        string strategy_name;

        
       /** 
       * @brief A protected variable.
       * A Boolean that stores the status of the Strategy.
       */
        bool status;

    public:

        /**
       *@brief  A constructor.
       * Default War Startegy constructor.
       */
        WarStrategy(bool s);

       /**
       * @brief A destructor.
       * War Strategy destructor.
       */
        ~WarStrategy();

       /**
       * @brief A pure virtual member.
       */
        virtual void RulesofEngagement() = 0; 

        /**
       * @brief A normal member.
       */
        string getName(); 

        /**
       * @brief A normal member.
       */
        bool getStatus();       

         /**
       * @brief A normal member.
       */
        void setStatus(bool s);   

};


#endif