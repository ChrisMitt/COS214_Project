#ifndef TRUNCONTROL_H
#define TRUNCONTROL_H

/**
 * @brief a turncontrol class. an iterator class for the iterator pattern
 * 
 */
class TurnControl {


public:


/**
 * @brief Construct a new Turn Control object
 * 
 */
	 TurnControl();
	 /**
	  * @brief Destroy the Turn Control object
	  * 
	  */
	 virtual ~TurnControl();
/**
 * a pure virtual member
 
 */
	virtual void Movements()=0;
/**
 * a pure virtual member
 */
	virtual void AttackDefend()=0;
/**
 * a pure virtual member
 */
	virtual void ResourceManagement()=0;
/**
 * a pure virtual member
 */
	virtual void ActivePhase()=0;
/**
 * a pure virtual member
 */
	virtual void completeTurn()=0;
};

#endif
