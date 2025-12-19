#ifndef IC_H
#define IC_H

#include "Component.h"
#include "List.h"

class IC : public Component {
public:
    IC(double x, double y);
    IC(std::string name, double x, double y, double w, double h, const List<Pin>& p);

    void draw(sf::RenderWindow& window) const ;
    std::unique_ptr<Component> clone() const ;
};
#endif