#include "IC.h"

IC::IC(double x, double y) : Component("DIP8", x, y, 4.0, 4.0) {
    // Pins added manually if needed
}

// Updated constructor
IC::IC(std::string name, double x, double y, double w, double h, const List<Pin>& p)
    : Component(name, x, y, w, h) {
    pins = p; // List assignment operator handles copying
}

void IC::draw(sf::RenderWindow& window) const {
    sf::RectangleShape body(sf::Vector2f(width * 10.0f, height * 10.0f));
    body.setPosition(x * 10.0f, y * 10.0f);
    body.setFillColor(sf::Color(50, 50, 50)); 
    
    if (selected) body.setOutlineColor(sf::Color::Red);
    else body.setOutlineColor(sf::Color::White);
    body.setOutlineThickness(1.0f);

    window.draw(body);
}

std::unique_ptr<Component> IC::clone() const {
    return std::make_unique<IC>(*this);
}