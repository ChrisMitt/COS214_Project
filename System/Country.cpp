//
// Created by Rebecca on 2022/10/31.
//

#include "Country.h"
using namespace std;

void Country::update()
{
    state = subject->getState();
}

void Country::fight(){
    cout << name << " is now fighting\n";
}

void Country::add(CountryObserver* c){

}