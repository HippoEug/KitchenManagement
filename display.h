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
	cout << "Press [1] to add a new item" << endl;
	cout << "Press [2] to delete an existing item" << endl;
	cout << "Press [3] to display items in inventory" << endl;
	cout << "Press [0] to exit" << endl;
	cout << "Choice: ";
}

void displayNewMenu()
{
	cout << "\n==============================" << endl;
	cout << "          NEW MENU";
	cout << "\n==============================" << endl;
}
