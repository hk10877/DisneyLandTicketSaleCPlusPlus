#ifndef GOLD_H
#define GOLD_H
#include <string>
#include "Customer.h"


/*
Preferred Customer - Gold (derived from customer)
o Filename – Gold.h
o Member
  ▪ Discount Percentage (double)
o Methods
  ▪ Default Constructor
  ▪ Overloaded Constructor (uses overloaded base class constructor)
    • Additional parameter: discount
  ▪ Accessor
  ▪ Mutator
*/

class Gold : public Customer
{
  private:
    double discountPercentage;

  public:
    Gold();
    Gold(std::string, std::string, std::string, double, double);
    double getDiscountPercentage() {return discountPercentage;}
    void setDiscountPercentage( double discountPercentage) { this-> discountPercentage = discountPercentage; }

};

#endif //GOLD_H
