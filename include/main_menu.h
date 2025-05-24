
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "menu.h"
#include "grade_tracker.h"
#include "attendance_tracker.h"
#include "course_management.h"
#include<iomanip>

#include "attendance_menu.h"
#include "schedule_menu.h"

class MainMenu : public Menu {
    public:
		// Override the display method from the base class
		void display() override;

		// Override the handle_choice method from the base class
		bool handle_choice(int choice, CourseManager& courseManager, AttendanceTracker& attendanceTracker) override;
		virtual ~MainMenu() = default;

	private:
		GradeTracker gradeTracker;
		ScheduleMenu scheduleMenu;
		AttendanceMenu attendanceMenu;
};
#endif //MAIN_MENU_H
