#ifndef CONCRETEAGGREGATE_H
#define CONCRETEAGGREGATE_H
#include "Aggregate.h"

class ConcreteAggregate : Aggregate {


public:
	TurnControl* createTurnControl();
};

#endif
