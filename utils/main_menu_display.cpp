#include "main_menu_display.h"
using namespace std;

// Purpose: display the main menu / demonstrating output formatting
void main_menu_display() {
	const int WIDTH = 60; // width of the menu block for formatting

	// output formatting
	cout << setfill('*') << setw(WIDTH) << "" << endl;

	// setw() adjusts the width of the output, and setfill(' ') fills spaces
	cout << setfill(' ') << setw((WIDTH + 44) / 2)
		 << "Welcome to your Personal Course Management System!" << endl;

	cout << setw((WIDTH + 23) / 2) << "Choose where to navigate" << endl; // explain this line

	// bottom border of the header
	cout << setfill('*') << setw(WIDTH) << "" << endl;

	cout << "1. Schedule" << endl;
	cout << "2. Attendance" << endl;
	cout << "3. Record & View Grades" << endl;
	cout << "4. Exit" << endl;

	cout << "Enter your choice: ";
}