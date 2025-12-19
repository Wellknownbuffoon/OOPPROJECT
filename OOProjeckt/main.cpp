#include <iostream>
#include "PCB.h"
#include "Resistor.h"
#include "IC.h"
#include "Capacitor.h"
#include "Diode.h"
#include "Lineartrace.h"
#include "Overlap.h"
#include "shortcircuit.h"
// REMOVED: #include <SFML/Graphics.hpp>

// Simple structure to replace sf::Vector2f for the grid
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    // Default constructor needed for Lists sometimes
    Point() : x(0), y(0) {} 
};

int main() {
    
    PCB myBoard(40, 20); 

    std::cout << "--- Initializing Components ---" << std::endl;
    myBoard.addComponent(new Resistor(1, 10, 5));  
    myBoard.addComponent(new Resistor(2, 35, 5));  
    myBoard.addComponent(new Capacitor(3, 20, 10)); 
    myBoard.addComponent(new Diode(4, 14, 15));     
    myBoard.addComponent(new IC(5, 30, 15));        
    

    
    myBoard.addValidator(new Overlap(myBoard.getComponents(), 1));
    myBoard.addValidator(new shortcircuit(myBoard.getTraces(), myBoard.getComponents()));

    
    std::cout << "--- Validating Board ---" << std::endl;
    myBoard.validateBoard(); 


    std::cout << "\n--- PCB Grid View ---" << std::endl;
    myBoard.printBoard(); 

    return 0; 
}