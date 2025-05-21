#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "grade_tracker.h"
#include "attendance_tracker.h"
using namespace std;

// this file was previously named main_menu_display and it served the purpose of storing the function to display the main menu
// it's now used to display all menus (main menu and submenu, by using a menu class which will store both functions)

class Menu {
private:
	const int WIDTH = 60;       // formatting
	const int BOX_WIDTH = 40;   // menu boxes

	// Helper function for formatting borders and centered text (used for submenus and main menu)
	void format_box(const string& text, char border_char, int width) const;

public:
	Menu() {
		cout << "hey world" << endl;
	};

	void display_main_menu() const;

	void display_menu(const string& title, const vector<string>& options) const;

	bool handle_main_menu_choice(int choice, GradeTracker& gradeTracker, AttendanceTracker& attendanceTracker) const;
};

#endif // MENU_H


