#include "PCB.h"
#include "Resistor.h"
#include "IC.h"
#include "Capacitor.h"
#include "Diode.h"
#include "Lineartrace.h"
#include "Overlap.h"
#include "shortcircuit.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    
    PCB myBoard(200, 150);

   
    myBoard.addComponent(new Resistor(100, 100));
    myBoard.addComponent(new Resistor(35, 35));
    myBoard.addComponent(new Capacitor(50, 50));
    myBoard.addComponent(new Diode(14, 28));
    myBoard.addComponent(new IC(10, 20));
    myBoard.addComponent(new IC(2, 2)); 
    myBoard.addComponent(new IC(20, 20)); 
    

    
    List<sf::Vector2f> wirePoints;
    wirePoints.pushback(sf::Vector2f(0, 0));
    wirePoints.pushback(sf::Vector2f(50, 50));
    myBoard.addTrace(new Lineartrace(1, 1, 0.5, wirePoints));

    
    myBoard.addValidator(new Overlap(myBoard.getComponents(), 1));
    myBoard.addValidator(new shortcircuit(myBoard.getTraces(),myBoard.getComponents()));

    
    myBoard.validateBoard(); 

    return 0; 
}