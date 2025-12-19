#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <string>
class Validation{
protected:
  bool checker;
  std::string errormessage;
public:
  Validation();
  virtual ~Validation();
  virtual bool validate()=0;
  bool getHasError() const;
  std::string getErrorMess() const;
  void reset();


};
#endif