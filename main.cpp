#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <filesystem>
#include "features//main_menu_display.h"
#include "features/schedule_management.h"
#include "features/attendance_tracker.h"
#include "features/grade_tracker.h"
#include "utils/ensure_data_directory.h"
#include "utils/utils.h"

using namespace std;
namespace fs = filesystem;

int main() {
    // Load previously saved data for classes, attendance, and grades
    ensure_data_directory();
    load_courses();
    load_attendance();
    load_grades();
    while (true) {
        // Define menu options for the main menu
       main_menu_display();

        // Input validation: Get user choice as an integer
        int choice;
        cin >> choice;

        if (cin.fail()) { // Check if input is invalid
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        // Validate the menu choice is within the correct range
        if (choice < 1 || choice > 4) {
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        // Handle user input based on their choice
        switch (choice) {
            case 1: // Schedule Management
                manage_schedule();
                break;

            case 2: // Attendance Management
                track_attendance();
                break;

            case 3: // Grade Management
                manage_grades();
                break;

            case 4: // Exit
                cout << "Goodbye! Saving all data..." << endl;

                // Save data for courses, attendance, and grades before exiting
                save_courses();
                save_attendance();
                save_grades();

                return 0;

            default:
                cout << "Invalid input. Please try again." << endl;
        }
    }

    return 0;
}