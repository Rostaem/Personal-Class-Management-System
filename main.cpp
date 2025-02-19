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
		if (choice == -1) {
			cout << "Invalid input. Returning to menu..." << endl;
			continue;
		}


		if (!handle_main_menu_choice(choice)) {
			break;
		}
	}

	return 0;
}