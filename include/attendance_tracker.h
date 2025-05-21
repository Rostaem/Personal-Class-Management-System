#ifndef ATTENDANCE_TRACKER_H
#define ATTENDANCE_TRACKER_H

#include <iostream>
#include <vector>
#include <string>
#include "schedule_management.h"

using namespace std;

struct AttendanceRecord {
	string course_name;
	vector<string> dates;
};

class AttendanceTracker {
private:
	vector<AttendanceRecord> attendance_records;

public:
	void track_attendance(ScheduleManager& schedule_manager);
	void save_attendance() const;
	void load_attendance();
};

#endif // ATTENDANCE_TRACKER_H