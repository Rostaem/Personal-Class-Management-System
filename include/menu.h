#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "grade_tracker.h"
#include "attendance_tracker.h"
#include "schedule_management.h"

using namespace std;

class Menu {
private:
	const int WIDTH = 60;
	const int BOX_WIDTH = 40;

	void format_box(const string& text, char border_char, int width) const;

public:
	Menu() {
		cout << "hey world" << endl;
	};

	void display_main_menu() const;
	void display_menu(const string& title, const vector<string>& options) const;

	bool handle_main_menu_choice(int choice, GradeTracker& grade_tracker, AttendanceTracker& attendance_tracker, ScheduleManager& schedule_manager) const;
};

#endif // MENU_H