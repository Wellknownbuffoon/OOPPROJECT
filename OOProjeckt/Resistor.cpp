#include <iostream>
#include "Resistor.h"

Resistor::Resistor(double x, double y) 
    : Component("Resistor", x, y, 5.0, 2.0) {
    pins.pushback(Pin("1", 0.0, 1.0));
    pins.pushback(Pin("2", 5.0, 1.0));
}

void Resistor::draw(sf::RenderWindow& window) const {
    sf::RectangleShape body(sf::Vector2f(width * 10.0f, height * 10.0f));
    body.setPosition(x * 10.0f, y * 10.0f);
    body.setFillColor(sf::Color(245, 222, 179));
    
    if (selected) body.setOutlineColor(sf::Color::Red);
    else body.setOutlineColor(sf::Color::Black);
    
    body.setOutlineThickness(1.0f);
    window.draw(body);
}

std::unique_ptr<Component> Resistor::clone() const {
    return std::make_unique<Resistor>(*this);
}