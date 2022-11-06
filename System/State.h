//
// Created by Rebecca on 2022/10/31.
//

#ifndef STATE_H
#define STATE_H
#include <iostream>
using namespace std;
/**
 * @brief a State class.
 * 
 */
class State {
  public:
  /**
   * @brief Get the State String object
   * 
   * @return string 
   */
    string getStateString() {return state;};
  protected:
  /**
   * @brief a protected object
   * a string object
   */
    string state;
};

/**
 * @brief a peacestate class
 * 
 */
class peaceState : public State {
  public:
    peaceState() {state = "Peace";};
};

/**
 * @brief a warstate class
 * 
 */
class warState : public State {
 public:
 /**
  * @brief Construct a new war State object
  * 
  */
    warState() {state = "War";};
};

/**
 * @brief a egotiatingState class
 * 
 */
class negotiatingState : public State {
  public:
  /**
   * @brief Construct a new negotiating State object
   * 
   */
    negotiatingState() {state = "Negotiating";};
};

#endif