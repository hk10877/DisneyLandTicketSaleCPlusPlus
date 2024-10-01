# DisneyLandTicketSaleCPlusPlus
/*
Objectives: 
• Use inheritance to create base and child classes.   
• Utilize multiple classes in the same program.  
• Perform standard input validation 
• Implement a solution that uses polymorphism 

Problem: Disneyland is experimenting with a new program where Disney fans can personalize reusable drinking 
cups and fill them with their favorite drinks.  You have been hired by Disney to create a program that will track 
customer purchases and the rewards applied to each customer’s account.  Based on the amount that a customer 
spends, they will be placed into a reward tier giving them discounts on future purchases. 

Pseudocode:

File name: Main.cpp

//Returns the price of the customer wants to personalize the product
FindPriceOfPersonalizedProduct Function- 
Parameter: double diameter, double height, double quantity
Return: double
	Make a variable called personalizationPrice
	Write 3 if statements according to the size of the cup, S, M, L
	In case the cup is small, 
•	personalizationPrice is equal to value of 2 * pi *2 * 4.5;
	In case the cup is medium, 
•	personalizationPrice is equal to value of 2 * pi *2.25 * 5.75;
	In case the cup is small, 
•	personalizationPrice is equal to value of 2 * pi *2.75 * 7;

	personalizationPrice = personalizationPrice* getPriceperSquareInch
	return personalizationPrice;

//calculates the discount for preferred costumers
FindDiscount Function- 
Parameter: array of preferred costumers
Return: int

	Make an int variable called discount
	Loop through all the preferred costumers
	If object.getAmount() >=50 and object.getAmount() <99.99
o	Discount is 5
	If object.getAmount() >=100 and object.getAmount() <=149.99
o	Discount is 10
	If object.getAmount() >=150 and object.getAmount() <199.99
o	Discount is 15
	Return discount
//Reading the file and creating the arrays and calling the necessary methods
Main
	Prompt the user for the regular costumer file
	Make an array of costumer objects called regCostumers.
	While file doesn’t reach the end of the file
•	Make a counter called count;
•	Read in the first word from the file and set the customer id 
•	Read the next 2 words from the file and set the string as the name of the object
•	Read the last word and type cast it to a double. Set the double as the price of the object.
•	Store the object at the count position of the array
•	Increase count by 1

	Prompt the user for the preferred customer file
	Check if file is empty
	If the file is not empty
•	Make an array of costumer objects called prefCostumers.
•	While file doesn’t reach the end of the file
o	Make a counter called count2;
o	Read in the first word from the file and set the customer id 
o	Read the next 2 words from the file and set the string as the name of the object
o	Read the next word and type cast it to a double. Set the double as the price of the object.
o	Read the last word and set the value in bonus bucks
o	Store the object at the count position of the array
o	Increase count2 by 1

	Prompt the user for the orders file
	While file doesn’t reach the end of the file
•	Read in the first word that is the ID of the person who ordered
•	Using the id, find the index of the object of the array containing that id
•	If id is not found, continue;
•	Else 
•	Read in the next word that is the drink size
•	Type cast the string into a char and set the drink size of the object at that index
•	Read in the next word that is the drink type
•	Set the drink type of the object at that index
•	Read in the next word that is the square inch price 
•	Type cast the string into a double and set the square inch price of the object at that index
•	Read in the next word that is the quantity
•	Type cast the string into an integer and set the quantity of the object at that index

	Loop through all the regular costumers using a for loop
	If the object.getAmount() is greater than 50
•	Then remove the costumer from the array and add it to the preferred costumers
•	To add the object to the preferred costumers, create a new array and with size 1 greater than the previous array and copy down all the objects from prefCostumers. Then add the new object at the end of the array.
•	Resize the regCostumers array by creating a new array with regCostumers.size() -1 and copy all the elements into that new array

	Loop through the preferred costumer array
	If the object.getAmount > 200
•	Create a new plantitnum object
•	Put the platinum object at that index
•	Create a variable called bonusBuck
•	bonusBuck is (amount spent – 200) /5
•	set the bonusBuck for the object using the mutator method of the platinum class

	Create a new file called customer.dat
	Overload the << operator
	Loop through each element of the regular costumers
	print the information of each element using ostream into the file though the accessor methods of the costumer class

	Create a new file called preferred.dat
	Overload the << operator
	Loop through each element of the preferred costumers
	print the information of each element using ostream into the file though the accessor methods of the costumer class

Test Cases
1.	Regular costumer ordering enough to get promoted to gold costumer
2.	Gold costumer ordering enough to get promoted to platinum costumer
3.	Ordering two beverages with design, one medium and other large
4.	Platinum costumer ordering and receiving bonus bucks
5.	Gold costumer using discounts available and earning more discounts
6.	Regular costumer ordering below $50
7.	Costumer ordering 3 different drinks of different sizes
8.	Platinum costumer ordering using bonus bucks
9.	Platinum costumer earning no bonus bucks
10.	 Gold customer earning a 15% discount for future purchases 

*/
