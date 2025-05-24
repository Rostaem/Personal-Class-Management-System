#ifndef SCHEDULE_MENU_H
#define SCHEDULE_MENU_H

#include "menu.h"
#include "grade_tracker.h"
#include "attendance_tracker.h"
#include "course_management.h"
#include<iomanip>

class ScheduleMenu: public Menu {
public:
	// Override the display method from the base class
	void display() override;

	// Override the handle_choice method from the base class
	bool handle_choice(int choice, CourseManager& courseManager) override;
	virtual ~ScheduleMenu() = default;

};
#endif
