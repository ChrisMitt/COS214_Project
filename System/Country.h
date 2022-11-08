//
// Created by Rebecca on 2022/10/31.
//

#ifndef COUNTRY_H
#define COUNTRY_H

#include "CountryObserver.h"
#include "Alliance.h"
#include <iostream>
using namespace std;

/**
 * @brief a Country class. a composite class for the composite pattern
 * 
 */
class Country : public CountryObserver {
  public:

    /**
     * @brief a normal member. Udates any changes to other Contries
     * 
    */
    void update();

    /**
     * @brief a normal member. Shows if the coutry s fighting 
     * 
    */
    void fight();
    
    /**
     * @brief a normal member. Adds the country into the Observer
    *  @param c pointer argument that represents the coutry 
    */
    void add(CountryObserver* c);
  };

#endif
