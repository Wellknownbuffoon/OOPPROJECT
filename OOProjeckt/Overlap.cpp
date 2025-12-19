#include <iostream>
#include "Overlap.h"

Overlap::Overlap(const List<Component*>& comps, int clearance):components(comps), 
       minClearance(clearance){
        checker = false;
        errormessage ="";
}
bool Overlap::validate(){
  reset();
  if(checkOverlaps()){
    checker = true;
    return false;
  }
  if(minClearance>0 && checkClearances()){
    checker = true;
    return false;
  }
  return true;
}

bool Overlap::checkOverlaps(){
  for(int i=0;i<components.size();i++){
    for(int j=i+1;j<components.size();j++){
        if(components[i]->overlaps(*components[j])){
            errormessage ="Overlap detected between" +
               components[i]->getName() + "and " + 
               components[j]->getName();
            std::cout<<"ERROR:" <<errormessage<<std::endl;
            return true;
        }
    }
  }
  return false;
}

bool Overlap::checkClearances() {
    std::cout << "Components count: " << components.size() << std::endl;

    for (int i = 0; i < components.size(); i++) {
        for (int j = i + 1; j < components.size(); j++) {
            
            double dist = components[i]->distanceTo(*components[j]);
            
            std::cout << "Checking " << components[i]->getName() 
                      << " and " << components[j]->getName() 
                      << ". The Distance: " << dist <<std::endl;
          
            if (components[i]->violatesClearance(*components[j], minClearance)) {
                errormessage = "Clearance violation: " + components[i]->getName() + 
                               " is too close to " + components[j]->getName();
                std::cout << "ERROR: " << errormessage << std::endl;
                return true;
            }
        }
    }
    return false;
}