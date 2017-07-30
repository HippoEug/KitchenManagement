#pragma once
#include <iostream>
#include <string>
using namespace std;

void addNewItem(int& categoryX, string& productX, int& productCodeX, long long& dateX)
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

	cout << "Enter Product Expiry Date [DDMMYYYY]: ";
	cin >> dateX;
}

void lineCount(int& numberOfLines)
{
	ifstream inFile;
	inFile.open("FSTREAM DSA GROUP WORK V1.4A");

	string line;

	numberOfLines = 0;

	while (getline(inFile, line))
		++numberOfLines;
}
