#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"

class Resistor : public Component {
public:
    Resistor(double x, double y);
    void draw(sf::RenderWindow& window) const;
    std::unique_ptr<Component> clone() const;
};
#endif