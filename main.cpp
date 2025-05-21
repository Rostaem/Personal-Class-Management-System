#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <filesystem>
#include "include/menu.h"
#include "include/schedule_management.h"
#include "include/attendance_tracker.h"
#include "include/grade_tracker.h"
#include "include/ensure_data_directory.h"
#include "src/utils/utils.h"

using namespace std;
namespace fs = filesystem;

int main() {
	GradeTracker gradeTracker;
	AttendanceTracker attendanceTracker;

	// Ensure the data directory exists and load previously saved data for courses, attendance, and grades
	ensure_data_directory();
	load_courses();
	attendanceTracker.load_attendance();
	gradeTracker.load_grades();

	Menu menu;

	while (true) {
		menu.display_main_menu();

		int choice = input_validation(1, 4, "Enter your choice (1-4): ");
		if (choice == -1) {
			cout << "Invalid input. Returning to menu..." << endl;
			continue;
		}


		if (!menu.handle_main_menu_choice(choice, gradeTracker, attendanceTracker)) {
			break;
		}
	}


	save_courses();
	attendanceTracker.save_attendance();
	gradeTracker.save_grades();

	return 0;
}