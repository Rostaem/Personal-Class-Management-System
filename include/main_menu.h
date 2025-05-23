
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "menu.h"
#include "grade_tracker.h"
#include "attendance_tracker.h"
#include "course_management.h"
#include<iomanip>

class MainMenu : public Menu {
public:
	// Override the display method from the base class
	void display() const override;

	// Override the handle_choice method from the base class
	bool handle_choice(int choice, GradeTracker& gradeTracker,
					AttendanceTracker& attendanceTracker,
					CourseManager& courseManager) const override;
	virtual ~MainMenu() = default;
};
#endif //MAIN_MENU_H
