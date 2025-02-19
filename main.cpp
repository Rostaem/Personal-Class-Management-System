#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <filesystem>
#include "include/main_menu_display.h"
#include "include/schedule_management.h"
#include "include/attendance_tracker.h"
#include "include/grade_tracker.h"
#include "include/ensure_data_directory.h"
#include "src/utils/utils.h"

using namespace std;
namespace fs = filesystem;

int main() {
	// Ensure the data directory exists and load previously saved data for courses, attendance, and grades
	ensure_data_directory();
	load_courses();
	load_attendance();
	load_grades();

	while (true) { // Main menu loop
		main_menu_display();

		int choice = input_validation(1, 5, "Enter your choice (1-5): ");
		if (choice == -1) { // Handle invalid input
			cout << "Invalid input. Returning to menu..." << endl;
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

			// Save data for courses, attendance, and grades before exiting
			save_courses();
			save_attendance();
			save_grades();

			return 0;

			default:
					cout << "Unexpected error. Returning to menu..." << endl;
			break;
		}
	}

	return 0;
}