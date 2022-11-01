#ifndef COUNTRY_H
#define COUNTRY_H

#include "CountryObserver.h"
#include "Alliance.h"
#include <iostream>
using namespace std;


class Country : public CountryObserver {
  public:
    void update();
  };

#endif
