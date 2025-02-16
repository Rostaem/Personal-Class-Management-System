#include <iostream>
#include <iomanip>
#include "schedule_management.h"
#include "attendance_tracker.h"
#include "grade_tracker.h"

using namespace std;

void display_main_menu() {
	cout << "******************************************************** " << endl;
	cout << "   Welcome to your Personal Class Management System!  " << endl;
	cout << setw(5) <<  "Chose where to navigate " << setw(5) <<  endl; // figure out how to center
	cout << "********************************************************" << endl;
	cout << "1. Schedule" << endl;
	cout << "2. Attendance" << endl;
	cout << "3. Record & View Grades" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice: ";
}

int main() {

	load_classes();
	load_attendance();
	load_grades();

	int choice;
	do {
		display_main_menu();
		cin >> choice;

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