#ifndef PIN_H
#define PIN_H
#include <string>

class Pin {
    std::string name;
    double relX, relY;
    bool isInput;
public:
    
    Pin();
    Pin(std::string n, double rx, double ry, bool in=false);
    std::string getName() const;
    double getRelX() const;
    double getRelY() const;
    bool getIsInput() const;
};
#endif