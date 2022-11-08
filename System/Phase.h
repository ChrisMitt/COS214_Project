//
// Created by chris on 2022/11/07.
//

#ifndef COS214_PROJECT_PHASE_H
#define COS214_PROJECT_PHASE_H

#include <string>
#include "PhasesofWar.h"
#include "Country.h"

class PhasesofWar;

using namespace std;


/**
*  @brief A Phase class.
*/
class Phase {
public:
    /**
     * @brief A pure virtual member.
    * @param p  a pointer argument
    */
    virtual void changePhase(PhasesofWar*, bool) = 0;
    
    /**
    * @brief A pure virtual member.
    * @return A string 
    */
    virtual string getPhase() = 0;

    /**
    * @brief A destructor.
    * Phase1 destructor.
    */
    virtual ~Phase();
    static string dispute;
    static int result;
    bool success;

};


/**
*  @brief A Phases1 class. ConcreteState Class for the StatePattern .
*/
class Phase1: public Phase{
public:
    
    /**
    * @brief A constructor.
    * Default Phase1 constructor.
    */
    Phase1();
    /**
     * @brief A virtual member.
    * @param p  a pointer argument
    */
    virtual void changePhase(PhasesofWar* p, bool);

    /**
    * @brief A pure virtual member.
    * @return A string 
    */
    virtual string getPhase();
};

/**
*  @brief A Phases2 class. ConcreteState Class for the StatePattern .
*/
class Phase2: public Phase{
public:
    /**
    * @brief A constructor.
    * Default Phase2 constructor.
    */
    Phase2(bool);

    
    /**
     * @brief A virtual member.
    * @param p  a pointer argument
    */
    virtual void changePhase(PhasesofWar* p, bool);
    
    /**
    * @brief A virtual member.
    * @return A string 
    */
    virtual string getPhase();

    /**
    * @brief A normal member that creates Allaince for Phase2
    */
    void createAlliance();
    void editAlliances();
};


/**
*  @brief A Phases3 class. ConcreteState Class for the StatePattern .
*/
class Phase3: public Phase{
public:
    /**
    * @brief A constructor.
    * Default Phase3 constructor.
    */
    Phase3();
    /**
    * @brief A virtual member.
    * @param p  a pointer argument
    */
    virtual void changePhase(PhasesofWar* p, bool);
    
    /**
    * @brief A virtual member.
    * @return A string 
    */
    virtual string getPhase();
    
    /**
    * @brief A normal member that starts the Battle between Alliances
    */
    void startBattle(bool);

    /**
    * @brief A normal member that displays Alliance for Phase3
    */
    void printAlliances();
};

/**
*  @brief A Phases4 class. ConcreteState Class for the StatePattern .
*/
class Phase4: public Phase{
public: 
    /**
    * @brief A constructor.
    * Default Phase4 constructor.
    */
    Phase4();
    /**
    * @brief A virtual member.
    * @param p  a pointer argument
    */
    virtual void changePhase(PhasesofWar* p, bool);

    /**
    * @brief A virtual member.
    * @return A string 
    */
    virtual string getPhase();

    /**
    * @brief A normal member. Shows the Alliances after Phase 3
    */
    void showUN();
    void createResources(Country *co);
};


/**
*  @brief A Phases4 class. ConcreteState Class for the StatePattern .
*/
class Phase5: public Phase{
public:
    /**
    * @brief A constructor.
    * Default Phase4 constructor.
    */
    Phase5();
    /**
    * @brief A virtual member.
    * @param p  a pointer argument
    */
    virtual void changePhase(PhasesofWar* p, bool);

    /**
    * @brief A virtual member.
    * @return A string 
    */
    virtual string getPhase();
};


#endif //COS214_PROJECT_PHASE_H
