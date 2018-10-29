#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <chrono>
#include <future>
#include <ctime>

#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"

#include "displayfunctions.hpp"
#include "display.hpp"
#include "functions.hpp"
#include "timer.hpp"
#include "items.hpp"

int main() {
	//class declarations
	item productDetail;
	dateRegister datesData;

	//queue declarations
	std::queue<item> allCategories;
	std::queue<item> displayCopy;
	std::queue<item> displayDeleteCopy;
	std::queue<item> rawList;
	std::queue<item> freshList;
	std::queue<item> precookedList;

	//declarations of variables
	int sizeToDisplay; //to count the number of times to loop
	int numberOfLines;
	int functionChoice; //for choices to add, delete or display
	int displayTypeChoice; //to display all items, raw or precooked
	int codeToDelete; //for user to enter code to delete

	//delcarations for fstream
	int fstreamCategory;
	std::string fstreamName;
	int fstreamCode;
	//long long fstreamDate; //change this
	int fstreamDateDay;
	int fstreamDateMonth;
	int fstreamDateYear;

	//initialization when adding new item
	int categoryX = 0;
	std::string productX = "NULL";
	int productCodeX = 0;
	//long long dateX = 0;
	int dateDayX = 0;
	int dateMonthX = 0;
	int dateYearX = 0;

	displayProgramKeepsTrack();
	std::cout << "LOADING: " << std::endl;
	std::cout << "Version: V1.11A" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "\nAuto-Detecing Date..." << std::endl;
	std::cout << "Auto-Detecing Time..." << std::endl;

	//functions to run in the background
	auto getDate = std::async(&dateRegister::updateDate, &datesData); //getting date in the background
	auto dayCalculation = std::async(&dateRegister::dayMainCalculator, &datesData); //count number of days since year 2000 in the background
	std::this_thread::sleep_for(std::chrono::seconds(1));

	lineCount(numberOfLines); //copying existing data into queue
	std::ifstream getData;
	//getData.open("V1.2B", std::fstream::in | std::fstream::out | std::fstream::app);
	getData.open("V2.1C", std::ios::_Noreplace); //use this for windows

												 //cout << "Number of lines = " << numberOfLines << endl; //for debugging
	for (int i = 1; i <= numberOfLines; i++) {
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
	std::cout << "AUTO-DETECTION COMPLETED" << std::endl << std::endl;
	std::cout << "Initializing Data..." << std::endl;
	std::cout << "INITIALIZATION COMPLETED" << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(2));
	auto dayWarning = std::async(&dateRegister::dayAlarm, &datesData); //to give warning when expiry date is close

	window_rs window;
	window.onCreate(1280, 720, "KitchenManagementX");
	ImGui_ImplGlfw_Init(window, false);

	while (window) {
		ImGui_ImplGlfw_NewFrame(1);

		ImGui::Begin("Hello");
		ImGui::Separator();
		ImGui::Text("-------STREAM-------");
		ImGui::End();
		ImGui::Render();
	}

	//start of program
	system("cls");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	displayChoice();
	std::cin >> functionChoice;

	while (functionChoice != 0) {
		switch (functionChoice) {
			//function to add item
		case 1: {
			system("cls");
			addNewItem(categoryX, productX, productCodeX, dateDayX, dateMonthX, dateYearX);

			productDetail.category = categoryX;
			productDetail.product = productX;
			productDetail.productCode = productCodeX;
			productDetail.dateDay = dateDayX;
			productDetail.dateMonth = dateMonthX;
			productDetail.dateYear = dateYearX;

			allCategories.push(productDetail);

			std::cout << "\nTotal number of items = " << allCategories.size() << std::endl;
			break;
		}
				//function to delete item
		case 2: {
			system("cls");
			//to display current items
			std::queue<item> displayCopy = allCategories;
			sizeToDisplay = static_cast<int>(displayCopy.size());

			for (int i = 1; i <= sizeToDisplay; i++) {
				productDetail = displayCopy.front();

				std::cout << "\nCategory: ";
				switch (productDetail.category) {
				case 1:
					std::cout << "Raw" << std::endl;
					break;
				case 2:
					std::cout << "Fresh" << std::endl;
					break;
				case 3:
					std::cout << "Pre-Cooked" << std::endl;
					break;
				}
				std::cout << "Name: " << productDetail.product << std::endl;
				std::cout << "Code: " << productDetail.productCode << std::endl;
				std::cout << "Expiry Date: " << productDetail.dateDay << "-" << productDetail.dateMonth << "-" << productDetail.dateYear << std::endl;

				displayCopy.pop();
			}

			//to delete item and copy into a queue
			std::queue<item> displayDeleteCopy = allCategories;
			for (int i = 1; i <= sizeToDisplay; i++) {
				allCategories.pop();
			}

			sizeToDisplay = static_cast<int>(displayDeleteCopy.size());
			displayDelete();
			std::cin >> codeToDelete;

			for (int i = 1; i <= sizeToDisplay; i++) { //for (int i = 0; i < sizeToDisplay; i++)
				productDetail = displayDeleteCopy.front();

				if (productDetail.productCode != codeToDelete) {
					allCategories.push(productDetail);
					switch (productDetail.category) {
					case 1:
						rawList.push(productDetail);
						break;
					case 2:
						freshList.push(productDetail);
						break;
					case 3:
						precookedList.push(productDetail);
						break;
					}
					displayDeleteCopy.pop();
				}
				else if (productDetail.productCode == codeToDelete) {
					std::cout << "Data has been deleted" << std::endl << std::endl;
					displayDeleteCopy.pop();
				}
			}

			if (rawList.size() == 0) {
				std::cout << "NO RAW ITEMS REMAINING" << std::endl;
			}
			if (freshList.size() == 0) {
				std::cout << "NO FRESH ITEMS REMAINING" << std::endl;
			}
			if (precookedList.size() == 0) {
				std::cout << "NO PRE-COOKED ITEMS REMAINING" << std::endl;
			}
			break;
		}
				//function to display items
		case 3: {
			system("cls");
			displayOption();
			std::cin >> displayTypeChoice;

			switch (displayTypeChoice) {
				//to display all items in raw, precooked and fresh
			case 1: {
				std::queue<item> displayCopy = allCategories;
				sizeToDisplay = static_cast<int>(displayCopy.size());

				for (int i = 1; i <= sizeToDisplay; i++) {
					productDetail = displayCopy.front();

					std::cout << "\nCategory: ";
					switch (productDetail.category) {
					case 1:
						std::cout << "Raw" << std::endl;
						break;
					case 2:
						std::cout << "Fresh" << std::endl;
						break;
					case 3:
						std::cout << "Pre-Cooked" << std::endl;
						break;
					}
					std::cout << "Name: " << productDetail.product << std::endl;
					std::cout << "Code: " << productDetail.productCode << std::endl;
					std::cout << "Expiry Date: " << productDetail.dateDay << "-" << productDetail.dateMonth << "-" << productDetail.dateYear << std::endl;

					displayCopy.pop();
				}
				break;
			}
					//to display raw items
			case 2: {
				std::queue<item> displayCopy = allCategories;
				sizeToDisplay = static_cast<int>(displayCopy.size());

				for (int i = 1; i <= sizeToDisplay; i++) {
					productDetail = displayCopy.front();

					if ((productDetail.category) == 1) {
						std::cout << "\nCategory: Raw" << std::endl;
						std::cout << "Name: " << productDetail.product << std::endl;
						std::cout << "Code: " << productDetail.productCode << std::endl;
						std::cout << "Expiry Date: " << productDetail.dateDay << "-" << productDetail.dateMonth << "-" << productDetail.dateYear << std::endl;
					}
					displayCopy.pop();
				}
				break;
			}
					//to display fresh items
			case 3: {
				std::queue<item> displayCopy = allCategories;
				sizeToDisplay = static_cast<int>(displayCopy.size());

				for (int i = 1; i <= sizeToDisplay; i++) {
					productDetail = displayCopy.front();

					if ((productDetail.category) == 2) {
						std::cout << "\nCategory: Fresh" << std::endl;
						std::cout << "Name: " << productDetail.product << std::endl;
						std::cout << "Code: " << productDetail.productCode << std::endl;
						std::cout << "Expiry Date: " << productDetail.dateDay << "-" << productDetail.dateMonth << "-" << productDetail.dateYear << std::endl;
					}
					displayCopy.pop();
				}
				break;
			}
					//to display precooked items
			case 4: {
				std::queue<item> displayCopy = allCategories;
				sizeToDisplay = static_cast<int>(displayCopy.size());

				for (int i = 1; i <= sizeToDisplay; i++) {
					productDetail = displayCopy.front();

					if ((productDetail.category) == 3) {
						std::cout << "\nCategory: Pre-Cooked" << std::endl;
						std::cout << "Name: " << productDetail.product << std::endl;
						std::cout << "Code: " << productDetail.productCode << std::endl;
						std::cout << "Expiry Date: " << productDetail.dateDay << "-" << productDetail.dateMonth << "-" << productDetail.dateYear << std::endl;
					}
					displayCopy.pop();
				}
				break;
			}
			default:
				std::cout << "[WARNING]: SWITCH DISPLAY TYPE ERROR" << std::endl;
				break;
			}
		}
		}
		std::ofstream writeData;
		writeData.open("V2.1C");
		std::queue<item> displayCopy = allCategories;
		sizeToDisplay = static_cast<int>(displayCopy.size());

		for (int i = 1; i <= sizeToDisplay; i++) {
			productDetail = displayCopy.front();

			fstreamCategory = productDetail.category;
			fstreamName = productDetail.product;
			fstreamCode = productDetail.productCode;
			fstreamDateDay = productDetail.dateDay;
			fstreamDateMonth = productDetail.dateMonth;
			fstreamDateYear = productDetail.dateYear;

			writeData << fstreamCategory << " " << fstreamName << " " << fstreamCode << " " << fstreamDateDay << " " << fstreamDateMonth << " " << fstreamDateYear << std::endl;

			displayCopy.pop();
		}
		writeData.close();

		sizeToDisplay = static_cast<int>(rawList.size());
		for (int i = 1; i <= sizeToDisplay; i++) {
			rawList.pop();
		}

		sizeToDisplay = static_cast<int>(freshList.size());
		for (int i = 1; i <= sizeToDisplay; i++) {
			freshList.pop();
		}

		sizeToDisplay = static_cast<int>(precookedList.size());
		for (int i = 1; i <= sizeToDisplay; i++) {
			precookedList.pop();
		}

		displayNewMenu();
		displayChoice();
		std::cin >> functionChoice;
	}
}
