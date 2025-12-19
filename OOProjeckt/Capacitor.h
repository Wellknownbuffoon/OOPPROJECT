#ifndef CAPACITOR_H
#define CAPACITOR_H
#include  "Component.h"

class Capacitor:public Component{
public:
  Capacitor(double x, double y);
  void draw(sf::RenderWindow& window) const;
  std::unique_ptr<Component> clone() const;
};

#endif