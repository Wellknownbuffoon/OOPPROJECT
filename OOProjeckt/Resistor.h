#ifndef RESISTOR_H
#define RESISTOR_H
#include "Component.h"
#include <memory>


class Resistor : public Component {
public:
    Resistor(int id_,int x, int y);
    void drawonGrid(Grid<string>& comp);
    std::unique_ptr<Component> clone() const;
};
#endif