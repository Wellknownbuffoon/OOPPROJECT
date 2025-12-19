#include <iostream>
#include "Component.h"
#include <cmath>
#include <algorithm> 

Component::Component(const int&id_, const int&x_, const int&y_, 
              const int&width_, const int&height_,
              const string& sym_):id(id_), x(x_), y(y_),
               width(width_), height(height_), symbol(sym_){}

              

std::string Component::getName() const { return symbol; }
int Component::getX() const { return x; }
int Component::getY() const { return y; }
int Component::getWidth() const { return width; }
int Component::getHeight() const { return height; }


void Component::setPosition(double nx, double ny) { 
    x = nx; y = ny;
}

void Component::drawonGrid(Grid<string>& comp){
   int  X=x-(width/2);
   int  Y=y-(height/2);
   for (int i=0;i<height;i++){
    for(int j=0;j<width;j++){
        int gridX= X + j;
        int gridY= Y + i;
        if (gridX >= 0 && gridX < comp.getWidth() && 
            gridY >= 0 && gridY < comp.getHeight()) {
              if(gridX==x && gridY==y){comp(gridX, gridY)=to_string(id);}
              else{comp(gridX,gridY)=symbol;}
        }

   }
  }
}

bool Component::overlaps(const Component& other) const {
    int left= x-(width/2), left2 = other.x-(other.width/2);
    int right = x+(width/2),right2 = other.x+(other.width/2);
    int up = y-(height/2), up2 = other.x-(other.height/2);
    int down = y+(height/2), down2 = other.x+(other.height/2);

    if (up>down2|| down<up2 ||
        left>right2 || right<left2) {
        return false;
    }
    return true;
}

bool Component::violatesClearance(const Component& other, int minClearance) const{
    int left= x-(width/2)-minClearance, left2 = other.x-(other.width/2);
    int right = x+(width/2)+minClearance ,right2 = other.x+(other.width/2);
    int up = y-(height/2)-minClearance, up2 = other.x-(other.height/2);
    int down = y+(height/2)+minClearance, down2 = other.x+(other.height/2);

    if (up>down2|| down<up2 ||
        left>right2 || right<left2) {
        return false;
    }
    return true;
}

double Component::distanceTo(const Component& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}

bool Component::contains(double px, double py) const {
    
    int left   = x - width / 2;
    int right  = x + width / 2;
    int top    = y - height / 2;
    int bottom = y + height / 2;

    return (px >= left && px <= right && py >= top && py <= bottom);
}