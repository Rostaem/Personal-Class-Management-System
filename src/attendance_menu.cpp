#include <attendance_menu.h>
#include "utils.h"
#include "attendance_tracker.h"


void AttendanceMenu::display() {
	string submenu_title = "Attendance Tracker";
	vector<string> submenu_options = {
		"1. Track Attendance",
		"2. Calculate Attendance Percentage",
		"3. Display Attendance Records",
		"4. Back to Main Menu"
	};
	display_submenu(submenu_title, submenu_options);
};

bool AttendanceMenu::handle_choice(int choice, CourseManager& courseManager, AttendanceTracker& attendanceTracker ) {
	while (choice != 4){
		if (choice !=0) display();
		choice = input_validation(1, 6, "Enter your choice (1-4): ");

		switch (choice) {
			case 1:
				attendanceTracker.mark_attendance(courseManager.courses);
			break;
			case 2:
				attendanceTracker.calculate_attendance();
			break;
			case 3:
				attendanceTracker.display_attendance();
			break;
			case 4:
				cout << "Returning to Main Menu..." << endl;
			break;
		}
	};
	return true;
}