#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <filesystem>
#include "include/schedule_management.h"
#include "include/attendance_tracker.h"
#include "include/grade_tracker.h"
#include "include/ensure_data_directory.h"
#include "utils.h"
#include "course_management.h"
#include "main_menu.h"
using namespace std;
namespace fs = filesystem;


int main() {
	GradeTracker gradeTracker;
	AttendanceTracker attendanceTracker;
	CourseManager courseManager;

	ensure_data_directory();
	courseManager.load_courses();
	attendanceTracker.load_attendance();
	gradeTracker.load_grades();

	MainMenu mainMenu;

	while (true) {
		mainMenu.display();
		int choice = input_validation(1, 4, "Enter your choice (1-4): ");
		if (choice == -1) {
			cout << "Invalid input. Returning to menu..." << endl;
			continue;
		}

		if (!mainMenu.handle_choice(choice, gradeTracker, attendanceTracker, courseManager)) {
			break;
		}
	}

	courseManager.save_courses();
	attendanceTracker.save_attendance();
	gradeTracker.save_grades();

	return 0;
}