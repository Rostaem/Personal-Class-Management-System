#include "menu.h"
#include "schedule_management.h"
#include "attendance_tracker.h"
#include "grade_tracker.h"
#include <iostream>
#include <iomanip>
using namespace std;

Menu::Menu() {}

// Display the main menu
void Menu::display_main_menu() const {
    // top border
    cout << setfill('*') << setw(WIDTH) << "" << endl;

    // title
    string title = "Welcome to your Personal Course Management System!";
    int padding = (WIDTH - title.length()) / 2;
    cout << setfill(' ') << setw(padding + title.length()) << title
         << setw(WIDTH - padding - title.length()) << "" << endl;

    string subtitle = "Choose where to navigate:";
    padding = (WIDTH - subtitle.length()) / 2;
    cout << setw(padding + subtitle.length()) << subtitle
         << setw(WIDTH - padding - subtitle.length()) << "" << endl;

    // bottom border
    cout << setfill('*') << setw(WIDTH) << "" << endl;

    vector<string> menu_options = {
        "1. Schedule",
        "2. Attendance",
        "3. Record & View Grades",
        "4. Exit"
    };

    // box for menu options
    for (const string& option : menu_options) {
        // Top border
        cout << "|" << setfill('-') << setw(BOX_WIDTH) << "-" << "|" << endl;

        // Centered
        int option_padding = (BOX_WIDTH - option.length()) / 2;
        cout << "|" << setfill(' ')
             << setw(option_padding) << "" << option
             << setw(BOX_WIDTH - option_padding - option.length()) << "" << "|" << endl;

        // Bottom border
        cout << "|" << setfill('-') << setw(BOX_WIDTH) << "-" << "|" << endl;
    }

    cout << "Enter your choice: ";
}

void Menu::submenu_formatting(const string& submenu_title, const vector<string>& submenu_options) const {
    cout << setfill('=') << setw(WIDTH) << "=" << endl;

    int padding = (WIDTH - submenu_title.length()) / 2;
    cout << setfill(' ') << setw(padding + submenu_title.length()) << submenu_title
         << setw(WIDTH - padding - submenu_title.length()) << "" << endl;

    cout << setfill('=') << setw(WIDTH) << "=" << endl;

    for (const string& option : submenu_options) {
        cout << "|" << setfill('-') << setw(BOX_WIDTH) << "" << "|" << endl;

        int option_padding = (BOX_WIDTH - option.length()) / 2;
        cout << "|" << setfill(' ')
             << setw(option_padding) << "" << option
             << setw(BOX_WIDTH - option_padding - option.length()) << "" << "|" << endl;

        cout << "|" << setfill('-') << setw(BOX_WIDTH) << "" << "|" << endl;
    }
}

void Menu::display_submenu(const string& submenu_title, const vector<string>& submenu_options) const {
    cout << setfill('=') << setw(WIDTH) << " " << endl;

    int padding = (WIDTH - submenu_title.length()) / 2;
    cout << setfill(' ') << setw(padding + submenu_title.length()) << submenu_title
         << setw(WIDTH - padding - submenu_title.length()) << "" << endl;

    cout << setfill('=') << setw(WIDTH) << " " << endl;

    // options
    for (const string& option : submenu_options) {
        cout << "|" << setfill('-') << setw(BOX_WIDTH) << "" << "|" << endl;

        int option_padding = (BOX_WIDTH - option.length()) / 2;
        cout << "|" << setfill(' ')
             << setw(option_padding) << "" << option
             << setw(BOX_WIDTH - option_padding - option.length()) << "" << "|" << endl;

        cout << "|" << setfill('-') << setw(BOX_WIDTH) << "" << "|" << endl;
    }
}

//input handling
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
            return false;

        default:
            cout << "Invalid input, returning to main menu..." << endl;
    }
    return true;
}
