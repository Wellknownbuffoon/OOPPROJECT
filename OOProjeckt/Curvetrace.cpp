#include <iostream>
#include "Curvetrace.h"
#include "cmath"

constexpr float DEG_TO_RAD = 3.14159265f / 180.0f;
Arc::Arc(int net_, int lay, double thick, sf::Vector2f cent, double rad,
    double startAng, double endAng) : Trace(net_, lay), thickness(thick), center(cent),
                                           radius(rad), startAngle(startAng), endAngle(endAng){
    segments = static_cast<int>(radius / 2.0f);
    if (segments < 10) segments = 10;

}
void Arc::draw(sf::RenderWindow& window) const{
sf::VertexArray arc(sf::LinesStrip, segments + 1);
    float totalSweep = endAngle - startAngle;
    
    for (int i = 0; i <= segments; ++i) {
        float progress = (float)i / segments;
        float currentDeg = startAngle + (totalSweep * progress);
        float currentRad = currentDeg * DEG_TO_RAD;

        float x = center.x + radius * std::cos(currentRad);
        float y = center.y + radius * std::sin(currentRad);

        arc[i].position = sf::Vector2f(x, y);

        sf::Color c = (layer == 1) ? sf::Color::Red : sf::Color::Blue;
        if (selected) c = sf::Color::White;
        arc[i].color = c;
    }

    window.draw(arc);
}
bool Arc::contains(sf::Vector2f point) const{
    float dx = point.x - center.x;
    float dy = point.y - center.y;
    float dist = std::sqrt(dx*dx + dy*dy);

    float halfThick = thickness / 2.0f;
    if (dist < (radius - halfThick) || dist > (radius + halfThick)) return false;
    

    float angleRad = std::atan2(dy, dx);
    float angleDeg = angleRad / DEG_TO_RAD;
    if (angleDeg < 0) angleDeg += 360.0f;
    return (angleDeg >= startAngle && angleDeg <= endAngle);
}