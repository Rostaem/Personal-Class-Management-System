#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include <memory>
#include "schedule_management.h"
#include "menu.h"
#include "utils/utils.h"

#define WIDTH 50

using namespace std;

vector<shared_ptr<course>> courses;

void manage_schedule() {
    Menu menu;
// this is what gets sent to submenu
    string submenu_title = "Schedule Management";
    vector<string> submenu_options = {
        "1. Add Course",
        "2. Delete Course",
        "3. Edit Course",
        "4. View Courses",
        "5. Back to Main Menu"
    };

    int choice;
    do { // do while loop for showing this submenu repeatedly
        menu.display_menu(submenu_title, submenu_options);
        choice = input_validation(1, 5, "Enter your choice (1-5): ");

        switch (choice) { //modular design : different functions
            case 1:
                add_course();
            break;
            case 2:
                delete_course();
            break;
            case 3:
                edit_course();
            break;
            case 4:
                view_courses();
            break;
            case 5:
                cout << "Returning to Main Menu..." << endl;
            break;
        }
    } while (choice != 5);
}

void add_course() {
    auto new_course = make_shared<course>(); //shared ptr

    cout << "Enter course name: ";
     cin.ignore();
    getline(cin, new_course->name);

    if (new_course->name.empty()) {
        cout << "Course name cannot be empty. Please try again." << endl;
        return;
    }

    cout << "Enter course time (ex 9:00 AM): ";
    getline(cin, new_course->time);

    cout << "Enter professor's name: ";
    getline(cin, new_course->professor);

    new_course->grade = 0.0;
    courses.push_back(new_course);

    cout << "Course added successfully!" << endl;
}

void delete_course() {
    string course_name;
    cin.ignore();
    cout << "Enter the name of the course to delete: ";
    getline(cin, course_name);

    for (auto it = courses.begin(); it != courses.end(); ++it) { // for loop that iterates through a list of courses to find and delete a course by its name
        if ((*it)->name == course_name) { // dereference shared_ptr
            courses.erase(it); //Removes the course object from the courses container at the position pointed to by the iterator it.
            cout << "Course deleted successfully!" << endl;
            return;
        }
    }

    cout << "Course not found." << endl;
}

void edit_course() {
    string course_name;
    cin.ignore();
    cout << "Enter the name of the course to edit: ";
    getline(cin, course_name);

    for (auto &cls : courses) {
        if (cls->name == course_name) { // Checks if the name of the current course (cls.name) matches the course_name entered by the user.
            cout << "Editing course: " << cls->name << endl;

            cout << "Enter new course time (current: " << cls->time << "): ";
            getline(cin, cls->time);

            cout << "Enter new professor's name (current: " << cls->professor << "): ";
            getline(cin, cls->professor);

            cout << "Course updated successfully!" << endl;
            return;
        }
    }

    cout << "Course not found. Returning to menu." << endl;
}

void view_courses() {
    if (courses.empty()) {
        cout << "No courses available." << endl;
        return;
    }
//display the table, consider making a helper function down the line
    string header = "Course Schedule";
    int header_centering = (WIDTH - header.length()) / 2;
    cout << endl << setfill(' ') << setw(header_centering) << "" << header << endl;

    cout << setfill('-') << setw(WIDTH) << "" << endl;
    cout << setfill(' ') << left
         << setw(20) << "Name"
         << setw(15) << "Time"
         << setw(15) << "Professor" << endl;
    cout << setfill('-') << setw(WIDTH) << "" << endl;

    for (const auto &cls : courses) {
        cout << setfill(' ') << left
             << setw(20) << cls->name
             << setw(15) << cls->time
             << setw(15) << cls->professor << endl;
    }
//bottom line
    cout << setfill('-') << setw(WIDTH) << "" << endl;
}

void save_courses() { // never being caled, fix
    ofstream file("data/courses_data.txt");
    if (!file) {
        cout << "Error: Unable to save course data." << endl;
        return;
    }

    for (const auto &cls : courses) {
        file << cls->name << "," << cls->time << "," << cls->professor << "," << cls->grade << endl;
    }

    file.close();
    cout << "Courses saved successfully!" << endl;
}

void load_courses() {
    ifstream file("data/courses_data.txt");
    if (!file) {
        cout << "No saved course data found." << endl;
        return;
    }

    courses.clear();
    string line;
    while (getline(file, line)) {
        auto cls = make_shared<course>(); //change smart pointer
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
            cout << "Error: Malformed line in file. Skipping..." << endl;
            continue;
        }

        cls->name = line.substr(0, pos1);
        cls->time = line.substr(pos1 + 1, pos2 - pos1 - 1);
        cls->professor = line.substr(pos2 + 1, pos3 - pos2 - 1);

        try {
            cls->grade = stof(line.substr(pos3 + 1));
        } catch (const invalid_argument &) {
            cout << "Error: Invalid grade format. Skipping..." << endl;
            continue;
        }

        courses.push_back(cls);
    }

    file.close();
    cout << "Courses loaded successfully!" << endl;
}