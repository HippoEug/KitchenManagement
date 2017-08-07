//
//  main.cpp
//  DSA GROUP WORK
//
//  Created by HippoEug on 5/7/17.
//  Copyright © 2017 HippoEug. All rights reserved.
//

//
//Catogories: Raw; Fresh; Precooked/Can Food
//Functions: Add, Delete, Warning when food is about to expire
//Things to add: Expiry System, Some counting for loops, and delete item function
//Change >>cin<< to >>get<< as writing eg string to int will cause program to crash
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <queue>
#include <chrono>
#include <future>
#include <ctime>
#include "display.h"
#include "functions.h"
#include "timer.h"
#include "items.h"
using namespace std;

int main()
{
	//class declarations
	item productDetail;
	dateRegister datesData;

	//queue declarations
	queue<item> allCategories;
	queue<item> displayCopy;
	queue<item> displayDeleteCopy;

	//declarations of variables
	int sizeToDisplay; //to count the number of times to loop
	int numberOfLines;
	int functionChoice; //for choices to add, delete or display
	int displayTypeChoice; //to display all items, raw or precooked
	int codeToDelete; //for user to enter code to delete

	//delcarations for fstream
	int fstreamCategory;
	string fstreamName;
	int fstreamCode;
	//long long fstreamDate; //change this
	int fstreamDateDay;
	int fstreamDateMonth;
	int fstreamDateYear;

	//initialization when adding new item
	int categoryX = 0;
	string productX = "NULL";
	int productCodeX = 0;
	//long long dateX = 0;
	int dateDayX = 0;
	int dateMonthX = 0;
	int dateYearX = 0;

	displayProgramKeepsTrack();
	cout << "Loading... " << endl;
	cout << "HippoEug.Inc Version: 2.1C" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Auto-Detecing PR1 Channel..." << endl;
	cout << "Auto-Detecing PR1 Channel..." << endl;
	cout << "Auto-Detecing PR1 Channel..." << endl;
	cout << "Auto-Detecing PR1 Channel..." << endl;
	cout << "Auto-Detecing PR1 Channel..." << endl;
	cout << "INITIALIZATION COMPLETED" << endl;
	this_thread::sleep_for(chrono::seconds(2));

	//functions to run in the background
	auto getDate = async(&dateRegister::updateDate, &datesData); //getting date in the background
	auto dayCalculation = async(&dateRegister::dayMainCalculator, &datesData); //count number of days since year 2000 in the background
	auto dayWarning = async(&dateRegister::dayAlarm, &datesData); //to give warning when expiry date is close

	//copying existing data into
	lineCount(numberOfLines); //becareful, ifstream content here too
	ifstream getData;
	//getData.open("V1.2B", std::fstream::in | std::fstream::out | std::fstream::app);
	getData.open("V2.1C", std::ios::_Noreplace); //use this for windows

	//cout << "Number of lines = " << numberOfLines << endl; //for debugging

	for (int i = 1; i <= numberOfLines; i++)
	{
		getData >> fstreamCategory >> fstreamName >> fstreamCode >> fstreamDateDay >> fstreamDateMonth >> fstreamDateYear;

		productDetail.category = fstreamCategory;
		productDetail.product = fstreamName;
		productDetail.productCode = fstreamCode;
		productDetail.dateDay = fstreamDateDay;
		productDetail.dateMonth = fstreamDateMonth;
		productDetail.dateYear = fstreamDateYear;

		allCategories.push(productDetail);
	}
	getData.close();

	this_thread::sleep_for(chrono::seconds(1));

	//start of program
	displayChoice();
	cin >> functionChoice;

	while (functionChoice != 0)
	{
		switch (functionChoice)
		{
			//function to add item
		case 1:
		{
			system("cls");
			addNewItem(categoryX, productX, productCodeX, dateDayX, dateMonthX, dateYearX);

			productDetail.category = categoryX;
			productDetail.product = productX;
			productDetail.productCode = productCodeX;
			productDetail.dateDay = dateDayX;
			productDetail.dateMonth = dateMonthX;
			productDetail.dateYear = dateYearX;

			allCategories.push(productDetail);

			cout << "\nTotal number of items = " << allCategories.size() << endl;
			break;
		}
		//function to delete item
		case 2:
		{
			system("cls");
			//to display current items
			queue<item> displayCopy = allCategories;
			sizeToDisplay = static_cast<int>(displayCopy.size());

			for (int i = 1; i <= sizeToDisplay; i++)
			{
				productDetail = displayCopy.front();

				cout << "\nCategory: ";
				switch (productDetail.category)
				{
				case 1:
					cout << "Raw" << endl;
					break;
				case 2:
					cout << "Fresh" << endl;
					break;
				case 3:
					cout << "Pre-Cooked" << endl;
					break;
				}
				cout << "Name: " << productDetail.product << endl;
				cout << "Code: " << productDetail.productCode << endl;
				cout << "Expiry Date: " << productDetail.dateDay << "-" << productDetail.dateMonth << "-" << productDetail.dateYear << endl;

				displayCopy.pop();
			}

			//to delete item and copy into a queue
			queue<item> displayDeleteCopy = allCategories;
			for (int i = 1; i <= sizeToDisplay; i++)
			{
				allCategories.pop();
			}

			sizeToDisplay = static_cast<int>(displayDeleteCopy.size());

			//system("cls"); //rellocate this
			displayDelete();
			cin >> codeToDelete;

			for (int i = 1; i <= sizeToDisplay; i++) //for (int i = 0; i < sizeToDisplay; i++)
			{
				productDetail = displayDeleteCopy.front();

				if (productDetail.productCode != codeToDelete)
				{
					allCategories.push(productDetail);
					displayDeleteCopy.pop();
				}
				else if (productDetail.productCode == codeToDelete)
				{
					cout << "Data has been deleted" << endl;
					displayDeleteCopy.pop();
				}
			}
			break;
		}
		//function to display items
		case 3:
		{
			system("cls");
			displayOption();
			cin >> displayTypeChoice;

			switch (displayTypeChoice)
			{
				//to display all items in raw, precooked and fresh
			case 1:
			{
				queue<item> displayCopy = allCategories;
				sizeToDisplay = static_cast<int>(displayCopy.size());

				for (int i = 1; i <= sizeToDisplay; i++)
				{
					productDetail = displayCopy.front();

					cout << "\nCategory: ";
					switch (productDetail.category)
					{
					case 1:
						cout << "Raw" << endl;
						break;
					case 2:
						cout << "Fresh" << endl;
						break;
					case 3:
						cout << "Pre-Cooked" << endl;
						break;
					}
					cout << "Name: " << productDetail.product << endl;
					cout << "Code: " << productDetail.productCode << endl;
					cout << "Expiry Date: " << productDetail.dateDay << "-" << productDetail.dateMonth << "-" << productDetail.dateYear << endl;

					displayCopy.pop();
				}
				break;
			}
			//to display raw items
			case 2:
			{
				queue<item> displayCopy = allCategories;
				sizeToDisplay = static_cast<int>(displayCopy.size());

				for (int i = 1; i <= sizeToDisplay; i++)
				{
					productDetail = displayCopy.front();

					if ((productDetail.category) == 1)
					{
						cout << "\nCategory: Raw" << endl;
						cout << "Name: " << productDetail.product << endl;
						cout << "Code: " << productDetail.productCode << endl;
						cout << "Expiry Date: " << productDetail.dateDay << "-" << productDetail.dateMonth << "-" << productDetail.dateYear << endl;
					}
					displayCopy.pop();
				}
				break;
			}
			//to display fresh items
			case 3:
			{
				queue<item> displayCopy = allCategories;
				sizeToDisplay = static_cast<int>(displayCopy.size());

				for (int i = 1; i <= sizeToDisplay; i++)
				{
					productDetail = displayCopy.front();

					if ((productDetail.category) == 2)
					{
						cout << "\nCategory: Fresh" << endl;
						cout << "Name: " << productDetail.product << endl;
						cout << "Code: " << productDetail.productCode << endl;
						cout << "Expiry Date: " << productDetail.dateDay << "-" << productDetail.dateMonth << "-" << productDetail.dateYear << endl;
					}
					displayCopy.pop();
				}
				break;
			}
			//to display precooked items
			case 4:
			{
				queue<item> displayCopy = allCategories;
				sizeToDisplay = static_cast<int>(displayCopy.size());

				for (int i = 1; i <= sizeToDisplay; i++)
				{
					productDetail = displayCopy.front();

					if ((productDetail.category) == 3)
					{
						cout << "\nCategory: Pre-Cooked" << endl;
						cout << "Name: " << productDetail.product << endl;
						cout << "Code: " << productDetail.productCode << endl;
						cout << "Expiry Date: " << productDetail.dateDay << "-" << productDetail.dateMonth << "-" << productDetail.dateYear << endl;
					}
					displayCopy.pop();
				}
				break;
			}
			default:
				cout << "[WARNING]: SWITCH DISPLAY TYPE ERROR" << endl;
				break;
			}
		}
		}
		ofstream writeData;
		writeData.open("V2.1C");
		queue<item> displayCopy = allCategories;
		sizeToDisplay = static_cast<int>(displayCopy.size());

		for (int i = 1; i <= sizeToDisplay; i++)
		{
			productDetail = displayCopy.front();

			fstreamCategory = productDetail.category;
			fstreamName = productDetail.product;
			fstreamCode = productDetail.productCode;
			fstreamDateDay = productDetail.dateDay;
			fstreamDateMonth = productDetail.dateMonth;
			fstreamDateYear = productDetail.dateYear;

			writeData << fstreamCategory << " " << fstreamName << " " << fstreamCode << " " << fstreamDateDay << " " << fstreamDateMonth << " " << fstreamDateYear << endl;

			displayCopy.pop();
		}
		writeData.close();

		displayNewMenu();
		displayChoice();
		cin >> functionChoice;
	}
}
