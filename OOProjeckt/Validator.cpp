#include "Validator.h"
#include <iostream>

Validation::Validation():checker(false), errormessage(""){}
Validation::~Validation(){}

bool Validation::getHasError() const{
  return checker;
}
std::string Validation::getErrorMess() const{
  return errormessage;
}
void Validation::reset(){
  checker=false;
  errormessage="";
}