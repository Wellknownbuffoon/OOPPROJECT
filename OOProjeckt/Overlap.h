#ifndef OVERLAP_H
#define OVERLAP_H
#include "Validator.h"
#include "Component.h"
#include "List.h"

class Overlap:public Validation{
private:
  const List<Component*>& components;
  int minClearance;
  bool checkOverlaps();
  bool checkClearances();
public:
 Overlap(const List<Component*>& comps, int clearance=0);
 bool validate() override;



};


#endif