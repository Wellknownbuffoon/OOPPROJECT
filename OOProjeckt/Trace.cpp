#include <iostream>
#include "Trace.h"

Trace::Trace(const int&netID_, const  int& lay):netID(netID_),layer(lay), selected(false){}
Trace::~Trace() {
    
}
int Trace::getLayer() const {return layer;}
int Trace::getnetID() const {return netID;}
void Trace::setselec(bool s){selected = s;}