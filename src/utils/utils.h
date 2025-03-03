#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>
#include <sstream>
#include <string>
using namespace std;

// The ultimate input validation function
template <typename T>
T input_validation(T min, T max, const string& prompt) {
	T value;
	string input;

	while (true) {
		cout << prompt;
		getline(cin, input);  // Read the entire line of input

		stringstream ss(input);  // Create a stringstream to parse the input

		// Try to parse the input as the expected type and check if the parsing is complete (no extra characters left)
		if (ss >> value && ss.eof() && value >= min && value <= max) {
			// If parsing succeeded, no extra characters in the stream, and within range
			return value;
		} else {
			// Handle invalid input
			cout << "Invalid input. Please enter a valid number between " << min << " and " << max << ".\n";
		}
	}
}

#endif // UTILS_H