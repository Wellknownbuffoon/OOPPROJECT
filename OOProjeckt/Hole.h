#ifndef HOLE_H
#define HOLE_H
#include "Trace.h"
class Hole:public Trace{
private:
  double diameter;
  int endlayer;
  sf::Vector2f position;
public:
  Hole(int net, int startlay, int endlay, sf::Vector2f pos);
  void draw(sf::RenderWindow&window) const override;
  bool contains(sf::Vector2f point) const override;

  sf::Vector2f getPosition() const;
  double getDiameter() const;
};
#endif