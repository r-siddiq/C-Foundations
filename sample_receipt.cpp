/*
Rahim Siddiq
Sept 07 2022
Lab 2
*/

// Pre-processor directives
#include <iostream>
#include <string>
using namespace std;

// Function to create a reciept from Costco
int main()
{
	// Output of program function to the user
	cout << endl << " A program that replicates a Costco reciept" << endl << endl;

	// Constant for tax
	const double TAX = 0.0925;
	
	// Strings for product names & assignments for cout format
	string sweatpants = "  Sweatpants";
	string portableHardDrive = "  Portable Hard Drive";
	string almondMilk = "  Almond Milk";
	string hdmiCable = "  HDMI Cable";
	string headphones = "  Headphones";

	// double point variables for item prices
	double sweatpantsPrice = 12.95;
	double portableHardDrivePrice = 34.13;
	double almondMilkPrice = 9.32;
	double hdmiCablePrice = 15.18;
	double headphonesPrice = 32.99;

	// Reciept header with store info
	cout << endl << " ========== COSTCO WHOLESALE ==========" << endl << endl;
	cout << "        Woodland Hills #1205" << endl;
	cout << "        21800 Victory Blvd" << endl;
	cout << "        Woodland Hills, CA 91367" << endl;
	cout << "        (818) 884-9099" << endl;
	cout << endl << " ======================================" << endl << endl;

	// Output of items and prices
	cout << sweatpants << "                      " << sweatpantsPrice << endl;
	cout << portableHardDrive << "             " << portableHardDrivePrice << endl;
	cout << almondMilk << "                      " << almondMilkPrice << endl;
	cout << hdmiCable << "                      " << hdmiCablePrice << endl;
	cout << headphones << "                      " << headphonesPrice << endl << endl;

	// Variables for subtotal, tax and total
	double subTotal = sweatpantsPrice + portableHardDrivePrice + almondMilkPrice + hdmiCablePrice + headphonesPrice;
	double goodsTax = subTotal * TAX;
	double total = subTotal + goodsTax;

	// Outputs for subtotal, tax, and total
	cout << " SUBTOTAL:                       " << subTotal << endl;
	cout << " TAX:                           " << goodsTax << endl;
	cout << " ****TOTAL:                     " << total << endl;

	cout << endl << endl;

	return 0;
}