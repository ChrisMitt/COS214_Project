//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef WARPHASECHANGER_H
#define WARPHASECHANGER_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PhasesofWar.h"
#include "WarStrategy.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

/*Foward Declaration*/
class PhasesofWar;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief A WarPhaseChanger class. Context Class for both the Strategy and State Pattern .
 */
class WarPhaseChanger
{
    private:
       
       /** 
       * @brief a private variable.
       * A pointer to a PhasesofWar Object/Class.
       */
        PhasesofWar* War_phase;
        
       /** 
       * @brief a private variable.
       * A pointer to a WarStrategy Object/Class.
       */
        WarStrategy* CountryStrat;

    public:

       /**
       *@brief A constructor.
       * Default WarPhaseChanger constructor.
       */
        WarPhaseChanger();

       /**
       * @brief A destructor.
       * WarPhaseChanger destructor.
       */
        ~WarPhaseChanger();

       /**
       * @brief a normal member taking one arguments and sets the WarStrategy pointer.
       * @param Strategy a pointer argument.
       */
        void setStrategy(WarStrategy* Strategy);

       /**
       * @brief a normal member taking one arguments and sets the WarStrategy pointer.
       * @param Strategy a pointer argument.
       */
        void Engage();  

       /**
       * @brief a normal member taking one arguments and sets the PhasesofWar pointer.
       * @param phase a pointer argument.
       */
        void setPhase(PhasesofWar* phase);

       /**
       *  a normal member that changes the PhasesofWar.
       */
        void requestPhase();

       /**
       *  @brief a normal member that return that type of Phase.
       *  @return The String name of the Phase
       */
        string getPhase();

       /**
       *  @brief a normal member that return that type of Srategy.
       *  @return The String name of the Strategy
       */
        string getStrategy();

        /**
       *  @brief a normal member that gets the Status of the Strategy.
       *  @return The Boolean Status of the Strategy
       */
        bool Status();

};

#endif