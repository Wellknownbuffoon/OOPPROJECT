#ifndef SHORTCIRCUIT_H
#define SHORTCIRCUIT_H
#include "Validator.h"
#include "Component.h"
#include "Trace.h"
#include "List.h"

class shortcircuit:public Validation{
private:
   const List<Trace*>& trace;
   const List<Component*>& components;
public:
 shortcircuit(const List<Trace*>& t, const List<Component*>& c);
 bool validate() override;
 bool checkForshort();
 bool checkTraceProximity();
  



};

#endif