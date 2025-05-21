#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <filesystem>

#include "menu.h"
#include "schedule_management.h"
#include "attendance_tracker.h"
#include "grade_tracker.h"
#include "ensure_data_directory.h"
#include "utils.h"

using namespace std;
namespace fs = filesystem;

int main() {
	GradeTracker grade_tracker;
	AttendanceTracker attendance_tracker;
	ScheduleManager schedule_manager;

	ensure_data_directory();
	schedule_manager.load_courses();
	attendance_tracker.load_attendance();
	grade_tracker.load_grades();

	Menu menu;

	while (true) {
		menu.display_main_menu();

		int choice = input_validation(1, 4, "Enter your choice (1-4): ");
		if (choice == -1) {
			cout << "Invalid input. Returning to menu..." << endl;
			continue;
		}

		if (!menu.handle_main_menu_choice(choice, grade_tracker, attendance_tracker, schedule_manager)) {
			break;
		}
	}

	schedule_manager.save_courses();
	attendance_tracker.save_attendance();
	grade_tracker.save_grades();

	return 0;
}