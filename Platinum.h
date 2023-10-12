#ifndef PLATINUM_H
#define PLATINUM_H
#include <string>
#include "Customer.h"

/*
Preferred Customer - Platinum (derived from customer)
o Filename – Platinum.h
o Member
  ▪ Bonus bucks (integer)
o Methods
  ▪ Overloaded Constructor (uses overloaded base class constructor)
    • Additional parameter: bonus
  ▪ Accessor
  ▪ Mutator
*/
class Platinum 
{
  private:
  int bonusBucks;

  public:
    Platinum(std::string, std::string, std::string, double, int);
    int getBonusBucks() {return bonusBucks;}
    void setBonusBucks(int bonusBucks) { this->bonusBucks =bonusBucks;}

};



#endif
