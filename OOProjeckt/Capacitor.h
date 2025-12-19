#ifndef CAPACITOR_H
#define CAPACITOR_H
#include  "Component.h"

class Capacitor:public Component{
public:
    Capacitor(int id_,int x, int y);
    void drawonGrid(Grid<string>& comp);
    std::unique_ptr<Component> clone() const;
};

#endif