#ifndef CONCRETETURNCONTROL_H
#define CONCRETETURNCONTROL_H
#include "TurnControl.h"

class ConcreteTurnControl : TurnControl {


public:
	void Movements();

	void AttackDefend();

	void ResourceManagement();

	void ActivePhase();

	void CompleteTurn();
};

#endif
