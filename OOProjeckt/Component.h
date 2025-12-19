#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <memory>
#include "Grid.h"
using namespace std;
class Component {
protected:
    int id;
    int x, y;
    int width, height;
    string symbol;
    bool selected;

public:

    Component(const int&id_, const int&x_, const int&y_, 
              const int&width_, const int&height_,
              const string& sym_);

    virtual ~Component() {}
    virtual void drawonGrid(Grid<string>& comp);
    string getName() const;
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;


    void setPosition(double nx, double ny);

    bool overlaps(const Component& other) const;
    bool violatesClearance(const Component& other, int minClearance) const;
    double distanceTo(const Component& other) const;
    bool contains(double px, double py) const;

    ;
};
#endif
