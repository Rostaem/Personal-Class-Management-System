#ifndef ATTENDANCE_MENU_H
#define ATTENDANCE_MENU_H

#include "menu.h"
#include "course_management.h"
#include<iomanip>

class AttendanceMenu: public Menu {
public:
	// Override the display method from the base class
	void display() override;

	// Override the handle_choice method from the base class
	bool handle_choice(int choice, CourseManager& courseManager, AttendanceTracker& attendanceTracker) override;
	virtual ~AttendanceMenu() = default;

};

#endif //ATTENDANCE_MENU_H
