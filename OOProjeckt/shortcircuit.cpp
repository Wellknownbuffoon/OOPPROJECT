#include <iostream>
#include <cmath>
#include <algorithm>
#include "shortcircuit.h"
#include "Lineartrace.h" 
#include "Hole.h"

float distSq(sf::Vector2f p1, sf::Vector2f p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

float distSqPointToSegment(sf::Vector2f p, sf::Vector2f v, sf::Vector2f w) {
    float l2 = distSq(v, w);
    if (l2 == 0.0f) return distSq(p, v);
    float t = ((p.x - v.x) * (w.x - v.x) + (p.y - v.y) * (w.y - v.y)) / l2;
    t = std::max(0.0f, std::min(1.0f, t));
    sf::Vector2f projection = { v.x + t * (w.x - v.x), v.y + t * (w.y - v.y) };
    return distSq(p, projection);
}

bool checkThickLines(sf::Vector2f p1, sf::Vector2f p2, float w1,
                     sf::Vector2f p3, sf::Vector2f p4, float w2) {
    float threshold = (w1 / 2.0f) + (w2 / 2.0f);
    float thresholdSq = threshold * threshold;
    if (distSqPointToSegment(p1, p3, p4) < thresholdSq) return true;
    if (distSqPointToSegment(p2, p3, p4) < thresholdSq) return true;
    if (distSqPointToSegment(p3, p1, p2) < thresholdSq) return true;
    if (distSqPointToSegment(p4, p1, p2) < thresholdSq) return true;
    return false;
}

shortcircuit::shortcircuit(const List<Trace*>& t, const List<Component*>& c):trace(t),components(c){
  checker=false;
  errormessage="";
}
bool shortcircuit::validate(){
  reset();
  if(checkForshort()){
    checker = true;
    return false;
  }
  return true;
}

bool shortcircuit::checkForshort() {
    for (int i = 0; i < trace.size(); i++) {
        for (int j = i + 1; j < trace.size(); j++) {
            Trace* t1 = trace[i];
            Trace* t2 = trace[j];

            if (t1->getnetID() == t2->getnetID()) continue; 
            if (t1->getLayer() != t2->getLayer()) continue; 

            
            Lineartrace* l1 = dynamic_cast<Lineartrace*>(t1);
            Lineartrace* l2 = dynamic_cast<Lineartrace*>(t2);
            Hole* h1 = dynamic_cast<Hole*>(t1);
            Hole* h2 = dynamic_cast<Hole*>(t2);
            if (l1 && l2) {
                const auto& pts1 = l1->getPoints();
                const auto& pts2 = l2->getPoints();
                float thick = 1.0f; 

                for (int a = 0; a < pts1.size() - 1; ++a) {
                    for (int b = 0; b < pts2.size() - 1; ++b) {
                        if (checkThickLines(pts1[a], pts1[a+1], thick, 
                                            pts2[b], pts2[b+1], thick)) {
                            errormessage = "Short Circuit: Wire crossing Wire";
                            std::cout << "ERROR: " << errormessage << std::endl;
                            return true;
                        }
                    }
                }
            }

            if (l1 && h2) {
                float wireRadius = l1->getThickness() / 2.0f;
                float minDist = wireRadius + (h2->getDiameter() / 2.0f);
                const auto& pts = l1->getPoints();
                for (int a = 0; a < pts.size() - 1; ++a) {
                    if (distSqPointToSegment(h2->getPosition(), pts[a], pts[a+1]) < (minDist * minDist)) {
                        errormessage = "Short Circuit: Wire hitting Hole";
                        std::cout << "ERROR: " << errormessage << std::endl;
                        return true;
                    }
                }
            }

            if (h1 && l2) {
                float minDist = 0.5f + (h1->getDiameter() / 2.0f);
                const auto& pts = l2->getPoints();
                for (int a = 0; a < pts.size() - 1; ++a) {
                    if (distSqPointToSegment(h1->getPosition(), pts[a], pts[a+1]) < (minDist * minDist)) {
                        errormessage = "Short Circuit: Wire hitting Hole";
                        std::cout << "ERROR: " << errormessage << std::endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
    
}


