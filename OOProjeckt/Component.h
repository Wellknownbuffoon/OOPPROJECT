#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include "List.h"
#include "Pin.h"

class Component {
protected:
    std::string name;
    double x, y, width, height;
    List<Pin> pins;
    sf::Color color;
    bool selected;

public:

    Component(const std::string& name = "", double x = 0, double y = 0, double width = 1, double height = 1,
              const List<Pin>& pins = {});

    virtual ~Component() {}
    std::string getName() const;
    double getX() const;
    double getY() const;
    double getWidth() const;
    double getHeight() const;
    const List<Pin>& getPins() const;
    sf::Color getColor() const;

    void setPosition(double nx, double ny);
    void setColor(sf::Color col);
    void setSelected(bool s);

    bool overlaps(const Component& other) const;
    bool violatesClearance(const Component& other, int minClearance) const;
    double distanceTo(const Component& other) const;
    sf::Vector2f getPinPosition(size_t pinIndex) const;
    bool contains(double px, double py) const;

    virtual void draw(sf::RenderWindow& window) const = 0;
};
#endif
