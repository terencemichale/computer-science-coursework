#include <iostream>
#include <string>
using namespace std;

/*
 * Author: Terence Michale
 * Date: 5/24/2026
 * 
 * This program displays the current time in both 12-hour and 24-hour formats 
 * and allows the user to add one hour, one minute, or one second to the time. 
 * The user can also exit the program. The program uses functions to format the time, 
 * display the clocks, and process user input.
 * 
 * Upon finding invalid input for hours, minutes, seconds, or menu choices, the program prompts the user to enter valid input.
 * Best workaround using cin.fail(), cin.clear() and cin.ignore() to handle invalid input and prevent infinite loops 
 * when the user enters non-numeric values or values outside the expected range.
 * 
 */
string twoDigitString(int n) {
    // Convert a time attribute to a two-digit string, adding a leading zero if necessary
    // Using the expression (n < 10 ? "0" : "") to conditionally add a leading zero single digit numbers
    return (n < 10 ? "0" : "") + to_string(n);
}

string formatTime24(int h, int m, int s) {
    // Format time in 24-hour format (HH:MM:SS)
    return twoDigitString(h) + ":" +
           twoDigitString(m) + ":" +
           twoDigitString(s);
}

string formatTime12(int h, int m, int s) {
    // Format time in 12-hour format (HH:MM:SS AM/PM)
    // Determine AM or PM based on the hour
    string period = (h >= 12) ? "PM" : "AM";

    // Convert hour from 24-hour format to 12-hour format
    int hour12 = h % 12;

    // Handle the case where hour12 is 0, which corresponds to 12 in 12-hour format
    if (hour12 == 0) {
        hour12 = 12;
    }

    // Format the time string with the appropriate period (AM/PM)
    return twoDigitString(hour12) + ":" +
           twoDigitString(m) + ":" +
           twoDigitString(s) + " " + period;
}

void printMenu() {
    // Display the menu options to the user
    cout << "***************************" << endl;
    cout << "* 1 - Add One Hour        *" << endl;
    cout << "* 2 - Add One Minute      *" << endl;
    cout << "* 3 - Add One Second      *" << endl;
    cout << "* 4 - Exit Program        *" << endl;
    cout << "***************************" << endl;
}

void displayClocks(int h, int m, int s) {
    // Display the current time in both 12-hour and 24-hour formats in a formatted manner
    cout << endl;

    cout << "***************************   "
         << "***************************" << endl;

    cout << "*     12-Hour Clock       *   "
         << "*      24-Hour Clock      *" << endl;

    cout << "*      " << formatTime12(h, m, s)
         << "        *   ";

    cout << "*        " << formatTime24(h, m, s)
         << "         *" << endl;

    cout << "***************************   "
         << "***************************" << endl;
}

// Using pass-by-reference to allow the function to modify the original variable for hour
void addOneHour(int& h) {
    // Increment the hour and wrap around to 0 after reaching 23
    h = (h + 1) % 24;
}

// Using pass-by-reference to allow the function to modify the original variables for hour and minute
void addOneMinute(int& h, int& m) {
    // Increment the minute and handle the case where it reaches 60, which requires incrementing the hour
    m++;

    if (m >= 60) {
        // If minutes reach 60, reset to 0 and increment the hour
        m = 0;
        addOneHour(h);
    }
}

// Using pass-by-reference to allow the function to modify the original variables for hour, minute, and second
void addOneSecond(int& h, int& m, int& s) {
    // Increment the second and handle the case where it reaches 60, which requires incrementing the minute
    s++;

    if (s >= 60) {
        // If seconds reach 60, reset to 0 and increment the minute
        s = 0;
        addOneMinute(h, m);
    }
}

void processMenuChoice(int choice, int& h, int& m, int& s) {
    // Process the user's menu choice and call the appropriate function to update the time
    if (choice == 1) {

        addOneHour(h);
    }

    else if (choice == 2) {

        addOneMinute(h, m);
    }

    else if (choice == 3) {

        addOneSecond(h, m, s);
    }
}

int main() {

    int hour;
    int minute;
    int second;

    int choice = 0;

    cout << "Enter hour (0-23): ";
    cin >> hour;

    // Validate the hour input to ensure it is within the acceptable range (0-23)
    while (cin.fail() || hour < 0 || hour > 23) {
        cin.clear();
        cin.ignore(1000, '\n'); // Ignore the rest of the line
        cout << "Invalid hour. Enter hour (0-23): ";
        cin >> hour;
    }

    cout << "Enter minute (0-59): ";
    cin >> minute;

    // Validate the minute input to ensure it is within the acceptable range (0-59)
    while (cin.fail() || minute < 0 || minute > 59) {
        cin.clear();
        cin.ignore(1000, '\n'); // Ignore the rest of the line
        cout << "Invalid minute. Enter minute (0-59): ";
        cin >> minute;
    }

    cout << "Enter second (0-59): ";
    cin >> second;

    // Validate the second input to ensure it is within the acceptable range (0-59)
    while (cin.fail() || second < 0 || second > 59) {
        cin.clear();
        cin.ignore(1000, '\n'); // Ignore the rest of the line
        cout << "Invalid second. Enter second (0-59): ";
        cin >> second;
    }

    // Main loop to display the clocks and process user input until the user chooses to exit (choice 4)
    while (choice != 4) {

        displayClocks(hour, minute, second);

        printMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        // Validate the user's menu choice to ensure it is between 1 and 4
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n'); // Ignore the rest of the line
            cout << "Invalid choice. Enter 1-4: ";
            cin >> choice;
        }

        processMenuChoice(choice, hour, minute, second);
    }

    cout << "Program ended." << endl;

    return 0;
}