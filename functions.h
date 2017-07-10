#pragma once
#include <iostream>
#include <string>
using namespace std;

void addNewItem(string categoryX, string productX, int productCodeX, float productPriceX)
{
	cout << "Enter Product Category: ";
	cin >> categoryX;
	cout << "Enter Product Name: ";
	cin >> productX;
	cout << "Enter Product Code: ";
	cin >> productCodeX;
	cout << "Enter Product Price: $";
	cin >> productPriceX;
}
