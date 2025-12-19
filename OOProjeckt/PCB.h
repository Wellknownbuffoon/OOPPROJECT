#ifndef PCB_H
#define PCB_H

#include "List.h"       
#include "Component.h"  
#include "Trace.h"   
#include "Validator.h"   

class PCB {
private:
    
    List<Component*> components;
    List<Trace*> traces;
    List<Validation*> validators;

    double boardWidth;
    double boardHeight;

public:
    PCB(double width, double height);
    ~PCB(); 


    void addComponent(Component* c);
    void addTrace(Trace* t);
    void addValidator(Validation* v);
    bool validateBoard();

    
    const List<Component*>& getComponents() const;
    List<Component*>& getComponentsMutable(); 

    const List<Trace*>& getTraces() const;
    List<Trace*>& getTracesMutable();

    double getWidth() const;
    double getHeight() const;
};

#endif