/*
Rahim Siddiq
Nov 09 2022
Lab 6 - Console application allows user to build and price a custom specification PC
*/

// Pre-processor directives
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void userInput(double*, int*, int*, bool*, char*);
double calculateTotal(double, int, int, bool);
void displayBuild(double, int, int, bool, double);

// Main function
int main()
{
	// Define variables for processor speed, Storage capacity, RAM, touchscreen and final price
	double cpuSpeed, total;
	int storage, ram;
	bool touchScreen;
	char build, screenChoice;
	bool start = true;

	// Output program function to the user
	cout << endl << " ====== This program allows you to build and price a PC to your exact specifications. ======" << endl << endl;

	// While loop set to process by default
	while (start == true)
	{
		cout << endl << " Would you like to build a PC?, please input (Y) for yes OR (N) for no, then press enter: ";
		cin >> build;

		while (build == 'y' || build == 'Y')
		{
			cout << endl << " =============================================================================================" << endl;
			// Call the input() function to take user input and initialize the variables. Pass the variables as reference.
			userInput(&cpuSpeed, &storage, &ram, &touchScreen, &screenChoice);
			//calculate the total by calling calculateTotal function.
			total = calculateTotal(cpuSpeed, storage, ram, touchScreen);
			// Display all the data by calling displayBuild function
			displayBuild(cpuSpeed, storage, ram, touchScreen, total);
			// Re-prompt for next build
			cout << endl << " Would you like to build another?";
			cin >> build;
		}
		// User option to quit
		if (build == 'n' || build == 'N')
		{
			cout << endl << " Thank you!!! see you again!!!" << endl << endl;
			exit(0);
		}
		// Invalid input screening
		else
		{
			cout << endl << " *****Invalid input! You must select (Y) to proceed or (N) to quit.*****" << endl;
			continue;
		}
	}
	return 0;
}

//*******************************************************************************************************************************************
// userInput function																														*
// variables are passed by reference to this function which takes and validates user input													*
//*******************************************************************************************************************************************
void userInput(double* cpuSpeed, int* storage, int* ram, bool* touchScreen, char* screenChoice)
{
	// User inputs cpuSpeed
	cout << endl << " Please enter the processor speed you want (in GHz), then press enter: ";
	cin >> *cpuSpeed;
	// Validate input for cpuSpeed, re-promt for input
	while (*cpuSpeed <= 0)
	{
		cout << " *****Invalid Input. Please enter a number greater than 0 for processor speed: ";
		cin >> *cpuSpeed;
	}
	// User input desired storage capacity
	cout << endl << " Please enter the hard drive storage capacity (in GBs), then press enter: ";
	cin >> *storage;
	// Validate input for storage, re-promt for input
	while (*storage <= 0)
	{
		cout << " *****Invalid Input. Please enter a number greater than 0 for storage: ";
		cin >> *storage;
	}
	// User Input for ram capacity
	cout << endl << " Please enter the desired amount of RAM (in GBs), then press enter: ";
	cin >> *ram;
	// Validate input for ram, re-promt for input
	while (*ram <= 0)
	{
		cout << " *****Invalid Input. Please enter a number greater than 0 for ram: ";
		cin >> *ram;
	}
	// Screen choice Input -- uses while loop to protect from unwanted inputs
	cout << endl << " Do you want a touch screen display?, (Y) for yes or (N) for no, then press enter: ";
	cin >> *screenChoice;
	while (true)
	{
		if (*screenChoice == 'y' || *screenChoice == 'Y')
		{
			*touchScreen = true;
			break;
		}
		else if (*screenChoice == 'n' || *screenChoice == 'N')
		{
			*touchScreen = false;
			break;
		}
		else
		{
			cout << " *****Invalid input. Please enter (Y) or (N) for touch screen: ";
			cin >> *screenChoice;
			continue;
		}
	}
}

//*******************************************************************************************************************************************
// calculateTotal function																													*
// function calculates the total price of the PC build																						*
//*******************************************************************************************************************************************
double calculateTotal(double cpuSpeed, int storage, int ram, bool touchScreen)
{
	// Variables needed to perform calculations
	double baseCost = 150.0, price = 0.0, addCost = 0.0, markup = 0.75, speedCost = 50, storageCost = 40, ramCost = 5, screenCost = 60;
	int addSpeed = 0, addStorage = 0, addRam = 0, speedTier = 2, storageTier = 500, ramTier = 4;
	// Add $50 to the cost for each GHz of processor speed over 2 GHz.
	if (cpuSpeed > speedTier)
	{
		// calculate chargable tiers for processor speed / multiply by extra cost and store to addCost
		addSpeed = static_cast<int>(cpuSpeed / speedTier);
		addCost = addCost + addSpeed * speedCost;
	}
	// Charge $40 for every 500GB >= 500 increment addCost
	if (storage >= storageTier)
	{
		addStorage = storage / storageTier;
		addCost = addCost + addStorage * storageCost;
	}
	// Add $5 for each GB of RAM over 4 GB.
	if (ram > ramTier)
	{
		addRam = ram / ramTier - ramTier;
		addCost = addCost + ramCost * addRam;
	}
	// Add $60 for the touchscreen.
	if (touchScreen == true)
	{
		addCost = addCost + screenCost;
	}
	price = baseCost + addCost;
	price = price + markup * price;
	return price;
}

//*******************************************************************************************************************************************
// void displayBuild function																												*
// Outputs all specifications and price to console for user.																				*
//*******************************************************************************************************************************************
void displayBuild(double cpuSpeed, int storage, int ram, bool touchScreen, double total)
{
	cout << endl << endl << "============== YOUR PC! ================" << endl;
	cout << " Processor speed of your PC    : " << cpuSpeed << " GHz" << endl;
	cout << " Storage capacity of your PC   : " << storage << " GB" << endl;
	cout << " RAM included in your PC       : " << ram << " GB" << endl;
	if (touchScreen == true)
	{
		cout << " Touchscreen                   : Yes" << endl;
	}
	else
	{
		cout << " Touchscreen                   : No" << endl;
	}
	cout << " Total Price of the PC is      : $" << total << endl;
}