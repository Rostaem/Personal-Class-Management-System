#include "utils.h"

void display_menu(const string &title, const vector<string> &options, const int width) {
	// Header formatting
	int centering = (width - title.length()) / 2;
	cout << endl
		 << setfill('=') << setw(centering) << "" << title
		 << setfill('=') << setw(width - title.length() - centering) << "" << endl;

	// Display menu options
	for (size_t i = 0; i < options.size(); ++i) {
		cout << i + 1 << ". " << options[i] << endl;
	}

	// Footer
	cout << setfill('=') << setw(width) << "" << endl;
	cout << "Enter your choice: ";
}

// Function to clear input buffer
void clear_input_buffer() {
	cin.clear(); // Clear error flags
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
}

// Function to validate and get integer input
int get_valid_int_input(const string& prompt) {
	int value;
	while (true) {
		cout << prompt;
		cin >> value;

		if (cin.fail()) {
			cout << "Invalid input. Please enter a valid integer." << endl;
			clear_input_buffer();
		} else {
			clear_input_buffer();
			return value;
		}
	}
}

// Function to trim whitespace from a string
string trim(const string& str) {
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	return (start == string::npos) ? "" : str.substr(start, end - start + 1);
}

// Function to print a line with a specified character and length
void print_line(char ch, int length) {
	for (int i = 0; i < length; ++i) {
		cout << ch;
	}
	cout << endl;
}