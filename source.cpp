//
//  main.cpp
//  DSA GROUP WORK
//
//  Created by HippoEug on 5/7/17.
//  Copyright © 2017 HippoEug. All rights reserved.
//

//
//Catogories: Raw; Dairy; Fresh; (Can food);
//
//Functions: Add, delete, warning
//
//Things to add: Expiry System, Some counting for loops, and delete item function
//
//Create another header file item.h, so #include "item.h" in main.cpp
//
//Change >>cin<< as writing eg string to int will cause program to crash
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include "item.h"
#include "display.h"
#include "functions.h"
using namespace std;

void displayProgramKeepsTrack();
void displayChoice();
void displayNewMenu();

void addNewItem(string categoryX, string productX, int productCodeX, float productPriceX);

int main()
{
	//declaring queue
	queue<item> itemsInKitchen;

	//declaration + initialization
	int choice;

	string categoryX;
	string productX;
	int productCodeX;
	float productPriceX;

	displayProgramKeepsTrack();
	displayChoice();
	cin >> choice;

	while (choice != 0)
	{
		switch (choice)
		{
			case 1:
			{
				system("cls"); //clear console

				item productDetail;

				addNewItem(categoryX, productX, productCodeX, productPriceX);

				productDetail.category = categoryX;
				productDetail.product = productX;
				productDetail.productCode = productCodeX;
				productDetail.productPrice = productPriceX;
				itemsInKitchen.push(productDetail);

				cout << "Number of items = " << itemsInKitchen.size() << endl;

				cout << "TEST OUTPUT: " << endl;
				cout << productDetail.category << endl;
				cout << productDetail.product << endl;
				cout << productDetail.productCode << endl;
				cout << productDetail.productPrice << endl;

				break;
			}
			case 2:
			{
				cout << "ERROR: DELETE NOT IMPLENTED";
				break;
			}
			case 3:
			{
				cout << "ERROR: DISPLAY NOT IMPLENTED";
				break;
			}
			default:
			{
				cout << "ERROR: Enter choice again" << endl;
				break;
			}
		}
		displayNewMenu();
		displayChoice();
		cin >> choice;
	}
}
