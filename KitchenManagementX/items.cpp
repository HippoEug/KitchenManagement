#include "items.hpp"

item::item() { //constructor here, check defaulting with queue system
	category = 0; //change to choice, 1 = raw, 2 = fresh, 3 = precooked
	product = "NULL";
	productCode = 0;
	dateDay = 0;
	dateMonth = 0;
	dateYear = 0;
}
