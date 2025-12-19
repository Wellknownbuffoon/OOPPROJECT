#include <iostream>
#include "Hole.h"

Hole::Hole(int net, int startlay, int endlay, sf::Vector2f pos)
   : Trace (net,startlay),endlayer(endlay), position(pos), diameter(1.5f){}
void Hole::draw(sf::RenderWindow&window) const {
    sf::CircleShape ring(diameter);
    ring.setOrigin(diameter, diameter);
    ring.setPosition(position);
    
    if (selected) ring.setFillColor(sf::Color::White);
    else ring.setFillColor(sf::Color(218, 165, 32)); 

    window.draw(ring);


    float holeSize = diameter * 0.6f;
    sf::CircleShape hole(holeSize);
    hole.setOrigin(holeSize, holeSize);
    hole.setPosition(position);
    hole.setFillColor(sf::Color::Black); 
    window.draw(hole);

}
sf::Vector2f Hole::getPosition() const{
  return position;
}
double Hole::getDiameter() const{
  return diameter;
}
bool Hole::contains(sf::Vector2f point) const{
   float dx = point.x - position.x;
   float dy = point.y - position.y;
    
  return (dx*dx + dy*dy) < (diameter * diameter);
}