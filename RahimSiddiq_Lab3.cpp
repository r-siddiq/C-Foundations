/*
Rahim Siddiq
Sept 22 2022
Lab 3
*/

// Pre-processor directives
#include <iostream>
#include <iomanip>
using namespace std;

// Console application to calculate how many sqares fit in a circle
int main()
{
	// Output of program function to the user
	cout << endl << " A program that calculates how many squares fit in a circle" << endl << endl;

	// Constant for PI
	const double PI = 3.14159265358979;										// Constant for PI

	// Floating-point variables for squares and circles
	double squareSide, circleDiameter, circleRadius, squareArea, circleArea, numSquares;

	// User inputs
	cout << " Enter the diameter of the circle: ";							// Prompt for user to enter data
	cin >> circleDiameter;													// User input stored in circleDiameter
	cout << endl;
	cout << " Enter a number for the length of the squares sides: ";		// Promt for user to enter date
	cin >> squareSide;														// User input stored in squareSide

	// Calculations for the area of squares and circles & variable assignments for area
	circleRadius = circleDiameter / 2;										// Convert diameter to radius for area calculation
	circleArea = PI * (circleRadius * circleRadius);						// Area Formula pi * radius squared
	squareArea = squareSide * squareSide;									// Area Formula side squared

	// Calculating how many sqares will fit in the area of the circle
	numSquares = circleArea / squareArea;

	// Display output and formatting
	cout << setprecision(2) << fixed << endl;								// setprecision to limit decimal spaces
	cout << " " << numSquares << " squares with side length: " << squareSide << " will fit inside a circle with a diameter of: " << circleDiameter;

	cout << endl << endl;

	return 0;
}