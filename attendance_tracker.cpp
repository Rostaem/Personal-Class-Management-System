#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "attendance_tracker.h"

using namespace std;


struct Attendance {
    string class_name;
    int total_classes;
    int attended_classes;
};

vector<Attendance> attendance_records;

void track_attendance() {
    int choice;
    do {
        cout << "=== Attendance Tracker ===" << endl;
        cout << "1. Mark Attendance" << endl;
        cout << "2. Calculate Attendance Percentage" << endl;
        cout << "3. Display Attendance Records" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                mark_attendance();
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

void mark_attendance() {
    string class_name;
    cout << "Enter class name: ";
    cin.ignore();
    getline(cin, class_name);

    for (auto &record : attendance_records) {
        if (record.class_name == class_name) {
            int attended;
            cout << "Enter 1 if attended, 0 if absent: ";
            cin >> attended;

            record.total_classes++;
            if (attended == 1) {
                record.attended_classes++;
            }

            cout << "Attendance marked successfully!" << endl;
            return;
        }
    }

    // If class doesn't exist, create a new attendance record
    Attendance new_record;
    new_record.class_name = class_name;
    new_record.total_classes = 1;

    cout << "Enter 1 if attended, 0 if absent: ";
    int attended;
    cin >> attended;

    new_record.attended_classes = attended == 1 ? 1 : 0;

    attendance_records.push_back(new_record);
    cout << "Attendance marked successfully!" << endl;
}

void calculate_attendance() {
    string class_name;
    cout << "Enter class name: ";
    cin.ignore();
    getline(cin, class_name);

    for (const auto &record : attendance_records) {
        if (record.class_name == class_name) {
            if (record.total_classes == 0) {
                cout << "No classes recorded for " << class_name << "." << endl;
                return;
            }

            float percentage = (static_cast<float>(record.attended_classes) / record.total_classes) * 100;
            cout << "Attendance percentage for " << class_name << ": " << percentage << "%" << endl;
            return;
        }
    }

    cout << "Class not found in attendance records." << endl;
}

void display_attendance() {
    if (attendance_records.empty()) {
        cout << "No attendance records available." << endl;
        return;
    }

    cout << "=== Attendance Records ===" << endl;
    for (const auto &record : attendance_records) {
        cout << "Class: " << record.class_name
             << ", Total Classes: " << record.total_classes
             << ", Attended Classes: " << record.attended_classes << endl;
    }
}

void save_attendance() {
    ofstream file("data/attendance_data.txt");
    if (!file) {
        cout << "Error saving attendance data." << endl;
        return;
    }

    for (const auto &record : attendance_records) {
        file << record.class_name << "," << record.total_classes << "," << record.attended_classes << endl;
    }

    file.close();
    cout << "Attendance data saved successfully." << endl;
}

void load_attendance() {
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

        record.class_name = line.substr(0, pos1);
        record.total_classes = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        record.attended_classes = stoi(line.substr(pos2 + 1));

        attendance_records.push_back(record);
    }

    file.close();
    cout << "Attendance data loaded successfully." << endl;
}