/*
Rahim Siddiq
Dec 04 2022
Lab 8 - Password generator: Console application assist user in creating a password that meets the following criteria: No spaces / minimum length of
6 characters / one uppercase letter / one lowercase letter / one number / one special character (punctuation)
*/

// Pre-processor directives
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
	// Constants & variables. Constants for min and max password lengths. Int variables for password requisites. Char arrays to store desired
	// password and password confirmation.
	const int PASSMIN = 6, PASSMAX = 20, PASSLENGTH = 256;
	int passUpperCase = 0, passLowerCase = 0, passDigit = 0, passSpecial = 0, passSpace = 0;
	char desiredPass[PASSLENGTH]{ 0 }, confirmPass[PASSLENGTH]{ 0 };

	// Output program function to user lists password requisites
	cout << endl << " ================================================================================================================" << endl;
	cout << " ========================== This program assists in the creation of a secure password. ==========================" << endl;
	cout << " ================================================================================================================" << endl << endl;
	cout << " Please enter a desired password that meets the following criteria:" << endl;
	cout << "   - Must be six to twenty characters in length" << endl;
	cout << "   - Cannot include any [space]'s" << endl;
	cout << "   - Must contain at least one uppercase letter" << endl;
	cout << "   - Must contain at least one lowercase letter" << endl;
	cout << "   - Must contain at least one number" << endl;
	cout << "   - Must contain at least one special character (punctuation)";

	// do loop increments variables outputs specific error messages. While loop terminates condition if all password requisites are met
	do
	{
		// Each pass through the variables are cleared so they dont carry values from previous passes through the loop
		passUpperCase = 0, passLowerCase = 0, passDigit = 0, passSpecial = 0, passSpace = 0;
		cout << endl << endl << " Enter your password, then press the [Enter] key: ";
		// User input prompt for c-string array
		cin.getline(desiredPass, PASSLENGTH);
		// for loop increments variables when password requisites in an element are met
		for (int i = 0; i < strlen(desiredPass); i++)
		{
			if (isupper(desiredPass[i]))
				passUpperCase++;
			else if (islower(desiredPass[i]))
				passLowerCase++;
			else if (isdigit(desiredPass[i]))
				passDigit++;
			else if (isspace(desiredPass[i]))
				passSpace++;
			else if (ispunct(desiredPass[i]))
				passSpecial++;
		}

	// Specific conditional statements to user for missing requisites in password entry
	cout << endl << " **********************************************************************";
		if (strlen(desiredPass) < PASSMIN)
		{
			cout << endl << " * Your password must be at least six characters in length            *";
		}
		if (strlen(desiredPass) > PASSMAX)
		{
			cout << endl << " * Your password cannot be more than twenty characters in length      *";
		}
		if (passUpperCase == 0)
		{
			cout << endl << " * You are missing an upper case letter in your password              *";
		}
		if (passLowerCase == 0)
		{
			cout << endl << " * You are missing a lower case letter in your password               *";
		}
		if (passDigit == 0)
		{
			cout << endl << " * You are missing a numeric digit in your password                   *";
		}
		if (passSpace != 0)
		{
			cout << endl << " * Your password cannot include any [Space]'s                         *";
		}
		if (passSpecial == 0)
		{
			cout << endl << " * You are missing a special character (punctuation) in your password *";
		}
	cout << endl << " **********************************************************************";
	// loop repeated until all password requisites are met
	} while (strlen(desiredPass) < PASSMIN || strlen(desiredPass) > PASSMAX || passUpperCase == 0 || passLowerCase == 0 || passDigit == 0 || passSpace != 0 || passSpecial == 0);

	// do loop prompts user for password confirmation. strcmp used to compare the arrays and conditionals output messages accordingly
	do
	{
		cout << endl << endl << " Re-enter your password to confirm, then press [Enter]: ";
		cin.getline(confirmPass, PASSLENGTH);
		if (strcmp(desiredPass, confirmPass) == 0)
			cout << endl << " Thank you, your password has been set";
		else
		{
			cout << endl << " **********************************************";
			cout << endl << " * The passwords must match, please try again *";
			cout << endl << " **********************************************";
		}
	// loop repeated until both arrays are equal
	} while (strcmp(desiredPass, confirmPass) != 0);

	cout << endl << endl;

	return 0;
}