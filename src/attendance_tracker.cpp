#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "attendance_tracker.h"

#include "main_menu.h"
#include "schedule_management.h"
#include "utils/utils.h"

using namespace std;

// Purpose: Displays the attendance tracker menu and handles user input
void AttendanceTracker::track_attendance(const std::vector<Course>& courses) {
    MainMenu menu;

    string submenu_title = "Attendance Tracker";
    vector<string> submenu_options = {
        "1. Track Attendance",
        "2. Calculate Attendance Percentage",
        "3. Display Attendance Records",
        "4. Back to Main Menu"
    };

    int choice;
    do {
        menu.display();
        choice = input_validation(1, 4, "Enter your choice (1-4): ");

        if (choice == -1) {
            cout << "Invalid input, please enter a number between 1 and 4. Returning to menu..." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                mark_attendance(courses); // updated
            break;
            case 2:
                calculate_attendance();
            break;
            case 3:
                display_attendance();
            break;
            case 4:
                cout << "Returning to Main Menu." << endl;
            break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

void AttendanceTracker::mark_attendance(const std::vector<Course>& courses) {
    string course_name;
    cout << "Enter course name: ";
    getline(cin, course_name);

    bool course_found_in_schedule = false;
    for (const auto &course : courses) {
        if (course.name == course_name) {
            course_found_in_schedule = true;
            break;
        }
    }

    if (!course_found_in_schedule) {
        cout << "Course '" << course_name << "' doesn't exist in the schedule." << endl;
        return;
    }

    int attended;
    string input;
    while (true) {
        cout << "Enter 1 if attended, 0 if absent: ";
        getline(cin, input);
        stringstream ss(input);

        if (ss >> attended && ss.eof() && (attended == 0 || attended == 1)) {
            break;
        } else {
            cout << "Invalid input, please enter 0 or 1..." << endl;
        }
    }

    for (auto &record : attendance_records) {
        if (record.course_name == course_name) {
            record.total_courses++;
            if (attended == 1) {
                record.attended_courses++;
            }
            cout << "Attendance marked successfully!" << endl;
            return;
        }
    }

    Attendance new_record;
    new_record.course_name = course_name;
    new_record.total_courses = 1;
    new_record.attended_courses = (attended == 1) ? 1 : 0;
    attendance_records.push_back(new_record);

    cout << "Attendance marked successfully!" << endl;
}
void AttendanceTracker::calculate_attendance() {
    string course_name;
    cout << "Enter course name: ";
    getline(cin, course_name);

    for (const auto &record : attendance_records) {
        if (record.course_name == course_name) {
            if (record.total_courses == 0) {
                cout << "No courses recorded for " << course_name << "." << endl;
                return;
            }

            float percentage = (static_cast<float>(record.attended_courses) / record.total_courses) * 100; //static casting reqs
            cout << "Attendance percentage for " << course_name << ": " << percentage << "%" << endl;
            return;
        }
    }

    cout << "Course not found in attendance records." << endl;
}

void AttendanceTracker::display_attendance() {
    if (attendance_records.empty()) {
        cout << "No attendance records available." << endl;
        return;
    }

    cout << "=== Attendance Records ===" << endl;
    for (const auto &record : attendance_records) {
        cout << "Course: " << record.course_name
             << ", Total Courses: " << record.total_courses
             << ", Attended Courses: " << record.attended_courses << endl;
    }
}

void AttendanceTracker::save_attendance() {
    ofstream file("data/attendance_data.txt");
    if (!file) {
        cout << "Error saving attendance data." << endl;
        return;
    }

    for (const auto &record : attendance_records) {
        file << record.course_name << "," << record.total_courses << "," << record.attended_courses << endl;
    }

    file.close();
    cout << "Attendance data saved successfully." << endl;
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
        Attendance record;
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        record.course_name = line.substr(0, pos1);
        record.total_courses = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        record.attended_courses = stoi(line.substr(pos2 + 1));

        attendance_records.push_back(record);
    }

    file.close();
    cout << "Attendance data loaded successfully." << endl;
}