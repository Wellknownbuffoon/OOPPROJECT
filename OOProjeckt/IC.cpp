#include "IC.h"
#include <string>

using namespace std;

IC::IC(int id_, int x, int y) 
    : Component(id_, x, y, 4, 4, "I") {}

void IC::drawonGrid(Grid<string>& grid) {
    int startX = x - (width / 2);
    int startY = y - (height / 2);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            
            int gridX = startX + j;
            int gridY = startY + i;

            
            if (gridX >= 0 && gridX < grid.getWidth() && 
                gridY >= 0 && gridY < grid.getHeight()) {

                
                if (gridX == x && gridY == y) {
                    grid(gridX, gridY) = to_string(id);
                }
                
                else if (i == 0 && j == (width / 2)) {
                    grid(gridX, gridY) = "o"; 
                }
            
                else {
                    grid(gridX, gridY) = symbol; 
                }
            }
        }
    }
}


std::unique_ptr<Component> IC::clone() const {
    return std::make_unique<IC>(*this);
}