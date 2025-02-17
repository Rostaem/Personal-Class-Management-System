#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <filesystem>
#include "utils/main_menu_display.h"
#include "utils/schedule_management.h"
#include "utils/attendance_tracker.h"
#include "utils/grade_tracker.h"
#include "utils/ensure_data_directory.h"

using namespace std;
namespace fs = filesystem;

int main() {

	ensure_data_directory();


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