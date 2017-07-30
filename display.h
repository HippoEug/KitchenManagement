#pragma once
#include <iostream>
using namespace std;

void displayProgramKeepsTrack()
{
	cout << "==============================================" << endl;
	cout << "Program keeps track of items in your inventory" << endl;
	cout << "==============================================" << endl << endl;
}

void displayChoice()
{
	cout << "Press [1]: Add a new item" << endl;
	cout << "Press [2]: Delete an existing item" << endl;
	cout << "Press [3]: Display items in inventory" << endl;
	cout << "Press [0]: Exit" << endl;
	cout << "Choice: ";
}

void displayNewMenu()
{
	cout << "\n==============================" << endl;
	cout << "          NEW MENU";
	cout << "\n==============================" << endl;
}

void displayOption()
{
	cout << "\nEnter Food Category Type to Display" << endl;
	cout << "Press [1]: All items" << endl;
	cout << "Press [2]: Raw items" << endl;
	cout << "Press [3]: Fresh items" << endl;
	cout << "Press [4]: Precooked items" << endl;
	cout << "Choice: ";
}
