#ifndef CONCRETETURNCONTROL_H
#define CONCRETETURNCONTROL_H
#include "TurnControl.h"
/**
 * @brief a Concrete TurnCointrol class. a Concrete iterator class for the iterator pattern
 * 
 */
class ConcreteTurnControl : TurnControl {


public:
/**
 * @brief Construct a new Concrete Turn Control object
 */
ConcreteTurnControl();
/**
 * @brief Destroy the Concrete Turn Control object
 * 
 */
~ConcreteTurnControl();
/**
 * a normal member
 * 
 */
	void Movements();
	/**
 * a normal member
 * 
 */

	void AttackDefend();
	/**
 * a normal member
 * 
 */

	void ResourceManagement();
	/**
 * a normal member
 * 
 */

	void ActivePhase();
	/**
 * a normal member
 * 
 */

	void CompleteTurn();
};

#endif
