#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <vector>
#include "grade_tracker.h"
#include "attendance_tracker.h"
using namespace std;

//made this an abstract base class
class Menu {
protected:
	const int WIDTH = 60;       // formatting
	const int BOX_WIDTH = 40;   // menu boxes

	// Helper function for formatting borders and centered text (used for submenus and main menu)
	void format_box(const string& text, char border_char, int width) const;
	void display_submenu(const string& title, const vector<string>& options) const;

public:
	// Default constructor
	Menu() = default;

	// Virtual destructor for proper inheritance
	virtual ~Menu() = default;

	// Methods that can be overridden by derived classes
	virtual void display() = 0;
	virtual bool handle_choice(int choice, CourseManager& courseManager, AttendanceTracker& attendanceTracker) = 0;
};

#endif // MENU_H


