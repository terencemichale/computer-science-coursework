
/*
 * Name: Terence Michale
 * Class: CS-210
 * 
 * Mod 5 Fahrenheit to Celsius Converter
 * This program converts a temperature from Fahrenheit to Celsius. 
 *  1. It reads temperature from a file, 
 *  2. Performs the conversion using the formula C = (F - 32) * 5 / 9, 
 *  3. Uutput formatted results to another file.
 * 
 * */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

ifstream OpenFile(const string); // Function for reading the file
double ConvertFahrenheitToCelsius(double fahrenheit); // Function prototype for converting Fahrenheit to Celsius

const string FILENAME = "FahrenheitTemperature.txt"; // Name of the file containing the Fahrenheit temperature
const string OUTPUT_FILENAME = "CelsiusTemperature.txt"; // Name of the file to write the Celsius output
    
ifstream OpenFile(const string) {
    // Function to read the Fahrenheit temperature from the input file, perform the conversion, and write the results to the output file
   
    ifstream inFS; // Input file stream to read from the file
    inFS.open(FILENAME); // Attempt to open the file

    if (!inFS.is_open()) { // Check if the file was opened successfully
        cerr << "Could not open " << FILENAME << " file!" << endl; // Output an error message if the file cannot be opened
    }

    return inFS; // Return the input file stream for further processing regardless of success or failure in opening the file
}

double ConvertFahrenheitToCelsius(double fahrenheit) {
    // Function to convert a temperature from Fahrenheit to Celsius using the formula C = (F - 32) * 5 / 9
    double celsius = 0.0; // Variable to store the converted Celsius temperature

    celsius = (fahrenheit - 32) * 5 / 9.0; // Perform the conversion using the formula
    return celsius; // Return the converted the Celsius temperature
}

int main() {
    
    string city = ""; // City for the temperature read from the file
    int fahrenheit = 0; // Fahrenheit temperature read from the file
    double celsius = 0.0; // Converted Celsius temperature

    string output; // Variable to store the formatted output string

    ifstream inFS; // Input file stream to read from the file
    ofstream outFS; // Output file stream to write the results

    inFS = OpenFile(FILENAME); // Call the function to read the file and perform the conversion
    outFS.open(OUTPUT_FILENAME); // Open the output file to write the results

    inFS >> city; // Read the first city name of the loop

    if (inFS.fail() && !inFS.eof()) { // Check if reading the next city name failed due to an error (not just end of file)
        cout << "City name not provided!" << endl; // Output an error message for reading issues
        return 1; // Exit with a non-zero status to indicate an error
    }

    while (!inFS.eof() && !inFS.fail()) { // loop to read the city and temnperature in fahrenheit

        inFS >> fahrenheit;
        if (inFS.fail()) { // Check if reading the Fahrenheit temperature failed
            cout << "Fahrenheit temperature not provided!" << endl; // Output an error message for missing input
            return 1; // Exit with a non-zero status to indicate an error
        }
        
        celsius = ConvertFahrenheitToCelsius(fahrenheit); // Convert Fahrenheit to Celsius using the formula C = (F - 32) * 5 / 9
        
        outFS << city << " " << fixed << setprecision(2) << celsius << endl; // Format the output string with the city name and Celsius temperature
        
        if (outFS.fail()) { // Check if writing to the output file failed
            cout << "Error writing to the output file!" << endl; // Output an error message for writing issues
            return 1; // Exit with a non-zero status to indicate an error
        }
        
        inFS.ignore(); // Ignore the newline character after reading the city and temperature
        inFS >> city; // Read the next city name for the next iteration of the loop

        if (inFS.fail() && !inFS.eof()) { // Check if reading the next city name failed due to an error (not just end of file)
            cout << "City name not provided!" << endl; // Output an error message for reading issues
            return 1; // Exit with a non-zero status to indicate an error
        }
    }

    if (inFS.eof()) { // Check if the end of the file was reached successfully
        cout << "End of file reached." << endl; // Output a message indicating that the end of the file was reached
    }

    outFS.close(); // Close the output file
    inFS.close(); // Close the input file

}
