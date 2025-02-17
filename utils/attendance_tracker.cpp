#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "attendance_tracker.h"
#include "schedule_management.h"

#define WIDTH 50
// Purpose : Manages attendance.
using namespace std;

struct Attendance {
    string class_name;
    int total_classes;
    int attended_classes;
};

vector<Attendance> attendance_records;

// Purpose : displays menu and handles user input.
void track_attendance() {
    int choice;
    do {
        string title = "Attendance Tracker";
        int centering = (WIDTH - title.length()) / 2;
        cout << setfill('=') << setw(centering) << "" << title << setfill('=') << setw(WIDTH  - title.length() - centering) << "" << endl;
        cout << "1. Track Attendance" << endl;
        cout << "2. Calculate Attendance Percentage" << endl;
        cout << "3. Display Attendance Records" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        if (cin.fail()){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max());
          cout << "Invalid input, please enter a number between 1 and 4. " << endl;
          continue;
          }

        if (choice < 1 || choice > 4) {
          cout << " Invalid Input. Enter a number between 1 and 4" << endl;
          continue;
        }

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

    // Check if the class exists in the schedule
    bool class_found_in_schedule = false;
    for (const auto &cls : classes) {
        if (cls.name == class_name) {
            class_found_in_schedule = true;
            break;
        }
    }

    // If class doesn't exist in the schedule
    if (!class_found_in_schedule) {
        cout << "Class '" << class_name << "' doesn't exist in the schedule." << endl;
        cout << "Please add the class to the schedule first, then track attendance." << endl;
        return; // Return to the attendance menu
    }


    for (auto &record : attendance_records) {
        if (record.class_name == class_name) {
            int attended;


            while (true) {
                cout << "Enter 1 if attended, 0 if absent: ";
                cin >> attended;

                if (cin.fail() || (attended != 0 && attended != 1)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter 0 or 1." << endl;
                } else {
                    break;
                }
            }


            record.total_classes++;
            if (attended == 1) {
                record.attended_classes++;
            }

            cout << "Attendance marked successfully!" << endl;
            return;
        }
    }


    Attendance new_record;
    new_record.class_name = class_name;
    new_record.total_classes = 1;

    int attended;

    while (true) {
        cout << "Enter 1 if attended, 0 if absent: ";
        cin >> attended;

        if (cin.fail() || (attended != 0 && attended != 1)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 0 or 1." << endl;
        } else {
            break;
        }
    }

    new_record.attended_classes = (attended == 1) ? 1 : 0;
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