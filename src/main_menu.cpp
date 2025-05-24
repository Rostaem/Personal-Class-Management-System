#include "main_menu.h"
#include "schedule_management.h"
#include <iostream>
#include <iomanip>

using namespace std;

void MainMenu::display() {
    // Main menu specific display
    cout << setfill('*') << setw(WIDTH) << "" << endl;
    string title = "Welcome to your Personal Course Management System!";
    int padding = (WIDTH - static_cast<int>(title.length())) / 2;
    cout << setfill(' ') << setw(padding + static_cast<int>(title.length())) << title
         << setw(WIDTH - padding - static_cast<int>(title.length())) << "" << endl;

    string subtitle = "Choose where to navigate:";
    padding = (WIDTH - static_cast<int>(subtitle.length())) / 2;
    cout << setw(padding + static_cast<int>(subtitle.length())) << subtitle
         << setw(WIDTH - padding - static_cast<int>(subtitle.length())) << "" << endl;

    cout << setfill('*') << setw(WIDTH) << "" << endl;

    vector<string> main_menu_options = {
        "1. Schedule",
        "2. Attendance",
        "3. Record & View Grades",
        "4. Exit"
    };

    for (const string& option : main_menu_options) {
        format_box(option, '-', BOX_WIDTH);
    }
}

bool MainMenu::handle_choice(int choice) {

    switch (choice) {
        case 1:
            scheduleMenu.display();
            scheduleMenu.handle_choice(0);
            //scheduleManager.manage_schedule();
            break;
        case 2:
            attendanceTracker.track_attendance(courseManager.get_courses());
            break;
        case 3:
            gradeTracker.manage_grades();
            break;
        case 4:
            cout << "Goodbye! Saving all data..." << endl;
            courseManager.save_courses();
            gradeTracker.save_grades();
            attendanceTracker.save_attendance();
            return false;
        default:
            cout << "Invalid input, returning to main menu..." << endl;
    }

    return true;
}