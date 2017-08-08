Source Code Documentation: (8 Aug 2017) 
The purpose of the source code documentation is to enable the succeeding programmers able to have a clear understanding on the inner working of the software at a glance. The document should contain all functions that were coded, brief description on the purpose of the function, variables used by the function and also any global variables declared in the software. You are free to use any available libraries, but you must explain what it is and what you are using the library for. Operating environment, such as the hardware platform, the type of development environment and the running environment should brief stated.

#include STL header file that allows input and output streams.

#include STL header file that allows string variables to be explicitly used.

#include STL header file that allows input and output with file streams.

#include STL header file that allows queue container adaptor to be used, operating in a FIFO (first-in first-out) context.

#include STL header file that defines three main types (durations, clocks and time points) as well as utility functions and common type defines.

#include STL header file that supports running functions in separate threads.

#include STL header file that returns current calendar time and converts it to a C-string containing corresponding time and date.

#include "display.h" Header file which contains functions to display various menus and function choices.

#include "functions.h" Header file which contains functions to add new items, and also count the number of items in a particular fstream file.

#include "timer.h" Header file which contains a class which stores variables for time and days, and also functions to get system time, count the number of days from year 2000 and compare with various datas.

#include "items.h" Header file which contains a class which stores variables for the details of the item, including product category, product name, product code and the expiry date of the product.

using namespace std; Declaration introduces a container for a set of identifiers, and eliminates the need to also type the std:: prefix constantly.

item productDetail; dateRegister datesData; Creates an instance of productDetail from class item, and also an instance of datesData from class dateRegister.

queue allCategories; queue displayCopy; queue displayDeleteCopy; Creates a queue with a member type definition of class item, and a name of allCategories, where allCategories pushes the instance of an item into the queue. The queues displayCopy and displayDeleteCopy is a direct copy of allCategories, used when calling for functions to display and delete items.

int sizeToDisplay; int numberOfLines; Declares two integers, sizeToDisplay and numberOfLines. Their purpose is to know the total number of items, so the correct number of loops can be executed for various functions.

int functionChoice; int displayTypeChoice; Declares two integers, functionChoice and displayTypeChoice. Their purpose is to store the input data from the user, and use it for switch statements to enable the corresponding functions.

int codeToDelete; Declares an integer, codeToDelete. It stores the input data from user and matches it with existing in the data in the queue to execute the delete function.

int fstreamCategory; string fstreamName; int fstreamCode; int fstreamDateDay; int fstreamDateMonth; int fstreamDateYear; Declares five integers to store the category, code and expiry date of item, and a string to store the name of the item. Variables are designed for fstream.

int categoryX = 0; string productX = "NULL"; int productCodeX = 0; int dateDayX = 0; int dateMonthX = 0; int dateYearX = 0; Declares five integers to store the category, code and expiry date of item, and a string to store the name of the item. All variables are initialized to 0 and NULL. Variables are designed for addNewItem function.

system("cls"); Call to clear system console, a function of STL.

displayProgramKeepsTrack(); displayChoice(); Function calls displayProgramKeepsTrack and displayChoice() shows the user the different options for different functions.

this_thread::sleep_for(chrono::seconds(1)); Function using to call for a thread, and using chrono function to delay for 1 second. Variables (seconds, minutes, hours) can be changed.

auto getDate = async(&dateRegister::updateDate, &datesData); auto dayCalculation = async(&dateRegister::dayMainCalculator, &datesData); auto dayWarning = async(&dateRegister::dayAlarm, &datesData); Function calls getDate, dayCalculation and dayWarning

lineCount(numberOfLines);

ifstream getData; getData.open("V2.1C", std::ios::_Noreplace); getData.close();

ofstream writeData; writeData.open("V2.1C"); writeData.close();

getData >> fstreamCategory >> fstreamName >> fstreamCode >> fstreamDateDay >> fstreamDateMonth >> fstreamDateYear;

writeData << fstreamCategory << " " << fstreamName << " " << fstreamCode << " " << fstreamDateDay << " " << fstreamDateMonth << " " << fstreamDateyear << endl;

productDetail.category productDetail.product productDetail.productCode productDetail.dateDay productDetail.dateMonth productDetail.dateYear

productDetail.category = fstreamCategory; productDetail.product = fstreamName; productDetail.productCode = fstreamCode; productDetail.dateDay = fstreamDateDay; productDetail.dateMonth = fstreamDateMonth; productDetail.dateYear = fstreamDateYear;

productDetail.category = categoryX; productDetail.product = productX; productDetail.productCode = productCodeX; productdetail.dateDay = dateDayX; productDetail.dateMonth = dateMonthX; productDetail.dateYear = dateYearX;

fstreamCategory = productDetail.category; fstreamName = productDetail.product; fstreamCode = productDetail.productCode; fstreamDateDay = productDetail.dateDay; fstreamDateMonth = productDetail.dateMonth; fstreamDateYear = productDetail.dateYear;

productDetail = displayCopy.front(); productDetail = displayDeleteCopy.front();

allCategories.push(productDetail);

allCategories.size();

allCategories.pop(); displayCopy.pop(); displayDeleteCopy.pop();

sizeToDisplay = static_cast(displayCopy.size()); sizeToDisplay = static_cast(displayDeleteCopy.size());

addNewItem(categoryX, productX, productCodeX, dateDayX, dateMonthX, dateYearX);

queue displayCopy = allCategories; queue displayDeleteCopy = allCategories;
