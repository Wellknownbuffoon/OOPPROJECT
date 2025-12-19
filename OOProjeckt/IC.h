#ifndef IC_H
#define IC_H

#include "Component.h"
#include "List.h"

class IC : public Component {
public:
    IC(int id_,int x, int y);
    void drawonGrid(Grid<string>& comp);
    std::unique_ptr<Component> clone() const;
};
#endif