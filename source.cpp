//
//  main.cpp
//  DSA GROUP WORK
//
//  Created by HippoEug on 5/7/17.
//  Copyright © 2017 HippoEug. All rights reserved.
//

//
/*
Problem:
You observed that a lot of food was wasted because it was placed in the kitchen for too long and it needs to be thrown away because it has expired. You have decided to develop a software to help keep track of the inventory in the kitchen.
There are many type of food in the kitchen for example raw food such as fish, meat; dairy product such as milk, cheese; can food such as pasta sauce, condensed milk; and fresh produce such as vegetable and fruits. Your system allows user to scan in or key in the food every time when there is a purchase. It will keep track of the quantity available in the kitchen and the expiry date, etc.
The system should use the first-in, first-out sequence when a user key in an item to consume. It should also keep track of the inventory and give a warning when the stock is zero. It should also display a list of items to be expired in 3 days so that user can consume them before they expire.
*/
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
