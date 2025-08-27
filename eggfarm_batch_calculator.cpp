/*
Rahim Siddiq
Oct 25 2022
Lab 5 - Console application calculates the (total number, total type, percentage of type, number of carton dozen) for eggs
*/

// Pre-processor directives
#include <iostream>
#include <iomanip>
using namespace std;

// main function calculates the (total number, total type, percentage of type, number of carton dozen) of eggs and outputs result to user
int main()
{
	// Constant for dozen eggs
	const int CARTON = 12;
	const float PERCENTAGE = 100;
	// Int variables for baskets, number of white eggs, number of brown eggs, total brown, total while
	int numBaskets, whiteEggs, brownEggs, totalEggs, whiteDozen, brownDozen, totWhiteEggs = 0, totBrownEggs = 0;
	// Float variables for percentages
	float percentBrown, percentWhite;

	// Output of program function to the user
	cout << endl << " Program calculates the (total number, total type, percentage of type, number of carton dozen) for a batch of eggs" << endl <<endl;

	// User prompt and input call for numBaskets
	cout << " Please enter the number of baskets: ";
	cin >> numBaskets;
	cout << endl;
	// Validate input for numBaskets, re-promt for input
	while (numBaskets <= 0)
	{
		cout << " You have entered an invalid number. Please enter a number greater than 0 for baskets: ";
		cin >> numBaskets;
		cout << endl;
	}

	// for loop iterates to numBaskets value, promts input for white eggs per basket, then increments totWhiteEggs by whiteEggs each iteration
	for (int i = 0; i < numBaskets; i++)
	{
		cout << " Please enter the number of white eggs in basket #" << i + 1 << ": ";
		cin >> whiteEggs;
	// Validate input for whiteEggs, re-prompt for input
		while (whiteEggs < 0)
		{
			cout << endl;
			cout << " You have entered a negative number. Please enter a positve number or 0 for white eggs in basket #" << i + 1 << ": ";
			cin >> whiteEggs;
		}
		totWhiteEggs += whiteEggs;
		cout << endl;
	}

	// for loop iterates to numBaskets value, promts input for brown eggs per basket, then increments totBrownEggs by brownEggs each iteration
	for (int i = 0; i < numBaskets; i++)
	{
		cout << " Please enter the number of brown eggs in basket #" << i + 1 << ": ";
		cin >> brownEggs;
	// Validate input for brownEggs, re-prompt for input
		while (brownEggs < 0)
		{
			cout << endl;
			cout << " You have entered a negative number. Please enter a positve number or 0 for brown eggs in basket #" << i + 1 << ": ";
			cin >> brownEggs;
		}
		totBrownEggs += brownEggs;
		cout << endl;
	}
	
	// Type conversions for percentage calculation
	float itotWhiteEggs = static_cast<float> (totWhiteEggs);
	float itotBrownEggs = static_cast<float> (totBrownEggs);
	
	// Calculations for total number of eggs, percentages of each color, and how many dozens of each color
	totalEggs = totBrownEggs + totWhiteEggs;
	percentWhite = itotWhiteEggs / totalEggs * PERCENTAGE;
	percentBrown = itotBrownEggs / totalEggs * PERCENTAGE;
	whiteDozen = totWhiteEggs / CARTON;
	brownDozen = totBrownEggs / CARTON;

	// Format and display output to program user
	cout << setprecision(2) << fixed << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl << " The total number of eggs in this batch: " << totalEggs << endl;
	cout << " Number of white eggs: " << totWhiteEggs << endl;
	cout << " Number of brown eggs: " << totBrownEggs << endl << endl;
	cout << " Percentage of white eggs: " << percentWhite << "%" << endl;
	cout << " Percentage of brown eggs: " << percentBrown << "%" << endl << endl;
	cout << " The total number of carton dozen for white eggs is: " << whiteDozen << endl;
	cout << " The total number of carton dozen for brown eggs is: " << brownDozen << endl <<endl;
	cout << "--------------------------------------------------------------------------------------------------------------------";
	
	cout << endl << endl;

	return 0;
}