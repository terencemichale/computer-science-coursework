#ifndef banking_h
#define banking_h

#include <string>

//using std::string;
using namespace std;


class Banking
{
	/*
	* Private members will use Pascal case to identify they are private
	*/
private:
	int m_NumYears{0};	//the number of years for the investment
	double
		m_InitialInvestment {0}, //how much is deposited to start
		m_MonthlyDeposit {0},	//how much money is contributed each month
		m_InterestRate {0}, 		//interest rate in whole numbers to be converted to percentages
		m_BeginningBalance {0},	//beginning of the year balance
		m_Interest {0},			//interest earned for the year
		m_ClosingBalance {0};	//end of year balance which becomes the next year's beginning balance
	/*
	* This is the latest and preferred way to initialize a default constructor
	* This is not shown in the video
	*/

	/*
	* Changed private methods to Pascal case. Video shows camel case.
	*/
	void CalcBalance();
	void UpdateBalance(bool);
    void CalculateBalanceWithoutMonthlyDeposit();
    void CalculateBalanceWithMonthlyDeposit();

    void DisplayInterestTable(string);

public:
	Banking() = default; //default contstructor to initialized variables.
	void setInitialInvestment(double); //done
	void setNumYears(int);
	void setMonthlyDeposit(double);
	void setInterestRate(double);
	int getNumYears() const;
	double getInitialInvestment() const;
	double getMonthlyDeposit() const;
	double getInterestRate() const;
    void displayBalances(); 
	void dataInput();

    void displayInt(int);
    void displayPercent(double);
    void displayAmount(double);

    string centerText(string, int, char = ' ');
	void printChar(int, char = ' ');


};

#endif

