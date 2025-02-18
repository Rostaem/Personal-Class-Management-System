#include "main_menu_display.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Purpose: display the main menu with left-aligned boxes
void main_menu_display() {
	const int WIDTH = 60;    // Width of the menu block for formatting
	const int BOX_WIDTH = 40; // Width of individual option boxes

	// Top border
	cout << setfill('*') << setw(WIDTH) << "" << endl;

	// Title
	string title = "Welcome to your Personal Course Management System!";
	int padding = (WIDTH - title.length()) / 2;
	cout << setfill(' ') << setw(padding + title.length()) << title
		 << setw(WIDTH - padding - title.length()) << "" << endl;

	// Subtitle
	string subtitle = "Choose where to navigate:";
	padding = (WIDTH - subtitle.length()) / 2;
	cout << setw(padding + subtitle.length()) << subtitle
		 << setw(WIDTH - padding - subtitle.length()) << "" << endl;

	// Bottom border for the header
	cout << setfill('*') << setw(WIDTH) << "" << endl;

	// Menu options
	string menu_options[] = {
		"1. Schedule",
		"2. Attendance",
		"3. Record & View Grades",
		"4. Exit"
	};

	// Display each option in a left-aligned box
	for (const string &option : menu_options) {
		int option_padding = (BOX_WIDTH - option.length()) / 2;

		// Top border of the box
		cout << "|" << setfill('-') << setw(BOX_WIDTH) << "-" << "|" << endl;

		// Content of the box
		cout << "|" << setfill(' ') << setw(option_padding + option.length()) << option
			 << setw(BOX_WIDTH - option_padding - option.length()) << "  |" << endl;

		// Bottom border of the box
		cout << "|" << setfill('-') << setw(BOX_WIDTH) << "-" << "|" << endl;
	}

	// Input prompt
	cout << "Enter your choice: ";
}