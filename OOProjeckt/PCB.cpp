#include "PCB.h"
#include <iostream>


PCB::PCB(double width, double height) 
    : boardWidth(width), boardHeight(height) {
}

PCB::~PCB() {
    for (int i = 0; i < components.size(); ++i) {
        delete components[i];
    }
    for (int i = 0; i < traces.size(); ++i) {
        delete traces[i];
    }
    for (int i = 0; i < validators.size(); ++i) {
        delete validators[i];
    }
}

void PCB::addComponent(Component* c) {
    components.pushback(c);
}

void PCB::addTrace(Trace* t) {
    traces.pushback(t);
}

const List<Component*>& PCB::getComponents() const {
    return components;
}
List<Component*>& PCB::getComponentsMutable() {
    return components;
}
const List<Trace*>& PCB::getTraces() const {
    return traces;
}
List<Trace*>& PCB::getTracesMutable() {
    return traces;
}

void PCB::addValidator(Validation* v) {
    validators.pushback(v);
}
bool PCB::validateBoard() {
    bool allPassed = true;
    std::cout << "Starting PCB Validation Check"<<std::endl;
    for (int i = 0; i < validators.size(); ++i) {
        if (!validators[i]->validate()) {
            allPassed = false;
            std::cout << "[Warning] Violation Found!: " << validators[i]->getErrorMess() << std::endl;
        } else {
            std::cout << "Check " << (i + 1) << " passed." << std::endl;
        }
    }

    if (allPassed) {
        std::cout << "NO ERRORS FOUND" << std::endl;
    } else {
        std::cout << "ERRORS DETECTED" << std::endl;
    }

    return allPassed;
}
void PCB::printBoard() {
    
    int gridW = static_cast<int>(boardWidth);
    int gridH = static_cast<int>(boardHeight);

    Grid<string> displayGrid(gridW, gridH); 

    for(int y = 0; y < gridH; y++) {
        for(int x = 0; x < gridW; x++) {
            displayGrid(x, y) = ".";
        }
    }

    for (int i = 0; i < components.size(); ++i) {
        if (components[i] != nullptr) {
             components[i]->drawonGrid(displayGrid);
        }
    }

    std::cout << "   ";
    for(int i = 0; i < gridW; i++) std::cout << i % 10; // Ruler X
    std::cout << "\n";

    for (int y = 0; y < gridH; ++y) {
        std::cout << y % 10 << " |"; 
        for (int x = 0; x < gridW; ++x) {
            std::cout << displayGrid(x, y);
        }
        std::cout << "|\n";
    }
}
double PCB::getWidth() const { return boardWidth; }
double PCB::getHeight() const { return boardHeight; }