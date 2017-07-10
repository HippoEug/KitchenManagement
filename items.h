#pragma once
#include <string>
using namespace std;

class item
{
public: //original private:
	string category; //Categories: Raw, Fresh, Dairy
	string product; //Products: Chocolate Milk, Butter
	int productCode; //Product Code: 03421 (to modify this since programme is using FIFO structure
	float productPrice; //Product Price: $30.20, also check if this is neccessary with client
						//public:
	item(); //constructor
	//~item(); //deconstructor, delete if not necessary
	//to make category, product, productCode and productPrice as private, hence write functions for it
};

item::item() //constructor here, check defaulting with queue system
{
	category = "NULL";
	product = "NULL";
	productCode = 0;
	productPrice = 0;
}
