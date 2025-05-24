 #include "menu.h"
#include "schedule_management.h"
#include "attendance_tracker.h"
#include "grade_tracker.h"
#include "course_management.h"
#include <iostream>
#include <iomanip>

using namespace std;

CourseManager courseManager;
ScheduleManager scheduleManager;

void Menu::format_box(const string& text, char border_char, int width) const {
    cout << "|" << setfill(border_char) << setw(width) << "" << "|" << endl;
    int padding = (width - static_cast<int>(text.length())) / 2;
    cout << "|" << setfill(' ')
         << setw(padding) << "" << text
         << setw(width - padding - static_cast<int>(text.length()))
	<< "" << "|" << endl;
    cout << "|" << setfill(border_char) << setw(width) << "" << "|" << endl;
}

void Menu::display_submenu(const string& title, const vector<string>& options) const {
	cout << setfill('=') << setw(WIDTH) << "=" << endl;
	int padding = (WIDTH - static_cast<int>(title.length())) / 2;
	cout << setfill(' ') << setw(padding + static_cast<int>(title.length())) << title
		 << setw(WIDTH - padding - static_cast<int>(title.length())) << "" << endl;
	cout << setfill('=') << setw(WIDTH) << "=" << endl;

	for (const string& option : options) {
		format_box(option, '-', BOX_WIDTH);
	}
}




