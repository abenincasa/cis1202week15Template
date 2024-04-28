///*****************************
/// Personal Library File
///1.0 - Introduced.
/// 
/// 1.1 -
/// -Added getFloat and holdFloat
/// -Added getDouble and holdDouble
/// -Simplified exit function names
/// -Removed ignore()
/// 
/// 1.1.1 -
/// -Added isVowel
/// 
/// 1.1.2 -
/// -Added getRandom
/// 
/// 1.1.3 -
/// -Added [vector] and [fstream]
/// 
/// 1.2
/// -Removed all hold functions
/// -Converted all get functions to a single overloaded function
/// -Fixed some typing errors in all get functions.
/// 
/// Added searchLinear
/// Added searchBinary
/// 
/// Added 1 sortSelection command. 
/// 
/// 1.2.1
/// 
/// Added sortSelection in float and vector^int^

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

#pragma region DISPLAY FUNCTIONS


//begin a VOID function (non value returning)

/*
*  Clears the screen
*  VOID
*  No arguments
*/

void cls() //method header/signature - describes in/out of the function
{
	//cout << string(35, '\n'); // sends 35 \n to the output
	system("CLS");//call an Operating System command :(

}


/*
*  ends the program and clears the buffer
*  returns integer to close program
*/
int endProg() {
	cout << "\n\n*****************\n\nCopyright 2024, anthony.benincasa@sinclair.edu, All Rights Reserved\n\nPress any key to continue.....";
	cin.ignore(100, '\n');
	cin.get();
	return 0;
}

/*
*  Adds formatted title to top of page
*  VOID
*  receives string argument
*/
void title(string title) {
	int num = 0;
	num = 65 - title.length() / 2;

	for (int x = 1; x < num; x++) {
		cout << " ";
	}
	cout << title << endl;

	cout << string(80, '-');

	cout << "\n\n";

}

/*
* Center String
* Receives a string prompt
*/

void centerString(string prompt) {
	int num = 0;
	num = 65 - prompt.length() / 2;

	for (int x = 1; x < num; x++) {
		cout << " ";
	}
	cout << prompt << "\n\n";
}

int validateYesNo(string prompt) {
	char num = 0;
	cout << prompt;
	cin >> num;
	while (num != 'y' && num != 'n' && num != 'Y' && num != 'n') {
		cout << "Error - try again.  ";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << prompt;

	}
	return tolower(num);
}
/**********************************
* Gets an integer value from the user.
************************************/
void get(int& input, string desc) {
	cout << desc;
	while (!(cin >> input) || cin.fail()) {
		cout << "ERROR: Please enter an integer.\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}


/**********************************************************
* Gets an integer value from the user between 'min' and 'max'
*
* NOTE: Description is required, unlike the simpler version.
**********************************************************/
void get(int& input, int min, int max, string desc) {
	cout << desc;
	while (!(cin >> input) || cin.fail() || input < min || input > max) {
		cout << "ERROR: Please enter an integer between " << min << " and " << max << ".\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}


/***********************************************************
* Gets a floating-point value from the user.
************************************************************/
void get(float& input, string desc) {
	cout << desc;
	while (!(cin >> input) || cin.fail()) {
		cout << "ERROR: Please enter a floating-point number.\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}


/******************************************************************
* Gets a floating point value from the user between 'min' and 'max'
*******************************************************************/

void get(float& input, float min, float max, string desc) {
	cout << desc;
	while (!(cin >> input) || cin.fail() || input < min || input > max) {
		cout << "ERROR: Please enter a floating-point number between " << min << " and " << max << ".\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}



/***********************************************************
* Gets a double value from the user.
************************************************************/
void get(double& input, string desc) {
	cout << desc;
	while (!(cin >> input) || cin.fail()) {
		cout << "ERROR: Please enter a double.\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}




/******************************************************************
* Gets a double value from the user between 'min' and 'max'
*******************************************************************/

void get(double& input, double min, double max, string desc) {
	cout << desc;
	while (!(cin >> input) || cin.fail() || input < min || input > max) {
		cout << "ERROR: Please enter a double between " << min << " and " << max << ".\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}




/*********************************
* Gets a file name from the user.
********************************/
string getFile() {
	string directory;
	string fileName;

	cout << "Please enter directory:";
	getline(cin, directory);
	cout << "Please enter file name:";
	getline(cin, fileName);

	return (directory + '\\' + fileName + ".txt");
}



/**************************************
* Gets a random number between min and max.
************************************/

int getRandom(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}




/*************************************
* Checks to see if a character is a vowel.
**************************************/

bool isVowel(char character) {
	if (tolower(character) == 'a' || tolower(character) == 'e' || tolower(character) == 'i' || tolower(character) == 'o' || tolower(character) == 'u' || tolower(character) == 'y')
		return true;
	else
		return false;

}





/*****************************
* Exits the progam .
******************************/
void leave() {
	cout << "\nPress any key to continue...\n";
	cin.get();
	exit(0);
}




/*****************************
* All forms of searchLinear:
* look for an instance of value in the program.
* Inefficient, unless values aren't unique/sorted.
****************************/

void searchLinear(const int list[], int size, int value, vector<int>& elementNums) {
	int index = 0;
	while (index < size) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}

void searchLinear(const float list[], int size, float value, vector<int>& elementNums) {
	int index = 0;
	while (index < size) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}

void searchLinear(const double list[], int size, double value, vector<int>& elementNums) {
	int index = 0;
	while (index < size) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}

void searchLinear(const vector<int> list, int value, vector<int>& elementNums) {
	int index = 0;
	while (index < list.size()) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}

void searchLinear(const vector<float> list, float value, vector<int>& elementNums) {
	int index = 0;
	while (index < list.size()) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}

void searchLinear(const vector<double> list, double value, vector<int>& elementNums) {
	int index = 0;
	while (index < list.size()) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}



/****************************
* All forms of searchBinary:
* Look for an instance of value in the program.
* Efficient, but only usable on unique, sorted arrays.
****************************/

int searchBinary(const int list[], int size, int value, bool isAscending) {
	int start = 0;
	int end = size - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}

int searchBinary(const float list[], int size, float value, bool isAscending) {
	int start = 0;
	int end = size - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}

int searchBinary(const double list[], int size, double value, bool isAscending) {
	int start = 0;
	int end = size - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}

int searchBinary(const vector<int> list, int value, bool isAscending) {
	int start = 0;
	int end = list.size() - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}

int searchBinary(const vector<float> list, float value, bool isAscending) {
	int start = 0;
	int end = list.size() - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}

int searchBinary(const vector<double> list, double value, bool isAscending) {
	int start = 0;
	int end = list.size() - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}


/*******************************
* All forms of sortSelection:
* Sort the given array/vector in ascending/descending order.
******************************/

void sortSelection(int list[], int size, bool isAscending) {
	if (isAscending) {
		int startScan;
		int minIndex;
		float minValue;
		for (startScan = 0; startScan < size - 1; startScan++) {
			minIndex = startScan;
			minValue = list[startScan];
			for (int i = startScan + 1; i < size; i++) {
				if (list[i] < minValue) {
					minIndex = i;
					minValue = list[i];
				}
			}
			list[minIndex] = list[startScan];
			list[startScan] = minValue;
		}
	}
	else {
		int startScan;
		int maxIndex;
		float maxValue;
		for (startScan = 0; startScan < size - 1; startScan++) {
			maxIndex = startScan;
			maxValue = list[startScan];
			for (int i = startScan + 1; i < size; i++) {
				if (list[i] > maxValue) {
					maxIndex = i;
					maxValue = list[i];
				}
			}
			list[maxIndex] = list[startScan];
			list[startScan] = maxValue;
		}
	}
}

void sortSelection(float list[], int size, bool isAscending) {
	if (isAscending) {
		int startScan;
		int minIndex;
		float minValue;
		for (startScan = 0; startScan < size - 1; startScan++) {
			minIndex = startScan;
			minValue = list[startScan];
			for (int i = startScan + 1; i < size; i++) {
				if (list[i] < minValue) {
					minIndex = i;
					minValue = list[i];
				}
			}
			list[minIndex] = list[startScan];
			list[startScan] = minValue;
		}
	}
	else {
		int startScan;
		int maxIndex;
		float maxValue;
		for (startScan = 0; startScan < size - 1; startScan++) {
			maxIndex = startScan;
			maxValue = list[startScan];
			for (int i = startScan + 1; i < size; i++) {
				if (list[i] > maxValue) {
					maxIndex = i;
					maxValue = list[i];
				}
			}
			list[maxIndex] = list[startScan];
			list[startScan] = maxValue;
		}
	}
}

void sortSelection(vector<int> list, bool isAscending) {
	if (isAscending) {
		int startScan;
		int minIndex;
		float minValue;
		for (startScan = 0; startScan < list.size() - 1; startScan++) {
			minIndex = startScan;
			minValue = list[startScan];
			for (int i = startScan + 1; i < list.size(); i++) {
				if (list[i] < minValue) {
					minIndex = i;
					minValue = list[i];
				}
			}
			list[minIndex] = list[startScan];
			list[startScan] = minValue;
		}
	}
	else {
		int startScan;
		int maxIndex;
		float maxValue;
		for (startScan = 0; startScan < list.size() - 1; startScan++) {
			maxIndex = startScan;
			maxValue = list[startScan];
			for (int i = startScan + 1; i < list.size(); i++) {
				if (list[i] > maxValue) {
					maxIndex = i;
					maxValue = list[i];
				}
			}
			list[maxIndex] = list[startScan];
			list[startScan] = maxValue;
		}
	}
}


void fill(char prev) {
	cout.fill(prev);
}
void fill(char prev, int num) {
	cout.width(10);
	cout << num << '\n';
	cout.fill(prev);

}


/*
* Validate an integer entry
* returns validated integer
*/

int validateInt(string prompt) {
	int num = 0;
	cout << prompt;
	while ((!(cin >> num)) || cin.fail()) {
		cout << "Error - try again.  ";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << prompt;

	}
	return num;
}
int validateInt(string prompt, int min, int max) {
	int num = 0;
	cout << prompt;
	while ((!(cin >> num)) || cin.fail() || num<min || num>max) {
		cout << "Error - try again.  \n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << prompt;

	}
	return num;
}

/*
* Validate an double entry
* returns validated double
*/

double validateDouble(string prompt) {
	double num = 0;
	cout << prompt;
	while ((!(cin >> num)) || cin.fail()) {
		cout << "Error - try again.  ";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << prompt;

	}
	return num;
}


/*
* Validate an float entry
* returns validated float
*/

float validateFloat(string prompt) {
	float num = 0;
	cout << prompt;
	while ((!(cin >> num)) || cin.fail()) {
		cout << "Error - try again.  ";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << prompt;

	}
	return num;
}




#pragma endregion comment


char repeatPrompt() {
	cin.ignore(100, '\n');
	cin.clear();
	cin.sync();
	cls();
	char answer = 'n';
	cout << "\n\nWould you like to repeat the program? (y/n):  ";

	while ((!(cin >> answer) || cin.fail()) || (tolower(answer) != 'y' && (tolower(answer) != 'n'))) {
		cout << "Error - try again.  ";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');

	}
	return answer;
}
/*
	string getFileName() {
		ofstream fout;
		string fileName, directory;
		bool goodFileName = false;

		do {
			cout << "Where is the directory the file should open in?" << endl;
			getline(cin, directory);

			cout << "What is the file's name? " << endl;
			getline(cin, fileName);
			fileName = directory + "\\" + fileName;

			fout.open(directory + "\\" + fileName);
			if (fout.is_open()) {
				fout.close();
				goodFileName = true;
			}
			else {
				cout << "\nERROR: Could not open file in specified directory.  Try again. \n" << endl;
			}

		} while (!goodFileName);
		return fileName;
	}
	*/
void selectionSortInt(int arr[], int size) {
	bool swap;
	int temp;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (arr[count] > arr[count + 1])
			{
				temp = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}
void selectionSortFloat(float arr[], int size) {
	bool swap;
	float temp;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (arr[count] > arr[count + 1])
			{
				temp = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}
void selectionSortDouble(double arr[], int size) {
	bool swap;
	double temp;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (arr[count] > arr[count + 1])
			{
				temp = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}
void selectionSortChar(char arr[], int size) {
	bool swap;
	char temp;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (arr[count] > arr[count + 1])
			{
				temp = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}
void selectionSort(string arr[], int size) {
	bool swap;
	string temp;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (arr[count].compare(arr[count + 1]) == 0)
			{
				temp = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}


int linearSearchInt(const int list[], int numElems, int value)
{
	int index = 0; // Used as a subscript to search array
	int position = -1; // To record position of search value
	bool found = false; // Flag to indicate if the value was found

	while (index < numElems && !found)
	{
		if (list[index] == value) // If the value is found
		{
			found = true; // Set the flag
			position = index; // Record the value's subscript
		}
		index++; // Go to the next element
	}
	return position; // Return the position, or −1
}

int linearSearchFloat(const float list[], int numElems, float value)
{
	int index = 0; // Used as a subscript to search array
	int position = -1; // To record position of search value
	bool found = false; // Flag to indicate if the value was found

	while (index < numElems && !found)
	{
		if (list[index] == value) // If the value is found
		{
			found = true; // Set the flag
			position = index; // Record the value's subscript
		}
		index++; // Go to the next element
	}
	return position; // Return the position, or −1
}

int linearSearchDouble(const double list[], int numElems, double value)
{
	int index = 0; // Used as a subscript to search array
	int position = -1; // To record position of search value
	bool found = false; // Flag to indicate if the value was found

	while (index < numElems && !found)
	{
		if (list[index] == value) // If the value is found
		{
			found = true; // Set the flag
			position = index; // Record the value's subscript
		}
		index++; // Go to the next element
	}
	return position; // Return the position, or −1
}

int linearSearchChar(const char list[], int numElems, char value)
{
	int index = 0; // Used as a subscript to search array
	int position = -1; // To record position of search value
	bool found = false; // Flag to indicate if the value was found

	while (index < numElems && !found)
	{
		if (list[index] == value) // If the value is found
		{
			found = true; // Set the flag
			position = index; // Record the value's subscript
		}
		index++; // Go to the next element
	}
	return position; // Return the position, or −1
}

int linearSearchString(const string list[], int numElems, string value)
{
	int index = 0; // Used as a subscript to search array
	int position = -1; // To record position of search value
	bool found = false; // Flag to indicate if the value was found

	while (index < numElems && !found)
	{
		if (list[index].compare(value) == 1) // If the value is found
		{
			found = true; // Set the flag
			position = index; // Record the value's subscript
		}
		index++; // Go to the next element
	}
	return position; // Return the position, or −1
}

int binarySearchInt(const int array[], int numElems, int value)
{
	int first = 0, // First array element
		last = numElems - 1, // Last array element
		middle, // Midpoint of search
		position = -1; // Position of search value
	bool found = false; // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate midpoint
		if (array[middle] == value) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
	}
	return position;
}

int binarySearchFloat(const float array[], int numElems, float value)
{
	int first = 0, // First array element
		last = numElems - 1, // Last array element
		middle, // Midpoint of search
		position = -1; // Position of search value
	bool found = false; // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate midpoint
		if (array[middle] == value) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
	}
	return position;
}

int binarySearchDouble(const double array[], int numElems, double value)
{
	int first = 0, // First array element
		last = numElems - 1, // Last array element
		middle, // Midpoint of search
		position = -1; // Position of search value
	bool found = false; // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate midpoint
		if (array[middle] == value) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
	}
	return position;
}

int binarySearchChar(const char array[], int numElems, char value)
{
	int first = 0, // First array element
		last = numElems - 1, // Last array element
		middle, // Midpoint of search
		position = -1; // Position of search value
	bool found = false; // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate midpoint
		if (array[middle] == value) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
	}
	return position;
}

int binarySearchString(const string array[], int numElems, string value)
{
	int first = 0, // First array element
		last = numElems - 1, // Last array element
		middle, // Midpoint of search
		position = -1; // Position of search value
	bool found = false; // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate midpoint
		if (array[middle].compare(value) == 0) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle].compare(value) > 0) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
	}
	return position;
}

void bubbleSortInt(int array[], int size)
{
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}



void bubbleSortChar(char array[], int size)
{
	char startScan, minIndex, minValue;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}

void bubbleSortString(string arr[], int size)
{
	int startScan, minIndex;
	string minValue;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = arr[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (arr[index].compare(minValue) < 0)
			{
				minValue = arr[index];
				minIndex = index;
			}
		}
		arr[minIndex] = arr[startScan];
		arr[startScan] = minValue;
	}
}
