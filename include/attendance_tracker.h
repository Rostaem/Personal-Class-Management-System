#ifndef ATTENDANCE_TRACKER_H
#define ATTENDANCE_TRACKER_H

#include <string>
#include <vector>
#include "course_management.h"

struct Attendance {
	std::string course_name;
	int total_courses;
	int attended_courses;
};


class AttendanceTracker {
private:
	std::vector<Attendance> attendance_records;

public:
	void track_attendance(const std::vector<Course>& courses);
	void mark_attendance(const std::vector<Course>& courses);
	void calculate_attendance();
	void display_attendance();
	void save_attendance();
	void load_attendance();
};

#endif // ATTENDANCE_TRACKER_H