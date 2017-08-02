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

void displayProgramKeepsTrack();
void displayChoice();
void displayNewMenu();
void displayOption();
void displayDelete();

void lineCount(int& numberOfLines);

void addNewItem(int& categoryX, string& productX, int& productCodeX, long long& dateX);

int main()
{
	item productDetail;
	dateRegister datesData;

    queue<item> allCategories;
    queue<item> raw;
    queue<item> fresh;
    queue<item> precooked;
    
    queue<item> displayCopy;
	queue<item> displayDeleteCopy;
    
    int sizeToDisplay;
    
    //declaration + initialization
    int functionChoice;
    int displayTypeChoice; //to display all categories, raw categories or fresh etc
    
	int numberOfLines;

	int fstreamCategory;
	string fstreamName;
	int fstreamCode;
	long long fstreamDate;

    //intialize for adding new item
    int categoryX = 0;
    string productX = "NULL";
    int productCodeX = 0;
	long long dateX = 0;

	//program starts here
    auto futureX = async(&dateRegister::updateDate, &datesData); //date running in background
    auto calculation = async(&dateRegister::dayMainCalculator, &datesData); //counting number of days from Year 2000 in background
    
	ifstream inFile;
	inFile.open("FSTREAM DSA GROUP WORK V1.4A");

	lineCount(numberOfLines);

	for (int i = 1; i <= numberOfLines; i++)
	{
		inFile >> fstreamCategory >> fstreamName >> fstreamCode >> fstreamDate;

		productDetail.category = fstreamCategory;
		productDetail.product = fstreamName;
		productDetail.productCode = fstreamCode;
		productDetail.productDate = fstreamDate;

		allCategories.push(productDetail);

		switch (fstreamCategory) //individually pushing into food type
		{
			case 1:
			{
				//for raw
				raw.push(productDetail);
				break;
			}
			case 2:
			{
				//for fresh
				fresh.push(productDetail);
				break;
			}
			case 3:
			{
				//for precooked
				precooked.push(productDetail);
				break;
			}
			default:
			{
				cout << "[WARNING]: FSTREAM CATEGORY INPUT ERROR" << endl;
				break;
			}
		}
	}
	inFile.close();

    displayProgramKeepsTrack();
    displayChoice();
    cin >> functionChoice;
    
    while (functionChoice != 0)
    {
        switch (functionChoice)
        {
            case 1: //add function
            {
				ofstream outFile;
				outFile.open("FSTREAM DSA GROUP WORK V1.4A", std::ios_base::app);

                system("cls"); //clear console
                addNewItem(categoryX, productX, productCodeX, dateX);
                
                productDetail.category = categoryX;
                productDetail.product = productX;
                productDetail.productCode = productCodeX;
				productDetail.productDate = dateX;
                
                allCategories.push(productDetail); //pushing into queue of all categories

				outFile << categoryX << " " << productX << " " << productCodeX << " " << dateX << endl;
				outFile.close();
                
                switch (categoryX) //individually pushing into food type
                {
                    case 1:
                    {
                        //for raw
                        raw.push(productDetail);
                        break;
                    }
                    case 2:
                    {
                        //for fresh
                        fresh.push(productDetail);
                        break;
                    }
                    case 3:
                    {
                        //for precooked
                        precooked.push(productDetail);
                        break;
                    }
                    default:
                    {
                        cout << "[WARNING]: SWITCH QUEUE CATEGORY ERROR" << endl;
                        break;
                    }
                }
                
                //testing to check number of items, see if items are registered and pushed into queue
				system("cls");
                cout << "\nTotal number of itmes = " << allCategories.size() << endl;
                cout << "Total number of items in Raw = " << raw.size() << endl;
                cout << "Total number of items in Fresh = " << fresh.size() << endl;
                cout << "Total number of items in Precooked = " << precooked.size() << endl;
                
                break;
            }
            case 2: //delete function
            {
				cout << "[ERROR]: DELETE NOT IMPLENTED; FUNCTION DELETE STILL IN PROGRESS";

				queue<item> displayDeleteCopy = allCategories;
				sizeToDisplay = static_cast<int>(displayDeleteCopy.size()); //for loop

				for (int i = sizeToDisplay; i > 0; i--)
				{
					productDetail = displayDeleteCopy.front();

					cout << "\nCategory: ";
					switch (productDetail.category)
					{
					case 1:
					{
						cout << "Raw" << endl;
						break;
					}
					case 2:
					{
						cout << "Fresh" << endl;
						break;
					}
					case 3:
					{
						cout << "Pre-Cooked" << endl;
						break;
					}
					}
					cout << "Name: " << productDetail.product << endl;
					cout << "Code: " << productDetail.productCode << endl;
					cout << "Expiry Date: " << productDetail.productDate << endl;

					displayCopy.pop();
				}
				displayDelete();

                break;
            }
            case 3: //display
            {
				system("cls");
                displayOption();
                cin >> displayTypeChoice;
                
                switch (displayTypeChoice)
                {
                    case 1: //for all items
                    {
                        queue<item> displayCopy = allCategories;
                        sizeToDisplay = static_cast<int>(displayCopy.size()); //for loop
                        
                        for (int i = sizeToDisplay; i > 0; i--)
                        {
							productDetail = displayCopy.front();
                            
                            cout << "\nCategory: ";
                            switch (productDetail.category)
                            {
                                case 1:
                                {
                                    cout << "Raw" << endl;
                                    break;
                                }
                                case 2:
                                {
                                    cout << "Fresh" << endl;
                                    break;
                                }
                                case 3:
                                {
                                    cout << "Pre-Cooked" << endl;
                                    break;
                                }
                            }
                            cout << "Name: " << productDetail.product << endl;
                            cout << "Code: " << productDetail.productCode << endl;
							cout << "Expiry Date: " << productDetail.productDate << endl;
                                    
                            displayCopy.pop();
                        }
                        break;
                    }
                    case 2: //for raw items
                    {
                        queue<item> displayCopy = raw;
                        sizeToDisplay = static_cast<int>(displayCopy.size());
                            
                        for (int i = sizeToDisplay; i > 0; i--)
                        {
                            productDetail = displayCopy.front();
                            
                            cout << "\nCategory: Raw" << endl;
                            cout << "Name: " << productDetail.product << endl;
							cout << "Code: " << productDetail.productCode << endl;
							cout << "Expiry Date: " << productDetail.productDate << endl;
                            
                            displayCopy.pop();
                        }
                        break;
                    }
                    case 3: //for fresh items
                    {
                        queue<item> displayCopy = fresh;
                        sizeToDisplay = static_cast<int>(displayCopy.size());
                        
                        for (int i = sizeToDisplay; i > 0; i--)
                        {
                            productDetail = displayCopy.front();
                            
                            cout << "\nCategory: Fresh" << endl;
                            cout << "Name: " << productDetail.product << endl;
                            cout << "Code: " << productDetail.productCode << endl;
							cout << "Expiry Date: " << productDetail.productDate << endl;
                            
                            displayCopy.pop();
                        }
                        break;
                    }
                    case 4: //for precooked items
                    {
                        queue<item> displayCopy = precooked;
                        sizeToDisplay = static_cast<int>(displayCopy.size());
                        
                        for (int i = sizeToDisplay; i > 0; i--)
                        {
                            productDetail = displayCopy.front();
                            
                            cout << "\nCategory: Pre-Cooked" << endl;
                            cout << "Name: " << productDetail.product << endl;
                            cout << "Code: " << productDetail.productCode << endl;
							cout << "Expiry Date: " << productDetail.productDate << endl;
                            
                            displayCopy.pop();
                        }
                        break;
                    }
                    default:
                    {
                        cout << "[WARNING]: SWITCH DISPLAY TYPE ERROR" << endl;
                        break;
                    }
                }
				inFile.close();
                break;
            }
            default:
            {
                cout << "[ERROR]: Enter choice again" << endl;
                break;
            }
        }
        displayNewMenu();
        displayChoice();
        cin >> functionChoice;
    }
}
