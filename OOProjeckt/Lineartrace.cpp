#include "Lineartrace.h"

#include <iostream>
#include <cmath>

Lineartrace::Lineartrace(int net_,int lay_, float thick, const List<sf::Vector2f>& pts)
    : Trace(net_,lay_), thickness(thick), points(pts){}
void Lineartrace::draw(sf::RenderWindow&window) const{
    if (points.size() < 2) return;
    sf::VertexArray lines(sf::LinesStrip, points.size());
    for (size_t i = 0; i < points.size(); ++i) {
        lines[i].position = points[i];
        if (selected) lines[i].color = sf::Color::White;
        else lines[i].color = (layer == 1) ? sf::Color::Red : sf::Color::Blue;
    }
    window.draw(lines);
}
double Lineartrace::getThickness() const{
    return thickness;
}
bool Lineartrace::contains(sf::Vector2f point) const{
   for (int i=0;i<points.size();i++){
    sf::Vector2f pt =points[i];
    float dx = point.x - pt.x;
    float dy = point.y - pt.y;
    if (std::sqrt(dx*dx + dy*dy) < thickness) return true;
   }
   
    return false;
}

const List<sf::Vector2f>& Lineartrace::getPoints() const{
    return points;
}
