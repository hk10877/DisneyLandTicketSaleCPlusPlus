#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h> 
#include <cmath>

#include "Customer.h"
#include "Gold.h"
#include "Platinum.h"

double findprice(char cupSize, std::string drinkType, double pricePerSquareInch, int quantity)
{
    double price;
    double oz;
    double area;
    
      if (cupSize == 'S')
      {
          oz = 12;
          area = 2 * M_PI * 2 * 4.5;
      }
      
      else if (cupSize == 'M')
      {
          oz = 20;
          area = 2 * M_PI * 2.25 * 5.75;
      }
      
      else if (cupSize == 'L')
      {
          oz = 32;
          area = 2 * M_PI * 2.75 * 7;
      }
      
      else
      {
          std::cout << "Not Vaild" << std::endl;
      }
      
      
      if (drinkType == "soda")
      {
          price = 0.20;
      }
      
      else if (drinkType == "tea")
      {
          price = 0.12;
      }
      
      else if (drinkType == "punch")
      {
          price = 0.15;
      }
      
      else
      {
          std::cout << "Not Vaild" << std::endl;
      }
      
      price = (price * oz * quantity) + (area * pricePerSquareInch * quantity);
      
     
      
      
      return price;
}

Customer** regCustPromotedToGold(Customer* customers[], Customer* preferredCustomers[], int counterCust, int counterPref, std::string id)
{
    Customer* *newPreferredCustomers = new Customer*[counterPref + 1];
    for (int i = 0; i < counterPref; i++)
    {
        newPreferredCustomers[i] = preferredCustomers[i];
    }
    
    for (int j = 0; j < counterCust; j++)
    {
        if (customers[j]->getID() == id)
        {
            Gold* new_obj = new Gold();
            new_obj ->setID(customers[j] ->getID());
            new_obj ->setFirstName(customers[j] ->getFirstName()); 
            new_obj ->setLastName(customers[j] ->getLastName());
            new_obj ->setAmountSpent(customers[j] ->getAmountSpent());
            
            
            //= customers[j]
            
            newPreferredCustomers[counterPref] = new_obj;
        }
        
    }
    
   
    preferredCustomers = newPreferredCustomers;
    
     for(int q = 0; q <counterPref + 1; q++)
    {
        std::cout << "This is the one we want " << preferredCustomers[q] ->getID() << std::endl;
    }
    
    
    return newPreferredCustomers;
}

Customer** regCustomersPromoted(Customer* customers[], int counterCust, std::string id)
{
    Customer* *newRegularCustomers = new Customer*[counterCust - 1];
    int m=0;
    for (int k = 0; k < counterCust; k++)
    {
        if (customers[k]->getID() == id)
        {
            continue;
        }
        newRegularCustomers[m] = customers[k];
        m++;
    }
    
    // for (int l = 0; l < counterCust; l++)
    // {
        
    //     delete customers[l];
        
    // }
   
    
    customers = newRegularCustomers;
    /*
     for(int q = 0; q <counterCust-1; q++)
    {
        std::cout << "This is the one we want---- " << customers[q] ->getID() << std::endl;
    }
    */
    return newRegularCustomers;
}


Customer** goldCustPromotedToPlatinum(Customer* preferredCustomers[], int counterPref, std::string id)
{
    Platinum* plat = new Platinum();
    int index;
    
    for (int i = 0; i< counterPref; i++)
    {
        if (preferredCustomers[i]->getID() == id)
        {
            int index = i;
            break;
        }
    }
    
    plat->setID(id);
    plat->setFirstName(preferredCustomers[index]->getFirstName());
    plat->setLastName(preferredCustomers[index]->getLastName());
    plat->setAmountSpent(preferredCustomers[index]->getAmountSpent());
    
    preferredCustomers[index] = plat;
    
    return preferredCustomers;
}









void makeCustomerFile(Customer* customers[], int numCountOfRegCustomers)
{
    std::ofstream MyFile("customer.dat");
  if (MyFile.good()) {
    std::cout << "File created" << std::endl;
  } else {
    std::cout << "File already exists" << std::endl;
  }
  
  std::ofstream outputFile("customer.dat");

  if (outputFile.is_open()) 
  {
      for (int e = 0; e < numCountOfRegCustomers; e++)
      {
         
          outputFile << customers[e]->getID();
          outputFile << " ";
          outputFile << customers[e]->getFirstName();
          outputFile << " ";
          outputFile << customers[e]->getLastName();
          outputFile << " ";
          outputFile << std::fixed << std::showpoint << std::setprecision(2) <<customers[e]->getAmountSpent();
          
          if (e < numCountOfRegCustomers - 1)
          {
              outputFile << "\n";
          }
          
          
      }
      
      outputFile.close();
  }

  else 
  {
    std::cout << "Error: Unable to open the file." << std::endl;
  }
}
  
  
  
  
  
void makePrefCustomerFile(Customer* preferredCustomers[], int numCountOfPrefCustomers)
{
  std::ofstream MyFile2("preferred.dat");
  if (MyFile2.good()) {
    std::cout << "File created" << std::endl;
  } else {
    std::cout << "File already exists" << std::endl;
  }
  
  std::ofstream outputFile2("preferred.dat");

  if (outputFile2.is_open()) 
  {
      for (int g = 0; g < numCountOfPrefCustomers; g++)
      {
          outputFile2 << preferredCustomers[g]->getID();
          outputFile2 << " ";
          outputFile2 << preferredCustomers[g]->getFirstName();
          outputFile2 << " ";
          outputFile2 << preferredCustomers[g]->getLastName();
          outputFile2 << " ";
          outputFile2 << preferredCustomers[g]->getAmountSpent();
          outputFile2 << " ";
          
          if (Gold* c = dynamic_cast<Gold*>(preferredCustomers[g]))
          {
              outputFile2 << c->getDiscountPercentage();
              outputFile2 << '%';
          }
          
          
          if (g < numCountOfPrefCustomers - 1)
          {
              outputFile2 << "\n";
          }
          
          
      }
      std::cout << "the program reached till here " << std::endl;
      outputFile2.close();
  }

  else 
  {
    std::cout << "Error: Unable to open the file." << std::endl;
  }
} 
  
  
  

int main() 
{
  std::string regFileName;
  std::cout << "Enter the regular costumer file: " << std::endl;
  
  std::cin >> regFileName;
  //std::cout << "Here " << std::endl;

  std::ifstream inputFile(regFileName);
  //std::cout << "Here2 " << std::endl;

  Customer** customers = new Customer*[4];
  int numCountOfRegCustomers = 0;
  
  if (inputFile.is_open()) // missing file check
    
  {
    //std::cout << "Here3 " << std::endl;
    std::string line;
    

    //fix this, the number of customers is not known
    
   
    //std::cout << "Here4 " << std::endl;

    std::string idFromFile; 
    std::string firstNameFromFile; 
    std::string lastNameFromFile; 
    double amountFromFile;

    int counter =0;

    while(!inputFile.eof())
      {
        getline(inputFile, line);
          std::stringstream ss(line);

        customers[counter] = new Customer();
        ss >> idFromFile;
        ss >> firstNameFromFile;
        ss >> lastNameFromFile;
        ss >> amountFromFile;
        
        customers[counter]->setID(idFromFile);
        customers[counter]->setFirstName(firstNameFromFile);
        customers[counter]->setLastName(lastNameFromFile);
        customers[counter]->setAmountSpent(amountFromFile);


        // std::cout << "this is setId" << customers[counter]->getID() << std::endl;
        // std::cout << "this is setFirstName" << customers[counter]->getFirstName() << std::endl;
        // std::cout << "this is setLastName" << customers[counter]->getLastName() << std::endl;
        // std::cout << "this is setAmountSpent" << customers[counter]->getAmountSpent() << std::endl;

        counter++;
      }

    inputFile.close(); // Close the file when done
    numCountOfRegCustomers = counter;
  }
 
  else 
  {
    std::cout << "Error: Unable to open the file." << std::endl;
  }
    


  std::string prefFileName;
  std::cout << "Enter the Preferred costumer file: " << std::endl;
  std::cin >> prefFileName;

  Customer* *preferredCustomers = new Customer*[4];
  int numCountOfPrefCustomers = 0;

  std::ifstream inputFile2(prefFileName);
  if (inputFile2.is_open()) // missing file check
  {
    std::string line2;
    //int count2 = 0;

      
    

    //Customer** customers = new Customer*[4];
    //std::cout << "Here4 " << std::endl;

    std::string idFromFile; 
    std::string firstNameFromFile; 
    std::string lastNameFromFile; 
    double amountFromFile;
    std::string discountPerc;

    int counterPref =0;

    while(!inputFile2.eof())
      {
        getline(inputFile2, line2);
          std::stringstream sspref(line2);

        //preferredCustomers[counterPref] = new Customer();
        sspref >> idFromFile;
        sspref >> firstNameFromFile;
        sspref >> lastNameFromFile;
        sspref >> amountFromFile;
        sspref >> discountPerc;

        
        //std::cout << "this is discountPerc" << discountPerc << std::endl;
        

        if (discountPerc[discountPerc.length() -1] == '%')
        {
           std::string dis = "";
           int len = static_cast<int>(discountPerc.length());
            for (int i = 0; i < len -1 ; i++)
            {
              dis.push_back(discountPerc[i]);
            }
            Gold* obj = new Gold();

        
            //std::cout << "this is dis" << dis << std::endl;
             double amount2 = std::stod(dis);
            
    
           //Gold* obj = (dynamic_cast<Gold*>(preferredCustomers[counterPref])); 
            obj->setDiscountPercentage(amount2);
            
           
            obj->setID(idFromFile);
            //std::cout << "this is setId" << preferredCustomers[counterPref]->getID() << std::endl;
                    
            
            obj->setFirstName(firstNameFromFile);
            obj->setLastName(lastNameFromFile);
            obj->setAmountSpent(amountFromFile);
    
            preferredCustomers[counterPref] = obj;
            
    
    
            // std::cout << "this is setId" << obj->getID() << std::endl;
            // std::cout << "this is setFirstName" << obj->getFirstName() << std::endl;
            // std::cout << "this is setLastName" << obj->getLastName() << std::endl;
            // std::cout << "this is setAmountSpent" << obj->getAmountSpent() << std::endl;
    
            // std::cout << "this is setDiscountPercentage" << obj->getDiscountPercentage() << std::endl;

          

        }

          

        else 
        {
          //Platinum object case
          std::string bonus = discountPerc;
           //int len = static_cast<int>(discountPerc.length());
            // for (int i = 0; i < len; i++)
            // {
            //   dis.push_back(discountPerc[i]);
            // }
            Platinum* objPlat = new Platinum();

        
            std::cout << "this is bonus" << bonus << std::endl;
             int amount3 = std::stoi(bonus);
            std::cout << "this is amount3" << amount3 << std::endl;
    
            //if (dynamic_cast<Platinum*>(preferredCustomers[counterPref]))
            //{
                std::cout << "entered this case" << std::endl;
                objPlat->setBonusBucks(amount3);
                 std::cout << "this is setBonusBucks" << objPlat->getBonusBucks() << std::endl;
            //}
            
            
           
            objPlat->setID(idFromFile);
            //std::cout << "this is setId" << preferredCustomers[counterPref]->getID() << std::endl;
                    
            
            objPlat->setFirstName(firstNameFromFile);
            objPlat->setLastName(lastNameFromFile);
            objPlat->setAmountSpent(amountFromFile);
    
            preferredCustomers[counterPref] = objPlat;
            
           
          
        }
        //discountPerc.substr(discountPerc.begin(),discountPerc.length()-1);
       


        counterPref++;
        numCountOfPrefCustomers = counterPref;
      }

    inputFile.close(); // Close the file when done
  }
    //Customer *preferredCustomers = new Customer[4];

  else 
  {
    std::cout << "Error: Unable to open the file." << std::endl;
  }


  //orderfile

  std::string orderName;
  std::cout << "Enter the orders file: " << std::endl;
  std::cin >> orderName;

  std::ifstream inputFile3(orderName);
  if (inputFile3.is_open()) // missing file check
  {
      
    std::string idFromOrderFile; 
    std::string cupSizeFromOrderFile; 
    std::string drinkTypeFromOrderFile; 
    double pricePerSquareInchFromOrderFile;
    int quantityFromOrderFile;
    
    
    std::string line3;
    int count3 = 0;
    
    

    //Customer preferredCustomers[4];


    while(!inputFile3.eof())
      {
          getline(inputFile3, line3);
          std::stringstream ssodr(line3);

        //preferredCustomers[counterPref] = new Customer();
        ssodr >> idFromOrderFile;
        ssodr >> cupSizeFromOrderFile;
        ssodr >> drinkTypeFromOrderFile;
        ssodr >> pricePerSquareInchFromOrderFile;
        ssodr >> quantityFromOrderFile;

        count3 =0;
        bool cond = false;
        
        while (count3 < numCountOfRegCustomers)
        {
           
            
            if (count3 < numCountOfRegCustomers && customers[count3]->getID() == idFromOrderFile)
            {
             
              char cupSize = cupSizeFromOrderFile.at(0);
              
              std::string drinkType = drinkTypeFromOrderFile;
              
              
              double pricePerSquareInch = pricePerSquareInchFromOrderFile;
             
              int quantity = quantityFromOrderFile;
             
              
              
                double spend = (customers[count3]->getAmountSpent());
                double spent = findprice(cupSize, drinkType, pricePerSquareInch, quantity);
                
                
                spent = round(spent * 100)/100;
                
                spend = spend + spent;
               
                
                customers[count3]->setAmountSpent(spend) ;
              
             
              if (customers[count3]->getAmountSpent() > 50)
              {
                  cond = true;
                  Customer** newRegCustom = regCustPromotedToGold(customers, preferredCustomers, numCountOfRegCustomers, numCountOfPrefCustomers, customers[count3]->getID());
                  
                  Customer** newPrefCustom =regCustomersPromoted(customers, numCountOfRegCustomers, customers[count3]->getID());
                  
                  
                  customers = newPrefCustom;
                  preferredCustomers = newRegCustom;
                  
                  numCountOfRegCustomers--;
                  numCountOfPrefCustomers++;
                  
                 
                
              if (Gold* ob = dynamic_cast<Gold*>(preferredCustomers[count3]))
                {
                   
                    if (spend >50 && spend < 99.99)
                        {
                            ob->setDiscountPercentage(5);
                        }
                        
                        if (spend >100 && spend < 149.99)
                        {
                            ob->setDiscountPercentage(10);
                        }
                        
                        if (spend >150 && spend < 199.99)
                        {
                            ob->setDiscountPercentage(15);
                        }
                    
                }
                
                
                    
                
              }
              
              
              

              
              
            }
            
            count3++;
            
            
            
          }
          

          count3 = 0;
          //bool anotherCond = false;
          while (count3 < numCountOfPrefCustomers && cond ==false)
          {
              std::cout <<"enters here" << std::endl;
              
           if (count3 < numCountOfPrefCustomers && preferredCustomers[count3]->getID() == idFromOrderFile)
           {
             
              char cupSizeP = cupSizeFromOrderFile.at(0);

              std::string drinkTypeP = drinkTypeFromOrderFile;
             
              double pricePerSquareInchP = pricePerSquareInchFromOrderFile;

              int quantityP = quantityFromOrderFile;
              
              
              
                  
                double spendP = (preferredCustomers[count3]->getAmountSpent());
                
                
                double spentP = findprice(cupSizeP, drinkTypeP, pricePerSquareInchP, quantityP);
                
                
                //this code is for testing
                for (int y = 0;)
                {
                    std::cout << y->getID() << " printing" << std::endl;
                }
                
                
                
            if (Gold* ob = dynamic_cast<Gold*>(preferredCustomers[count3]))
            {
                std::cout <<"enters discoutFromBefore here" << std::endl;
                double discoutFromBefore = ob->getDiscountPercentage();
                spentP = spentP * ((100 - discoutFromBefore)/100);
 
            }
            
            
            spendP = spendP + spentP;
            preferredCustomers[count3]->setAmountSpent(spendP) ;
            
            if (Gold* object = dynamic_cast<Gold*>(preferredCustomers[count3]))
            {
                std::cout << "does it even reach here? lets check" << std::endl;
                if (spendP >50 && spendP < 99.99)
                {
                    object->setDiscountPercentage(5);
                }
                
                if (spendP >100 && spendP < 149.99)
                {
                    object->setDiscountPercentage(10);
                }
                
                if (spendP >150 && spendP < 199.99)
                {
                    object->setDiscountPercentage(15);
                }
                
                if (spendP > 200)
                {
                    preferredCustomers = goldCustPromotedToPlatinum(preferredCustomers, numCountOfPrefCustomers, preferredCustomers[count3]->getID());
                }
                
                
            }
            
           }
            count3++;

          }
          
      
          
          
      }

        
   

    inputFile3.close(); // Close the file when done
    std::cout << "the file is closed" << std::endl;
    
    
    
  } 
  else 
  {
    std::cout << "Error: Unable to open the file." << std::endl;
  }

makeCustomerFile(customers, numCountOfRegCustomers);
makePrefCustomerFile(preferredCustomers, numCountOfPrefCustomers);
  
  
  

} //end of main