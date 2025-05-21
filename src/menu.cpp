#include "menu.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Menu::format_box(const string& text, char border_char, int width) const {
	cout << "|" << setfill(border_char) << setw(width) << "" << "|" << endl;
	int padding = (width - static_cast<int>(text.length())) / 2;
	cout << "|" << setfill(' ')
		 << setw(padding) << "" << text
		 << setw(width - padding - static_cast<int>(text.length())) << "" << "|" << endl;
	cout << "|" << setfill(border_char) << setw(width) << "" << "|" << endl;
}

void Menu::display_menu(const string& title, const vector<string>& options) const {
	cout << setfill('=') << setw(WIDTH) << "=" << endl;
	int padding = (WIDTH - static_cast<int>(title.length())) / 2;
	cout << setfill(' ') << setw(padding + static_cast<int>(title.length())) << title
		 << setw(WIDTH - padding - static_cast<int>(title.length())) << "" << endl;
	cout << setfill('=') << setw(WIDTH) << "=" << endl;
	for (const string& option : options) {
		format_box(option, '-', BOX_WIDTH);
	}
}

void Menu::display_main_menu() const {
	cout << setfill('*') << setw(WIDTH) << "" << endl;
	string title = "Welcome to your Personal Course Management System!";
	int padding = (WIDTH - static_cast<int>(title.length())) / 2;
	cout << setfill(' ') << setw(padding + static_cast<int>(title.length())) << title
		 << setw(WIDTH - padding - static_cast<int>(title.length())) << "" << endl;
	string subtitle = "Choose where to navigate:";
	padding = (WIDTH - static_cast<int>(subtitle.length())) / 2;
	cout << setw(padding + static_cast<int>(subtitle.length())) << subtitle
		 << setw(WIDTH - padding - static_cast<int>(subtitle.length())) << "" << endl;
	cout << setfill('*') << setw(WIDTH) << "" << endl;
	vector<string> main_menu_options = {
		"1. Schedule",
		"2. Attendance",
		"3. Record & View Grades",
		"4. Exit"
	};
	for (const string& option : main_menu_options) {
		format_box(option, '-', BOX_WIDTH);
	}
}

bool Menu::handle_main_menu_choice(int choice, GradeTracker& grade_tracker, AttendanceTracker& attendance_tracker, ScheduleManager& schedule_manager) const {
	switch (choice) {
		case 1:
			schedule_manager.view_courses();
			break;
		case 2:
			attendance_tracker.track_attendance(schedule_manager);
			break;
		case 3:
			grade_tracker.manage_grades();
			break;
		case 4:
			cout << "Goodbye! Saving all data..." << endl;
			schedule_manager.save_courses();
			grade_tracker.save_grades();
			attendance_tracker.save_attendance();
			return false;
		default:
			cout << "Invalid input, returning to main menu..." << endl;
	}
	return true;
}