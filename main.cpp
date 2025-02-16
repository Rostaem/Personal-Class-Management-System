#include <iostream>
#include <iomanip>
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
	do {
		main_menu_display();
		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max());
			cout << "Invalid input. Please enter a number between 1-4 " << endl;
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
			break;
			default:
				cout << "Invalid input. Please enter a number between 1-4." << endl;
		}

	} while (choice != 4);

	return 0;
}