#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
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

inline string trim(const string& str) {
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == string::npos)
		return "";

	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, last - first + 1);
}

inline string to_lower(const string& str) {
	string result = str;
	transform(result.begin(), result.end(), result.begin(),
			  [](unsigned char c) { return tolower(c); });
	return result;
}




#endif // UTILS_H