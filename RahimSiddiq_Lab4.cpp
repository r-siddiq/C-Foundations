/*
Rahim Siddiq
Oct 10 2022
Lab 4
*/

// Pre-processor directives
#include <iostream>
#include <iomanip>
using namespace std;

// Console application to calculate the salary of employees for a retail store.
int main()																			// Start of main function
{																					// Start body of main function
	// Output of program function to the user
	cout << endl << " A program that calculates the salary of empoyees for a retail store" << endl << endl;

	// Constants for hourly pay, commissions and overtime
	const double MIN_WAGE = 18;														// Constant for minimum hourly wage
	const double OVERTIME = MIN_WAGE * 0.5;											// Constant for overtime additonal multiplier
	const double REG_HOURS = 40;													// Constant for non-overtime hours
	const double COMM_TIER_1 = 0.02;												// Constant for first comission tier
	const double COMM_TIER_2 = 0.03;												// Constant for second comission tier
	const double COMM_TIER_3 = 0.04;												// Constant for third comission tier
	const double COMM_TIER_4 = 0.05;												// Constant for fourth comission tier

	// double variables for hours worked, commissions and net pay
	double hoursWorked, salesAmount, minPay, commission, netPay;

	// User inputs and user input validations
	cout << " Please enter the hours worked this week: ";							// Prompt for user to enter hours worked
	cin >> hoursWorked;																// User input stored in hoursWorked
	cout << endl;																	// Call new line
	if (hoursWorked < 0)															// Conditional for validating input
	{																				// {} for multi-line conditional
		cout << " Invalid input: Please enter positive values for hours worked.";   // Error prompt for user
		cout << endl;																// Call new line to seperate error from prompt
		cout << " Please enter the hours worked the week: ";						// Re-prompt user for expected input
		cin >> hoursWorked;															// User input stored in hoursWorked
		cout << endl;																// Call new line
	}																				// End of validation statements for hoursWorked																				
	cout << " Please enter the amount of sales for this week: $";					// Promt for user to enter weekly sales
	cin >> salesAmount;																// User input stored in salesAmount
	cout << endl;																	// Call new line
	if (salesAmount < 0)															// Conditional for validating input
	{																				// {} for multi-line conditional
		cout << " Invalid input: Please enter positive values for sales amount.";	// Error prompt for the user
		cout << endl;																// Call new line to seperate error from prompt
		cout << " Please enter the amount of sales for the week: $";				// Re-prompt user for expected input
		cin >> salesAmount;															// User input stored in salesAmount
		cout << endl;																// Call new line
	}																				// End of validation for salesAmount

	// Calculations for hourly wages
	if (hoursWorked <= 40)															// Conditional for standard pay
		minPay = hoursWorked * MIN_WAGE;											// hours * wage
	else																			// Overtime conditon
		minPay = hoursWorked * MIN_WAGE + (hoursWorked - REG_HOURS) * OVERTIME;		// hours * wage + hours - REG_HOURS pay overtime

	// Calculating Comission tiers and wages
	if (salesAmount < 5000)															// Conditional for commission tier 1
		commission = salesAmount * COMM_TIER_1;										// Sales amount * 1st commission tier
	else if (salesAmount < 10000)													// Conditional for commission tier 2
		commission = salesAmount * COMM_TIER_2;										// Sales amount * 2nd commission tier
	else if (salesAmount < 20000)													// Conditional for commission tier 3
		commission = salesAmount * COMM_TIER_3;										// Sales amount * 3rd commission tier
	else																			// Condition not required last logical option
		commission = salesAmount * COMM_TIER_4;										// Sales amount * 4th commission tier


	// Comparisson between hourly and comission pay. Highest value set as net pay and formatting for pay amounts
	cout << setprecision(2) << fixed << endl;										// setprecision to limit decimal spaces
	if (minPay > commission)														// Conditional if hourly exceeds commission pay
	{																				// {} for multi-line if statement
		netPay = minPay;															// minPay assigned to netPay
		cout << " This employee does NOT qualify for commission pay." << endl;		// Prompt user employee is being paid by hours
	}																				// End if statement		
	else																			// Only other logical option
	{																				// Start else body
		netPay = commission;														// commission assigned to netPay
		cout << " This employee qualifies for commission pay. $$$" << endl;			// Prompt user employee hit commission target
	}																				// End of else statement
	// Final output to user for net pay
	cout << " The net pay for this employee is: $" << netPay;						// Output net pay to user

	cout << endl << endl;															// Formatting
	return 0;																		// Check for successful completion
}																					// End of main function