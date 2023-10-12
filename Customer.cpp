#include "Customer.h"
#include <string>

Customer::Customer()
{
  //std::cout << "this is the construstor" << std::endl;
  firstName = "";
  lastName = "";
  id = "";
  amountSpent = 0.0;
}

Customer::Customer(std::string firstName, std::string lastName, std::string id, double amountSpent)
{
  this->firstName = firstName;
  this-> lastName = lastName;
  this->id =  id;
  this->amountSpent = amountSpent;
}

// Customer& Customer::operator=(const Customer& objToCopy) {
//   std::cout << "Assignment op called." << std::endl;
   
//   Customer *dataObject;
//   if (this != &objToCopy) {           // 1. Don't self-assign
//       //delete dataObject;                  // 2. Delete old dataObject
//       dataObject = new Customer();               // 3. Allocate new dataObject
//       *dataObject.firstName = *(objToCopy.firstName); // 4. Copy dataObject
//       *dataObject.lastName = *(objToCopy.lastName);
//       *dataObject.id = *(objToCopy.id);
//       *dataObject.amountSpent = *(objToCopy.amountSpent);
//   }
   
//   return *this;
// }


//virtual Customer::~Customer();

