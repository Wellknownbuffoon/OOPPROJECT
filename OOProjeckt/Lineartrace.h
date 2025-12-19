#ifndef LINEARTRACE_H
#define LINEARTRACE_H
#include "Trace.h"
#include "List.h"
class Lineartrace:public Trace{
private:
   List<sf::Vector2f> points;
   float thickness;
public:
   Lineartrace(int net_,int lay_, float thick, const List<sf::Vector2f>& pts);
   void draw(sf::RenderWindow& window) const override;
   bool contains(sf::Vector2f point) const override;
   const List<sf::Vector2f>& getPoints() const;
   double getThickness() const;

};
#endif