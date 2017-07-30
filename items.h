#pragma once
#include <string>
using namespace std;

class item
{
public: //original private:
	int category; //Categories: Raw, Fresh, Dairy
	string product; //Products: Chocolate Milk, Butter
	int productCode; //Product Code: 03421 (to modify this since programme is using FIFO structure
	long long productDate; //Product Expiry Date

	item();
};

item::item() //constructor here, check defaulting with queue system
{
	category = 0; //change to choice, 1 = raw, 2 = fresh, 3 = precooked
	product = "NULL";
	productCode = 0;
	productDate = 0;
}
