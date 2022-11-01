#ifndef STATE_H
#define STATE_H
#include <iostream>
using namespace std;

class State {
  public:
    string getStateString() {return state;};
  protected:
    string state;
};

class peaceState : public State {
  public:
    peaceState() {state = "Peace";};
};

class warState : public State {
 public:
    warState() {state = "War";};
};

class negotiatingState : public State {
  public:
    negotiatingState() {state = "Negotiating";};
};

#endif