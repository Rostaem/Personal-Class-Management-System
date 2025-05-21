#include "attendance_tracker.h"
#include "schedule_management.h"
#include "utils/utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

void AttendanceTracker::track_attendance(ScheduleManager& schedule_manager) {
	const auto& courses = schedule_manager.get_courses();

	if (courses.empty()) {
		cout << "No available courses to track attendance." << endl;
		return;
	}

	cout << "Available courses:" << endl;
	for (const auto& course : courses) {
		cout << "- " << course.name << endl;
	}

	cin.ignore();
	string course_name;
	cout << "Enter course name to track attendance: ";
	getline(cin, course_name);

	bool course_found = false;
	for (const auto& course : courses) {
		if (course.name == course_name) {
			course_found = true;
			break;
		}
	}

	if (!course_found) {
		cout << "Course not found in schedule." << endl;
		return;
	}

	string date;
	cout << "Enter date for attendance (e.g., 2024-05-20): ";
	getline(cin, date);

	for (auto& record : attendance_records) {
		if (record.course_name == course_name) {
			record.dates.push_back(date);
			cout << "Attendance recorded." << endl;
			return;
		}
	}

	AttendanceRecord new_record;
	new_record.course_name = course_name;
	new_record.dates.push_back(date);
	attendance_records.push_back(new_record);

	cout << "Attendance recorded." << endl;
}

void AttendanceTracker::save_attendance() const {
	ofstream file("data/attendance_data.txt");
	if (!file) {
		cout << "Error saving attendance data." << endl;
		return;
	}

	for (const auto& record : attendance_records) {
		file << record.course_name;
		for (const auto& date : record.dates) {
			file << "," << date;
		}
		file << endl;
	}

	cout << "Attendance data saved." << endl;
}

void AttendanceTracker::load_attendance() {
	ifstream file("data/attendance_data.txt");
	if (!file) {
		cout << "No saved attendance data found." << endl;
		return;
	}

	attendance_records.clear();
	string line;
	while (getline(file, line)) {
		istringstream ss(line);
		string token;
		AttendanceRecord record;

		if (!getline(ss, token, ',')) {
			continue;
		}
		record.course_name = token;

		while (getline(ss, token, ',')) {
			record.dates.push_back(token);
		}

		attendance_records.push_back(record);
	}

	cout << "Attendance data loaded." << endl;
}