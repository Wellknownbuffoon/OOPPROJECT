#include <iostream>
#include "Component.h"
#include <cmath>
#include <algorithm> 

Component::Component(const std::string& name, double x, double y, double width, double height,
                     const List<Pin>& pins)
    : name(name), x(x), y(y), width(width), height(height), pins(pins){

}

std::string Component::getName() const { return name; }
double Component::getX() const { return x; }
double Component::getY() const { return y; }
double Component::getWidth() const { return width; }
double Component::getHeight() const { return height; }
const List<Pin>& Component::getPins() const { return pins; }
sf::Color Component::getColor() const { return color; }

void Component::setSelected(bool s) { 
    selected = s; 
}
void Component::setPosition(double nx, double ny) { 
    x = nx; y = ny;
}
void Component::setColor(sf::Color col) { color = col; }

bool Component::overlaps(const Component& other) const {
    if (x+width <= other.x || other.x + other.width <= x ||
        y+height <= other.y || other.y + other.height<= y) {
        return false;
    }
    return true;
}
bool Component::violatesClearance(const Component& other, int minClearance) const{
   double dist = distanceTo(other);
   return dist < minClearance;
}

double Component::distanceTo(const Component& other) const {
    double dx = std::max(0.0, std::max(x - other.x , other.x - x ));
    double dy = std::max(0.0, std::max(y - other.y , other.y - y ));
    return std::sqrt(dx * dx + dy * dy);
}

sf::Vector2f Component::getPinPosition(size_t pinIndex) const {
    if (pinIndex >= pins.size()) return {static_cast<float>(x), static_cast<float>(y)};

    const Pin& pin = pins[pinIndex];
    double px = pin.getRelX();
    double py = pin.getRelY();

    return {static_cast<float>(x + px), static_cast<float>(y + py)};
}

bool Component::contains(double px, double py) const {
    return px >= x && px < x + width && py >= y && py < y + height;
}