#include <iostream>
#include <iomanip>
#include <limits>
#include "main_menu_display.h"
#include "schedule_management.h"
#include "attendance_tracker.h"
#include "grade_tracker.h"

using namespace std;

int main() {
	load_classes();
	load_attendance();
	load_grades();

	int choice;

	while (true) {
		main_menu_display();
		cin >> choice;

		// Input validation: Check for int value
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << "Invalid input. Please enter a number between 1 and 4." << endl;
			continue;
		}

		// Bounds check
		if (choice < 1 || choice > 4) {
			cout << "Invalid input. Please enter a number between 1 and 4." << endl;
			continue;
		}


		switch (choice) {
			case 1:
				manage_schedule();
			break;
			case 2:
				track_attendance();
			break;
			case 3:
				manage_grades();
			break;
			case 4:
				cout << "Goodbye! Saving all data..." << endl;
			save_classes();
			save_attendance();
			save_grades();
			return 0;
			default:
				
					cout << "Invalid input. Please enter a number between 1 and 4." << endl;
		}
	}

	return 0;
}