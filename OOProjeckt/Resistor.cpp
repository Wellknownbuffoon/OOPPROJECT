#include <iostream>
#include "Resistor.h"

Resistor::Resistor(int id_,int x, int y) 
    : Component(id_, x, y, 5, 2, "R") {}

void Resistor::drawonGrid(Grid<string>& comp){
    Component::drawonGrid(comp);
}

std::unique_ptr<Component> Resistor::clone() const {
    return std::make_unique<Resistor>(*this);
}