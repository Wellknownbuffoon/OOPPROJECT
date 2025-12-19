#include <iostream>
#include <string>
#include "Pin.h"

Pin::Pin() : name(""), relX(0), relY(0), isInput(false) {} 
Pin::Pin(std::string n, double rx, double ry, bool in) 
        : name(n), relX(rx), relY(ry), isInput(in) {}
std::string Pin::getName() const { return name; }
double Pin::getRelX() const { return relX; }
double Pin::getRelY() const { return relY; }
bool Pin::getIsInput() const { return isInput; }
