#pragma once
using namespace std;

void addNewItem(int& categoryX, string& productX, int& productCodeX, float& productPriceX)
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
    
    cout << "Enter Product Price: $";
    cin >> productPriceX;
}
