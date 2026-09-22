/* Banking.cpp 
* Name: Terence Michale
* Class: CS 210
* Project Two Banking
*
* This file contains the implementation of the Banking class defined in banking.h
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "banking.h"

#include <string>

//using std::cout;
//using std::endl;
//using std::fixed;
//using std::setprecision;
//using std::setw;
//using std::right;
//using std::left;
//using std::string;
//using std::to_string;
//using std::string;

using namespace std;

void Banking::CalcBalance()
{
	m_Interest = m_BeginningBalance *
        ((m_InterestRate / 100.0) / 12.0);

    m_ClosingBalance = m_BeginningBalance + m_Interest;
}

void Banking::UpdateBalance(bool t_includeDeposit)
{
	// Calculate closing balance
    m_BeginningBalance = m_ClosingBalance;

    if (t_includeDeposit)
    {
        m_BeginningBalance += m_MonthlyDeposit;
    }
}

void Banking::CalculateBalanceWithoutMonthlyDeposit()
{
    int numYears{getNumYears()};

    m_BeginningBalance = getInitialInvestment();
    m_ClosingBalance = m_BeginningBalance;

    DisplayInterestTable("Balance and Interest Without Additional Monthly Deposits");

    for (int year = 1; year <= numYears; year++)
    {
        double yearlyInterest{0};

        for (int month = 1; month <= 12; month++)
        {
            UpdateBalance(false);
            CalcBalance();

            yearlyInterest += m_Interest;
        }

        cout << setw(10) << left << year;

        cout << setw(10) << right;
        displayAmount(m_ClosingBalance);

        cout << setw(26) << right;
        displayAmount(yearlyInterest);

        cout << endl;
    }
}

void Banking::CalculateBalanceWithMonthlyDeposit()
{
    int numYears{getNumYears()};

    m_BeginningBalance = getInitialInvestment();
    m_ClosingBalance = m_BeginningBalance;

    DisplayInterestTable("Balance and Interest With Additional Monthly Deposits");

    for (int year = 1; year <= numYears; year++)
    {
        double yearlyInterest{0};

        for (int month = 1; month <= 12; month++)
        {
            UpdateBalance(true);
            CalcBalance();

            yearlyInterest += m_Interest;
        }

        cout << setw(10) << left << year;

        cout << setw(10) << right;
        displayAmount(m_ClosingBalance);

        cout << setw(26) << right;
        displayAmount(yearlyInterest);

        cout << endl;
    }
}
void Banking::DisplayInterestTable(string t_label)
{
    cout << centerText(t_label, 62, ' ') << endl;
    printChar(65, '=');

    cout << left
         << setw(10) << "Year"
         << setw(25) << "Year End Balance"
         << setw(30) << "Year End Earned Interest"
         << endl;

    printChar(65, '-');
}

//setters
//note although not necessary it is good practice to user this-> to make sure class variables do not get confused with passed variables
void Banking::setInitialInvestment(double t_initialInvestment)
{

	this->m_InitialInvestment = t_initialInvestment;
	this->m_BeginningBalance = t_initialInvestment;	//the beginning balance needs to start with the initial investment
}

void Banking::setNumYears(int t_numYears)
{
	this->m_NumYears = t_numYears; //set the number of years for the investment
}

void Banking::setMonthlyDeposit(double t_monthlyDeposit)
{
	this->m_MonthlyDeposit = t_monthlyDeposit; //set the monthly deposit
}

void Banking::setInterestRate(double t_interestRate)
{
	this->m_InterestRate = t_interestRate; //set the interest rate. Note the interest rate is in whole numbers and will be converted to a percentage in the calculations
}

//getters

int Banking::getNumYears() const
{
	return m_NumYears;
}

double Banking::getInitialInvestment() const
{
	return m_InitialInvestment;
}

double Banking::getMonthlyDeposit() const
{
	return m_MonthlyDeposit;
}

double Banking::getInterestRate() const
{
	return m_InterestRate;
}

void Banking::displayBalances()
{
	// this function will display the balances for each year of the investment.
	dataInput();
    cin.get(); //wait for user input before displaying the balances

	if (getInitialInvestment() > 0) {
		CalculateBalanceWithoutMonthlyDeposit(); // display the balances without additional monthly deposits
	}
	cout << endl << endl; // add some space between the two tables
	if (getMonthlyDeposit() > 0) {
		CalculateBalanceWithMonthlyDeposit();
	}

}

void Banking::dataInput()
{
    printChar(35, '*');
    cout << centerText("Data Input", 35, '*') << endl;
	cout << fixed << setprecision(2); //set the decimal places to 2 for all output

	cout << "Initial Investment: ";
    displayAmount(getInitialInvestment()); // print the initial investment if it is greater than 0
	cout << endl;
	cout << "Monthly Deposit: ";
    displayAmount(getMonthlyDeposit()); // print the monthly deposit if it is greater than 0
	cout << endl;
	cout << "Interest Rate: ";
    displayPercent(getInterestRate()); // print the interest rate with a percent sign if it is greater than 0
	cout << endl;
	cout << "Number of Years: ";
    displayInt(getNumYears()); // print the number of years if it is greater than 0
	cout << endl;
	
	cout << "Press any key to continue . . ." << endl << endl;
}

void Banking::displayInt(int t_num)
{
	// this function will print the number if the number is greater than 0. If the number is 0 or less it will just print the label
    if (t_num > 0)
    {
        cout << t_num;
    }
}

void Banking::displayPercent(double t_rate)
{
	// this function will print the number with a percent sign if the number is greater than 0. If the number is 0 or less it will just print the label
    if (t_rate > 0)
    {
        cout << t_rate << "%";
    }
}

void Banking::displayAmount(double t_amount)
{
	// this function will print the number with a dollar sign if the number is greater than 0. If the number is 0 or less it will just print the label
    if (t_amount > 0)
    {
        cout << "$" << t_amount;
    }
}

//helper methods

string Banking::centerText(string t_text, int t_length, char t_fill) {
	/*
	* text the text to center
	* length the length of the line to center the text.
	* Note the line must be > text length to be able to center otherwise returns the original text unchanged
	* function will use a space if no fill character is passed
	*/

	int textLength = t_text.length(); //get the length of the text to be centered
	string centeredText = "";		//stores final version of text with padding

	// If the text is same or longer than the line length, return the original text
	if (textLength >= t_length) {
		return t_text;
	}
	else {
		int charsNeeded = (t_length - textLength); //how many characters are need to fill on left and right
		int paddingNeeded = (charsNeeded / 2); //calculate the number of padding characters needed
		string leftPadding = string(paddingNeeded, t_fill);
		string rightPadding = leftPadding;
		centeredText = (leftPadding + t_text + rightPadding);
		// Note rightPadding is not needed but allows for other characters

		if (charsNeeded % 2 != 0) { // check if need an additional character to make sure centered text length 
			//is not one char less than linelength
			centeredText.insert(0, 1, t_fill);
		}
		//cout << text.length() << endl << centeredText.length() << endl << leftPadding << endl << rightPadding << endl;
		return (centeredText);
	}

}

void Banking::printChar(int times, char charToPrint)
{
	/*
	* This function will print a passed character times
	* If no character is passed the charToPrint will be a space (' ');
	*/
	string str(times, charToPrint); //use this instead of a for loop
	cout << str << endl; //remember to take out endl if necessary
	//calling function needs to put in endl
}