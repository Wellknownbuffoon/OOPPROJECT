#ifndef CURVETRACE_H
#define CURVETRACE_H
#include "Trace.h"
class Arc:public Trace{
private:
sf::Vector2f center;
double radius;
double startAngle;
double endAngle;
double thickness;
int segments;

public:
  Arc(int net_, int lay, double thick, sf::Vector2f cent, double rad,
    double startAng, double endAng);
  void draw(sf::RenderWindow& window) const override;
  bool contains(sf::Vector2f point) const override;
};
#endif