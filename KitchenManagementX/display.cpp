#include <iostream>

#include "display.hpp"

void displayProgramKeepsTrack() {
	std::cout << "==============================================" << std::endl;
	std::cout << "Program keeps track of items in your inventory" << std::endl;
	std::cout << "==============================================" << std::endl << std::endl;
}

void displayChoice() {
	std::cout << "Press [1]: Add a new item" << std::endl;
	std::cout << "Press [2]: Delete an existing item" << std::endl;
	std::cout << "Press [3]: Display items in inventory" << std::endl;
	std::cout << "Press [0]: Exit" << std::endl;
	std::cout << "Choice: ";
}

void displayNewMenu() {
	std::cout << "\n==============================" << std::endl;
	std::cout << "          NEW MENU";
	std::cout << "\n==============================" << std::endl;
}

void displayOption() {
	std::cout << "\nEnter Food Category Type to Display" << std::endl;
	std::cout << "Press [1]: All items" << std::endl;
	std::cout << "Press [2]: Raw items" << std::endl;
	std::cout << "Press [3]: Fresh items" << std::endl;
	std::cout << "Press [4]: Precooked items" << std::endl;
	std::cout << "Choice: ";
}

void displayDelete() {
	std::cout << "\nEnter the Item's Product Code to Delete" << std::endl;
	std::cout << "Product Code: ";
}
