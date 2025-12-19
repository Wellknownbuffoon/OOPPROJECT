#ifndef DIODE_H
#define DIODE_H
#include "Component.h"
class Diode:public Component{
public:
  Diode(double x, double y);
  void draw(sf::RenderWindow& window) const;
  std::unique_ptr<Component> clone() const;
};
#endif