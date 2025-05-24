#include "schedule_menu.h"
#include "utils.h"

void ScheduleMenu::display() const {
	string submenu_title = "Schedule Management";
	vector<string> submenu_options = {
	"1. Add Course",
	"2. Delete Course",
	"3. Edit Course",
	"4. View Courses",
	"5. Save Courses",
	"6. Back to Main Menu"
	};

	display_submenu(submenu_title, submenu_options);
};

bool ScheduleMenu::handle_choice(int choice, GradeTracker& gradeTracker,
						  AttendanceTracker& attendanceTracker,
						  CourseManager& courseManager) {
	do {
		choice = input_validation(1, 6, "Enter your choice (1-6): ");

		switch (choice) {
			case 1:
				courseManager.add_course();
			break;
			case 2:
				courseManager.delete_course();
			break;
			case 3:
				courseManager.edit_course();
			break;
			case 4:
				courseManager.view_courses();
			break;
			case 5:
				courseManager.save_courses();
			break;
			case 6:
				cout << "Returning to Main Menu..." << endl;
			break;
		}
	} while (choice != 6);
}