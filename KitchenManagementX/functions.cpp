#include <iostream>
#include <string>
#include <fstream>

#include "functions.hpp"

void addNewItem(int& categoryX, std::string& productX, int& productCodeX, int& dateDayX, int& dateMonthX, int& dateYearX) {
	std::cout << "\nEnter Category of Food Type" << std::endl;
	std::cout << "Press [1]: Raw" << std::endl;
	std::cout << "Press [2]: Fresh" << std::endl;
	std::cout << "Press [3]: Precooked" << std::endl;
	std::cout << "\nEnter Product Category: ";
	std::cin >> categoryX;

	std::cout << "Enter Product Name: ";
	std::cin >> productX;

	std::cout << "Enter Product Code: ";
	std::cin >> productCodeX;

	std::cout << "Enter Product Expiry Day [DD]: ";
	std::cin >> dateDayX;

	std::cout << "Enter Product Expiry Month [MM]: ";
	std::cin >> dateMonthX;

	std::cout << "Enter Product Expiry Year [YYYY]: ";
	std::cin >> dateYearX;
}

void lineCount(int& numberOfLines) {
	std::ifstream lineCount;
	//lineCount.open("V1.2A", std::fstream::in | std::fstream::out | std::fstream::app);
	lineCount.open("V2.1C", std::ios::_Noreplace);

	std::string line;

	numberOfLines = 0;

	while (std::getline(lineCount, line)) {
		++numberOfLines;
	}

	lineCount.close();
}
