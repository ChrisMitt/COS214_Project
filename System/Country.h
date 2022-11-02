//
// Created by Rebecca on 2022/10/31.
//

#ifndef COUNTRY_H
#define COUNTRY_H

#include "CountryObserver.h"
#include "Alliance.h"
#include <iostream>
using namespace std;


class Country : public CountryObserver {
  public:
    void update();
    void fight();
    void add(CountryObserver* c);
  };

#endif
