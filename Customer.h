#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>

/*
• Customer (base class)
o Filename – Customer.h
o Members
  ▪ First name (string)
  ▪ Last name (string)
  ▪ Guest ID (string)
  ▪ Amount spent (double)
o Methods
  ▪ Default Constructor
  ▪ Overloaded Constructor
    • Parameters: first name, last name, ID, amount
  ▪ Accessors
  ▪ Mutators
  */
class Customer
{
  protected:
    std::string firstName;
    std::string lastName;
    std::string id;
    double amountSpent;
    //char custType;


  public:
    Customer();
    Customer(std::string, std::string, std::string, double);
    virtual ~Customer(){std::cout << "Destructor"<< std::endl;}
    std::string getFirstName() const{ return firstName;}
    std::string getLastName() const{ return lastName; }
    std::string getID() const{ return id; }
    double getAmountSpent() const{ return amountSpent;}

    void setFirstName(std::string firstName) {this->firstName =firstName;}
    void setLastName(std::string lastName) {this->lastName =lastName;}
    void setID(std::string id) {this->id =id;}
    void setAmountSpent(double amountSpent) {this-> amountSpent = amountSpent;}
  
    //Customer& operator=(const Customer& objToCopy);
};








#endif // CUSTOMER_H