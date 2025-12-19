#include "Diode.h"
#include <iostream>
#include <string>

using namespace std;

Diode::Diode(int id_, int x, int y) 
    : Component(id_, x, y, 5, 2, "D") {}
    
void Diode::drawonGrid(Grid<string>& grid) {
    int startX = x - (width / 2);
    int startY = y - (height / 2);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int gridX = startX + j;
            int gridY = startY + i;
            if (gridX >= 0 && gridX < grid.getWidth() && 
                gridY >= 0 && gridY < grid.getHeight()) {

                if (j == width - 1) {
                    grid(gridX, gridY) = "|"; 
                } 
                else if (gridX == x && gridY == y) {
                    grid(gridX, gridY) = to_string(id);
                } 
                else {
                    grid(gridX, gridY) = "D";
                }
            }
        }
    }
}

std::unique_ptr<Component> Diode::clone() const{
  return std::make_unique<Diode>(*this);
}