#include <iostream>
#include <cmath>
#include <algorithm>
#include "Capacitor.h"

using namespace std;

Capacitor::Capacitor(int id_, int x, int y) 
    :Component(id_, x, y, 5, 5, "C") {}

void Capacitor::drawonGrid(Grid<string>& comp){
    double radius= min(width,height)/2.0;
    double radiusSq = pow(radius , 2);
    int startX = x - (width / 2);
    int startY = y - (height / 2);

for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int gridX = startX + j;
            int gridY = startY + i;
            if (gridX >= 0 && gridX < comp.getWidth() && 
                gridY >= 0 && gridY < comp.getHeight()) {
                double dx = gridX - x;
                double dy = gridY - y;
                double distSq = (dx * dx) + (dy * dy);
                if (distSq <= radiusSq) {
                    if (gridX == x && gridY == y) {
                        comp(gridX, gridY) = to_string(id);
                    } else {
                        comp(gridX, gridY) = symbol;
                    }
                }
            }
        }
    }
}


std::unique_ptr<Component> Capacitor::clone() const {
    return std::make_unique<Capacitor>(*this);
}