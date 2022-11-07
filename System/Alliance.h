//
// Created by Rebecca on 2022/10/31.
//

#ifndef ALLIANCE_H
#define ALLIANCE_H

#include <list>
#include <iostream>
#include "CountryObserver.h"
#include "State.h"
using namespace std;

/**
 * @brief Alliance class.a component class for the composite pattern and subject class for the observer pattern
 * 
 */
class CountryObserver;

class Alliance {
  public:
  /**
   * @brief Construct a new Alliance object
   * 
   */
    Alliance(string);
    /**
     * @brief Get the Name object
     * 
     * @return string 
     */
    string getName();
    /**
     * @brief get the ID object
     * 
     * @return int 
     */
    int getID();
    /**
     * a normal member
     * @param CountryObserver a pointer agurment
     */
    void addCountry(CountryObserver*);
    /**
     * @brief a normal member
     * @param CountryObserver a pointer argument
     */
    void removeCountry(CountryObserver*);
    /**
     * @brief a normal member
     * @param int an int argument
     */
    void removeCountry(int);
    /**
     * @brief Set the State object
     * @param State a pointer agurment
     */
    void setState(State*);
    /**
     * @brief Get the State object
     * 
     * @return State* 
     */
    State* getState();
    /**
     * @brief a normal member
     * 
     */
    void showAlliance();
    /**
     * @brief Get the Country List object
     * 
     * @return list<CountryObserver*> 
     */
    list<CountryObserver*> getCountryList();
/**
 * @brief a normal member
 * 
 */
    void notify();
  private:
  /**
   * a private variable
   * an int that holds the alliance id
   */
    int id;
    /**
     * a private variable
     * a string that holds name
     * 
     */
    string name;
    /**
     * a private variable
     * a static int that holds the total number of alliances
     * 
     */
    static int total; // Total number of alliances
    /**
     * a private variable
     * a list that holds the countries in an alliance
     * 
     */
    list<CountryObserver*> countryList; // List of countries in the alliance
    /**
     * a private variable
     * a State pointer that holds the phase of the war
     * 
     */
    State* state; // Conflict/Peace/Negotiating
};

#endif