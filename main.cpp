#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <filesystem>
#include "utils/main_menu_display.h"
#include "utils/schedule_management.h"
#include "utils/attendance_tracker.h"
#include "utils/grade_tracker.h"
#include "utils/ensure_data_directory.h"

using namespace std;
namespace fs = filesystem;

int main() {

    // Load previously saved data for classes, attendance, and grades
    load_courses(); //functions defined in other files
    load_attendance();
    load_grades();

    ensure_data_directory();

    int choice;

    // Infinite while loop to keep the program running until the user chooses to exit
    while (true) {

        main_menu_display();

        cin >> choice;

        // Input validation 1: Check if the input is a valid integer
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue; // Restart the loop
        }

        // input validation 2: Validate the menu choice is between 1 and 4
        if (choice < 1 || choice > 4) { //using if statements for input validation
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        // Handling user input using a switch statement
        switch (choice) {
            case 1:
                manage_schedule();
                break;
            case 2:
                track_attendance();
                break;
            case 3:
                manage_grades();
                break;
            case 4:
                cout << "Goodbye! Saving all data..." << endl;

                // Save data for courses attendance, and grades before exiting
                save_courses();
                save_attendance();
                save_grades();

                return 0;
            default:
                cout << "Invalid input. Please enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}