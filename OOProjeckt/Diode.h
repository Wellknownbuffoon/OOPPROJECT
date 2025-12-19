#ifndef DIODE_H
#define DIODE_H
#include "Component.h"
class Diode:public Component{
public:
    Diode(int id_,int x, int y);
    void drawonGrid(Grid<string>& comp);
    std::unique_ptr<Component> clone() const;
};
#endif