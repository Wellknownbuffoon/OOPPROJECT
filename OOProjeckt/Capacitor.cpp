#include <iostream>
#include "Capacitor.h"

Capacitor::Capacitor(double x, double y):
   Component("Capacitor", x,y,3.0,3.0){
pins.pushback(Pin("1",1,5,3.0));
pins.pushback(Pin("2",4.5,3.0));

}

void Capacitor::draw(sf::RenderWindow& window) const{
    sf::CircleShape circle(width / 2.f);
    circle.setPosition(x * 10.0f, y * 10.0f);
    circle.setOutlineColor(sf::Color(245, 222, 179));
    if (selected) circle.setOutlineColor(sf::Color::Red);
    else circle.setOutlineColor(sf::Color::Black);
    
    circle.setOutlineThickness(1.0f);
    window.draw(circle);
}

std::unique_ptr<Component> Capacitor::clone() const {
    return std::make_unique<Capacitor>(*this);
}