#include "Diode.h"
#include <iostream>

Diode::Diode(double x, double y) : Component("Diode", x, y, 4.0, 2.0) {
    pins.pushback(Pin("1", 0.0, 1.0));
    pins.pushback(Pin("2", 4.0, 1.0));
}
void Diode::draw(sf::RenderWindow& window) const
{
    const float scale = 10.0f;

    float px = x * scale;
    float py = y * scale;
    float w  = width * scale;
    float h  = height * scale;

    sf::RectangleShape body(sf::Vector2f(w, h));
    body.setPosition(px, py);
    body.setFillColor(sf::Color(60, 60, 60)); 

    body.setOutlineThickness(1.0f);
    body.setOutlineColor(selected ? sf::Color::Red : sf::Color::Black);


    sf::RectangleShape band(sf::Vector2f(w * 0.15f, h));
    band.setPosition(px + w * 0.85f, py); 
    band.setFillColor(sf::Color::White);

    window.draw(body);
    window.draw(band);
}

std::unique_ptr<Component> Diode::clone() const{
  return std::make_unique<Diode>(*this);
}