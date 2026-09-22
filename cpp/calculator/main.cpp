/*
 * Calculator.cpp
 *
 *  Date: 5/17/2026
 *  Author: Terence Michale
 */

#include <iostream>
#include <cctype>
#include <limits>

using namespace std;

int main()
{
	int op1, op2;
	char operation;
	char answer = 'Y'; // Initialize char literal using single quotes, added semicolon

	while (tolower(answer) == 'y') // Corrected condition to compare with char literal 'y' using tolower to allow for both uppercase and lowercase input
	{
		cout << "Enter expression" <<endl;
		if (!(cin >> op1 >> operation >> op2)) {
            if (cin.eof()) return 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid expression. Example: 8 + 2" << endl;
            continue;
        }
        if (operation == '/' && op2 == 0) {
            cout << "Cannot divide by zero." << endl;
            continue;
        }
        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') // Added condition to check for valid operators
        {
            cout << "Invalid operator. Please enter one of the following: +, -, *, /." << endl;
            continue; // Skip the rest of the loop and prompt the user again
        }
        
		if (operation == '+') // Removed semicolon, corrected to char literal using single quotes
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
		if (operation == '-')
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; // Removed semicolon, changed '>>' to '<<' for outputral using single quotes
		if (operation == '*')
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; // Removed semicolon, corrected operator from '/' to '*'
		if (operation == '/')
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; // Corrected operator from '*' to '/'

		cout << "Do you wish to evaluate another expression? " << endl;
		if (!(cin >> answer)) return 0;

        
        while (tolower(answer) != 'y') // Added condition to handle invalid input
        {
                if (tolower(answer) == 'n') // Added condition to break the loop if the user types “N” or “n,” the program will terminate with the message:
            {
                cout << "Program Finished." << endl;
                break; // Added break statement to exit the loop when the user chooses not to continue
            } else {
                cout << "Invalid input. Please enter 'Y' to continue or 'N' to exit." << endl;
                if (!(cin >> answer)) return 0;
            }
        }
	}
}

