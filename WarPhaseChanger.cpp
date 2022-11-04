#include "WarPhaseChanger.h"
#include "Phase1.h"

using namespace std;

WarPhaseChanger::WarPhaseChanger()
{
    cout<<"First Phase of the War has started"<<endl;
    War_phase=new Phase1();
}

WarPhaseChanger::~WarPhaseChanger()
{
    cout<< "Destructor called" <<endl;
    delete War_phase;
    War_phase=0;
}

void WarPhaseChanger::setStrategy(WarStrategy* Strategy)
{
    CountryStrat=Strategy;
}
        
void WarPhaseChanger::Engage()
{
    CountryStrat->RulesofEngagement();
}

void WarPhaseChanger::setPhase(PhasesofWar* phase)
{
    cout << "War Phase Changed" << endl;
    delete War_phase;
    War_phase = phase;
}

void WarPhaseChanger::requestPhase()
{
    War_phase->changePhase(this);
}

string WarPhaseChanger::getPhase()
{
    return War_phase->getPhase();
}
