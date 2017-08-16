#pragma once
#include <iostream>
#include <string>
using namespace std;

void addNewItem(int& categoryX, string& productX, int& productCodeX, int& dateDayX, int& dateMonthX, int& dateYearX)
{
	cout << "\nEnter Category of Food Type" << endl;
	cout << "Press [1]: Raw" << endl;
	cout << "Press [2]: Fresh" << endl;
	cout << "Press [3]: Precooked" << endl;
	cout << "\nEnter Product Category: ";
	cin >> categoryX;

	cout << "Enter Product Name: ";
	cin >> productX;

	cout << "Enter Product Code: ";
	cin >> productCodeX;

	//cout << "Enter Product Expiry Date [DDMMYYYY]: ";
	//cin >> dateX;

	cout << "Enter Product Expiry Day [DD]: ";
	cin >> dateDayX;

	cout << "Enter Product Expiry Month [MM]: ";
	cin >> dateMonthX;

	cout << "Enter Product Expiry Year [YYYY]: ";
	cin >> dateYearX;
}

void lineCount(int& numberOfLines)
{
	ifstream lineCount;
	//lineCount.open("V1.2A", std::fstream::in | std::fstream::out | std::fstream::app);
	lineCount.open("V2.1C", std::ios::_Noreplace);

	string line;

	numberOfLines = 0;

	while (getline(lineCount, line))
		++numberOfLines;

	lineCount.close();
}
