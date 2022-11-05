#ifndef AGGREGATE_H
#define AGGREGATE_H
#include "TurnControl.h"


/**
 * an Aggregate class for turncontrol, an aggregate class for the iterator pattern
 */
class Aggregate {

private:
/*data*/
public:
/**
 * @brief Construct a new Aggregate object
 * 
 */
	Aggregate();
	/**
	 * @brief Destroy the Aggregate object
	 * 
	 */
	virtual ~Aggregate();

	/**
	 * a pure virtual member
	 * @brief Create a Turn Control object
	 * 
	 * @return TurnControl* 
	 */
	 virtual TurnControl* createTurnControl()=0;
};

#endif
