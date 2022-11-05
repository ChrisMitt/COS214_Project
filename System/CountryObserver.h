//
// Created by Rebecca on 2022/10/31.
//

#ifndef COUNTRYOBSERVER_H
#define COUNTRYOBSERVER_H
#include "Alliance.h"
#include "State.h"
#include <iostream>
using namespace std;

class Alliance;
/**
 * @brief a CountryObserver class. an observer class
 *  for the alliance class, an observer for the observer design pattern
 * 
 */
class CountryObserver{
  public:
  /**
   * @brief Construct a new Country Observer object
   * 
   */
    CountryObserver();
    /**
     * @brief Set the Name object
     * @param String a string argument
     */
    void setName(string);
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
    void setState(State*);
    /**
     * @brief Get the State object
     * 
     * @return State* 
     */
    State* getState();
    /**
     * @brief Get the Alliance State object
     * 
     * @return true 
     * @return false 
     */
    bool getAllianceState();
    /**
     * @brief Set the Alliance State object
     * @param bool a bool argument
     */
    void setAllianceState(bool);
    /**
     * @brief Set the Subject object
     * @param Alliance a pointer argument
     */
    void setSubject(Alliance*);
    /**
     * @brief Get the Subject object
     * 
     * @return Alliance* 
     */
    Alliance* getSubject();
    /**
     * @brief a pure virtual member
     * 
     */
    virtual void update() = 0;
  protected:
  /**
   * @brief a private variable
   * an int int that holds the id
   */
    int id;
    /**
     * @brief a private variable
     * a string that holds  the name
     * 
     */
    string name;
    /**
     * a  private variable
     * a static int that holds the total number of contries
     * 
     */
    static int total; // Total number of countries
    /**
     * @brief a private member
     * a boolean that holds True if the country is part of an alliance, false if it is not
     */
    bool allianceState; // True if the country is part of an alliance, false if it is not
 /**
     * a private variable
     * a State pointer that holds the phase of the war
     * 
     */
    State* state; // Conflict/Peace/Negotiating
    /**
     * @brief a private variable
     *an Alliannce pointer that holds The alliance the country is part of, which it observe
     */
    Alliance* subject; // The alliance the country is part of, which it observes
};

#endif
