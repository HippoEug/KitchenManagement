//
//  main.cpp
//  DSA GROUP WORK
//
//  Created by HippoEug on 5/7/17.
//  Copyright © 2017 HippoEug. All rights reserved.
//

//
//Catogories: Raw; Fresh; Precooked(Can);
//
//Functions: Add, delete, warning
//
//Things to add: Expiry System, Some counting for loops, and delete item function
//
//Change >>cin<< as writing eg string to int will cause program to crash
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include "items.h"
#include "display.h"
#include "functions.h"
using namespace std;

//declaration of functions
void displayProgramKeepsTrack();
void displayChoice();
void displayNewMenu();
void displayOption();

void addNewItem(int& categoryX, string& productX, int& productCodeX, float& productPriceX);

//main program here
int main()
{
    //declaring queue
    
    queue<item> allCategories;
    queue<item> raw;
    queue<item> fresh;
    queue<item> precooked;
    
    queue<item> allCategoriesCopy;
    queue<item> rawCopy;
    queue<item> freshCopy;
    queue<item> precookedCopy;
    
    item productDetail;
    
    int i; //generic calculation type for display loop
    int sizeToDisplay; //for display function
    
    //declaration + initialization
    int functionChoice;
    int displayTypeChoice; //to display all categories, raw categories or fresh etc
    
    int categoryX = 0;
    string productX = "NULL";
    int productCodeX = 0;
    float productPriceX = 0;
    
    displayProgramKeepsTrack();
    displayChoice();
    cin >> functionChoice;
    
    while (functionChoice != 0)
    {
        switch (functionChoice)
        {
            case 1:
            {
                //system("cls"); //clear console
                addNewItem(categoryX, productX, productCodeX, productPriceX);
                
                productDetail.category = categoryX;
                productDetail.product = productX;
                productDetail.productCode = productCodeX;
                productDetail.productPrice = productPriceX;
                allCategories.push(productDetail);
                
                switch (categoryX)
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
                cout << "\nTotal number of itmes = " << allCategories.size() << endl;
                cout << "Total number of items in Raw = " << raw.size() << endl;
                cout << "Total number of items in Fresh = " << fresh.size() << endl;
                cout << "Total number of items in Precooked = " << precooked.size() << endl;
                
                break;
            }
            case 2:
            {
                cout << "[ERROR]: DELETE NOT IMPLENTED";
                break;
            }
            case 3: //display
            {
                displayOption();
                cin >> displayTypeChoice;
                
                queue<item> allCategoriesCopy = allCategories;
                
                sizeToDisplay = static_cast<int>(allCategoriesCopy.size());
                
                switch (displayTypeChoice)
                {
                    case 1: //for all items
                    {
                        //
                        
                        for (i = sizeToDisplay; i > 0; i--)
                        {
                            productDetail = allCategoriesCopy.front();
                            
                            cout << productDetail.category << endl;
                            cout << productDetail.product << endl;
                            cout << productDetail.productCode << endl;
                            cout << productDetail.productPrice << endl;
                            
                            allCategoriesCopy.pop();
                            
                            //cout << "\nSize now = " << allCategoriesCopy.size() << endl << "i = " << i << endl; //debugging
                        }
                        break;
                    }
                    case 2: //for raw items
                    {
                        for (i = 1; i <= (raw.size() + 1); i++)
                        {
                            productDetail = raw.front();
                            
                            //cout << "Element at the top of the stack is: " << endl;
                            cout << productDetail.category << endl;
                            cout << productDetail.product << endl;
                            cout << productDetail.productCode << endl;
                            cout << productDetail.productPrice << endl;
                            
                            raw.pop();
                        }
                        break;
                    }
                    case 3: //for fresh items
                    {
                        for (i = 1; i <= (fresh.size() + 1); i++)
                        {
                            productDetail = fresh.front();
                            
                            //cout << "Element at the top of the stack is: " << endl;
                            cout << productDetail.category << endl;
                            cout << productDetail.product << endl;
                            cout << productDetail.productCode << endl;
                            cout << productDetail.productPrice << endl;
                            
                            fresh.pop();
                        }
                        break;
                    }
                    case 4: //for precooked items
                    {
                        for (i = 1; i <= (precooked.size() + 1); i++)
                        {
                            productDetail = precooked.front();
                            
                            //cout << "Element at the top of the stack is: " << endl;
                            cout << productDetail.category << endl;
                            cout << productDetail.product << endl;
                            cout << productDetail.productCode << endl;
                            cout << productDetail.productPrice << endl;
                            
                            precooked.pop();
                        }
                        break;
                    }
                    default:
                    {
                        cout << "[WARNING]: SWITCH DISPLAY TYPE ERROR" << endl;
                        break;
                    }
                }
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
