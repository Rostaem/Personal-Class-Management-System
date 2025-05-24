
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "menu.h"
#include "grade_tracker.h"
#include "attendance_tracker.h"
#include "course_management.h"
#include "schedule_management.h"
#include<iomanip>

#include "schedule_menu.h"

class MainMenu : public Menu {
    public:
		// Override the display method from the base class
		void display() override;

		// Override the handle_choice method from the base class
		bool handle_choice(int choice) override;
		virtual ~MainMenu() = default;

	private:
		ScheduleManager scheduleManager;
		AttendanceTracker attendanceTracker;
		GradeTracker gradeTracker;
		CourseManager courseManager;
		ScheduleMenu scheduleMenu;
};
#endif //MAIN_MENU_H
