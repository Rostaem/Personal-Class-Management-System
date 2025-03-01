#include "menu.h"
#include "schedule_management.h"
#include "attendance_tracker.h"
#include "grade_tracker.h"
#include <iostream>
#include <iomanip>
using namespace std;

Menu::Menu() {}

/*formatting borders and centered text helper function*/
void Menu::format_box(const string& text, char border_char, int width) const {

  cout << "|" << setfill(border_char) << setw(width) << "" << "|" << endl;

    int padding = (width - text.length()) / 2;
    cout << "|" << setfill(' ')
         << setw(padding) << "" << text
         << setw(width - padding - text.length()) << "" << "|" << endl;

    cout << "|" << setfill(border_char) << setw(width) << "" << "|" << endl;
}

/* display any menu (used for submenus) */
void Menu::display_menu(const string& title, const vector<string>& options) const {
    // Top border
    cout << setfill('=') << setw(WIDTH) << "=" << endl;

    // Title
    int padding = (WIDTH - title.length()) / 2;
    cout << setfill(' ') << setw(padding + title.length()) << title
         << setw(WIDTH - padding - title.length()) << "" << endl;

    // Bottom border
    cout << setfill('=') << setw(WIDTH) << "=" << endl;

    // Display options in a box
    for (const string& option : options) {
        format_box(option, '-', BOX_WIDTH); // calling helper function at the top
    }
}

void Menu::display_main_menu() const {
    // Top border
    cout << setfill('*') << setw(WIDTH) << "" << endl;

    // Title
    string title = "Welcome to your Personal Course Management System!";
    int padding = (WIDTH - title.length()) / 2;
    cout << setfill(' ') << setw(padding + title.length()) << title
         << setw(WIDTH - padding - title.length()) << "" << endl;

    string subtitle = "Choose where to navigate:";
    padding = (WIDTH - subtitle.length()) / 2;
    cout << setw(padding + subtitle.length()) << subtitle
         << setw(WIDTH - padding - subtitle.length()) << "" << endl;

    // Bottom border
    cout << setfill('*') << setw(WIDTH) << "" << endl;

    // Main menu options
    vector<string> main_menu_options = {
        "1. Schedule",
        "2. Attendance",
        "3. Record & View Grades",
        "4. Exit"
    };

    for (const string& option : main_menu_options) {
        format_box(option, '-', BOX_WIDTH); // using helper function for boxes
    }

}

// Handle main menu choice
bool Menu::handle_main_menu_choice(int choice) const {
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
            save_courses();
            save_grades();
            return false;

        default:
            cout << "Invalid input, returning to main menu..." << endl;
    }
    return true;
}