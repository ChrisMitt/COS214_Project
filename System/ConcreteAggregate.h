#ifndef CONCRETEAGGREGATE_H
#define CONCRETEAGGREGATE_H
#include "Aggregate.h"
/**
 * @brief Concrete Aggregate class for Aggregate class, a Concrete aggregate class for the iterator pattern
 */
class ConcreteAggregate : Aggregate {
private:
/*data*/

public:
/**
 * @brief Construct a new Concrete Aggregate object
 * 
 */
	ConcreteAggregate();
/**
 * @brief Destroy the Concrete Aggregate object
 * 
 */

	~ConcreteAggregate();
	/**
	 * a normal member
	 * @brief Create a Turn Control object
	 * 
	 * @return TurnControl* 
	 */
	TurnControl* createTurnControl();
};

#endif
