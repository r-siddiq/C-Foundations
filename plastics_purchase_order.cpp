/*
Rahim Siddiq
Nov 20 2022
Lab 7 - Console application to produce a purchase order for recycled plastics.
*/

// Pre-processor directives
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	// Constants & variables. Arrays for plastic types, price of plastic type per pound, pounds per type, cost per type. Variables for total weight and cost.
	const int SIZE = 6;
	const string PLASTIC_TYPE[] = { "PET beverage bottles and jars", "Natural high-density polyethylene", "Color HDPE", "Grade A film", "Grade B film", "Grade C film" };
	const double PRICE_PER_LB[] = { 0.08, 0.34, 0.04, 0.08, 0.05, 0.02 };
	double poundsOfType[6] = { 0 };
	double costOfType[6] = { 0 };
	double totalWeight = 0, totalCost = 0;

	// Output program function to user
	cout << endl << " ==============================================================================================================" << endl;
	cout << " ============= This program creates a recycled plastics purchase order, for Plastic Products INC. =============" << endl;
	cout << " ==============================================================================================================" << endl << endl;
	cout << " *** Please enter the weight for each corresponding type of plastic in LBS, then press [enter] to continue. ***" << endl << endl;

	// For Loop to add user input into array. update cost of each type and increment totals
	for (int i = 0; i < SIZE; i++)
	{
		cout << " How many pounds of " << PLASTIC_TYPE[i] << "?: ";
		cin >> poundsOfType[i];
		while (poundsOfType[i] < 0)
		{
			cout << " No negative values please! Enter the weight again: ";
			cin >> poundsOfType[i];
		}
		costOfType[i] += poundsOfType[i] * PRICE_PER_LB[i];
		totalWeight += poundsOfType[i];
		totalCost += costOfType[i];
	}

	// Format & output to console for user. For loop prints names of plastics, pounds of each type, price per pound, and total cost of each type. then outputs totals.
	cout << endl << " ---------------------------------- PURCHASE ORDER ----------------------------------" << endl;
	cout << right << setw(20) << " Material" << setw(30) << "Weight(Pounds)" << setw(15) << "Cost/Pound" << setw(12) << "Cost" << endl;
	cout << " ------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << setprecision(2) << fixed;
		cout << " " << left << setw(37) << PLASTIC_TYPE[i] << setw(20) << poundsOfType[i] << "$" << setw(14) << PRICE_PER_LB[i] << "$" << costOfType[i] << endl;
	}
	cout << " ------------------------------------------------------------------------------------" << endl;
	cout << " " << left << setw(37) << "Totals:" << left << setw(35) << totalWeight << "$" << totalCost << endl;

	cout << endl << endl;

	return 0;
}