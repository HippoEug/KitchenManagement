#pragma once

#include <string>

class item {
public: //original private:
	int category; //Categories: Raw, Fresh, Dairy
	std::string product; //Products: Chocolate Milk, Butter
	int productCode; //Product Code: 03421 (to modify this since programme is using FIFO structure
	int dateDay;
	int dateMonth;
	int dateYear;

	item();
};
