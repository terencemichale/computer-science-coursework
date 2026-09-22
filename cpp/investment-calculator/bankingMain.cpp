/*
* Terence Michale
* CS 210
* Project Two Banking
*
* This program will get the following
* 
* Month: The number of months based on user input in the “Number of Years” field
* Opening Amount: The initial investment amount as well as the opening balance each
* month, which includes interest
* Deposited Amount: The dollar amount the user plans to deposit each month. This value
* will be the same every month for the duration of the investment.
* Total: The sum of the opening and deposited amounts
* Interest: Money earned based on the “annual interest” rate input by the user.
* 
* Program will then display the results in an organized manner
*/
#include <iostream>
#include <limits>
#include "banking.h"

//using std::cin;
//using std::cout;
//using std::endl;

using namespace std;

Banking getUserInput();
int getInteger(int, string);
double getDouble(int, string);


int main() {

	Banking airgead;	//create an instance of the banking class

	int numYears{}; // the number of years until maturity
	char runAgain{}, //variable to ask the user if they want to run the program again with new values
		applyToCurrent{}; //variable to ask the user if they want to apply new values to current balances

	/*
	* The follwing function call get the initial investment, monthly deposit,
	* interest rate and number of years passing the minimum valid value and a prompt for the user
	*/
    airgead = getUserInput();

    do {

		Banking bankBalance = airgead;	//create an instance of the banking class
		
		// ask the user if they want to run the program again with new values
		cout << endl << "Do you want to run the investment forecast again with new values? (y/n): ";
		cin >> runAgain;
		if (runAgain == 'n' || runAgain == 'N') {
			cout << endl << airgead.centerText("Thank you for using the program. Goodbye!", 50, '*') << endl;

		} else if (runAgain == 'y' || runAgain == 'Y') {
			cout << endl;
			bankBalance = getUserInput(); // get new user input values
			
			cout << endl << "Would you like to apply the new values to the current balances? (y/n): ";
						
			cin >> applyToCurrent;
			if (applyToCurrent == 'y' || applyToCurrent == 'Y') {
				airgead.setInitialInvestment(bankBalance.getInitialInvestment());
				airgead.setMonthlyDeposit(bankBalance.getMonthlyDeposit());
				airgead.setInterestRate(bankBalance.getInterestRate());
				airgead.setNumYears(bankBalance.getNumYears());

				cout << endl << airgead.centerText("New values applied to current balances.", 50, '*') << endl;
				airgead.displayBalances(); // display the balances with the new values applied to the current balances

			} else if (applyToCurrent == 'n' || applyToCurrent == 'N') {
				cout << endl << airgead.centerText("No changes applied to current balances.", 50, '*') << endl;
				airgead.displayBalances();
				// do nothing and the new values will be applied when the balances are displayed
			} else {
				cout << "Invalid input. Please enter 'y' or 'n'." << endl;
			}
		} else {
			cout << "Invalid input. Please enter 'y' or 'n'." << endl;
		}
	} while (runAgain == 'y' || runAgain == 'Y'); //keep the console open until the user is ready to close it

	return 0;
}

Banking getUserInput()
{
    Banking airgead; // create an instance of the banking class
	double 
		initialInvestment{}, 
		monthlyDeposit{}, 
		interestRate{};
	int numYears{};
    airgead.displayBalances(); // display empty balances

    initialInvestment = getDouble(0, "What is the initial investment? ");
    airgead.setInitialInvestment(initialInvestment);

    monthlyDeposit = getDouble(0, "What is the monthly deposit? ");
    airgead.setMonthlyDeposit(monthlyDeposit);

    interestRate = getDouble(1, "What is interest rate? ");
    airgead.setInterestRate(interestRate);

    numYears = getInteger(1, "How many years should the investment grow? ");
    airgead.setNumYears(numYears);

    cout << endl;
    airgead.displayBalances(); // display and calculate the balances

    return airgead; // return the banking object with the user input values set
}
// main

int getInteger(int lowest)
{
	/*
	* The purpose getInteger is get an integer that is greater than or equal to the lowest passed
	*/
	int number{}; //number to get
	bool needData{ true }; //for validation

	do {
		cout << "Enter a number greater than or equal to " << lowest << " " << endl;
		cin >> number;
		needData = (number < lowest); //invalid is number is less than lowest passed
		if (needData) {
			cout << "Invalid number - must be greater than or equal to " << (lowest) << endl;
		}//if needData

	} while (needData);

	return number;
}

int getInteger(int lowest, string prompt)
{
	/*
	* The purpose getInteger is get an integer that is greater than or equal to the lowest passed
	* The prompt parameter allows to use this function for different inputs
	* Note this function does not check if data entered is a number. Use getline and regex for ths
	*/
	int number{}; //number to get
	bool needData{ true }; //for validation

	
	do {
		cout << prompt << lowest << " " << endl;
		cin >> number;

		if (cin.fail())
        {
            cout << "Invalid input. Please enter a number." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

		needData = (number < lowest);
		if (needData) {
			cout << "Invalid number - must be greater than or equal to " << (lowest) << endl;
		}//if needData

	} while (needData);

	return number;
}

double getDouble(int lowest, string prompt)
{
	/*
	* The purpose getDouble is get a double that is greater than or equal to the lowest passed
	* The prompt parameter allows to use this function for different inputs
	* Note this function does not check if data entered is a number. Use getline and regex for ths
	*/
	double number{}; //number to get
	bool needData{ true }; //set initial flag

	do {
		cout << prompt << " Must be greater than " << lowest << " " << endl;
		cin >> number;

		if (cin.fail())
        {
            cout << "Invalid input. Please enter a number." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

		needData = (number < lowest);
		if (needData) {
			cout << "Invalid number - must be greater than or equal to " << (lowest) << endl;
		}//if needData

	} while (needData);

	return number;

}

