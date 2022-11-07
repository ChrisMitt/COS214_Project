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
   * @brief a normal member.
   * 
   */
    void update();
    void fight();
    void add(CountryObserver* c);
  };

#endif
