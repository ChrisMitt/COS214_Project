#include "Country.h"
using namespace std;

void Country::update()
{
    state = subject->getState();
}