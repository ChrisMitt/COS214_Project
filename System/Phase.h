//
// Created by chris on 2022/11/07.
//

#ifndef COS214_PROJECT_PHASE_H
#define COS214_PROJECT_PHASE_H

#include <string>
#include "PhasesofWar.h"
class PhasesofWar;

using namespace std;

class Phase {
public:
    virtual void changePhase(PhasesofWar*) = 0;
    virtual string getPhase() = 0;
    virtual ~Phase();
    static string dispute;
    static int result;
};

class Phase1: public Phase{
public:
    Phase1();
    virtual void changePhase(PhasesofWar* p);
    virtual string getPhase();
};

class Phase2: public Phase{
public:
    Phase2();
    virtual void changePhase(PhasesofWar* p);
    virtual string getPhase();
    void createAlliance();
};

class Phase3: public Phase{
public:
    Phase3();
    virtual void changePhase(PhasesofWar* p);
    virtual string getPhase();
    void startBattle(bool);
    void printAlliances();
};

class Phase4: public Phase{
public:
    Phase4();
    virtual void changePhase(PhasesofWar* p);
    virtual string getPhase();
    void showUN();
};

class Phase5: public Phase{
public:
    Phase5();
    virtual void changePhase(PhasesofWar* p);
    virtual string getPhase();
};


#endif //COS214_PROJECT_PHASE_H
