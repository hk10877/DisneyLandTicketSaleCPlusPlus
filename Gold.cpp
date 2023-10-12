#include <string>
#include "Gold.h"
//#include "Customer.h"

Gold::Gold()
{
  discountPercentage = 0;
}



Gold::Gold (std::string firstName, std::string lastName, std::string id, double amountSpent, double discountPercentage) : Customer(firstName, lastName, id, amountSpent)
	{
		//super(n, dep, id, sal);  -- no super keyword in c++
		this-> discountPercentage = discountPercentage;
	}



