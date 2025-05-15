#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
#include "grade_tracker.h"
#include "schedule_management.h"
#include "utils/utils.h"
#include "menu.h"

using namespace std;

struct Grade {
    string course_name;
    vector<float> assignment_grades;
};

unordered_map<string, vector<float>> grades_by_course;
map<string, vector<float>> sorted_grades_by_course;

// Purpose: Displays the grade tracker menu and handles user input

void manage_grades() {
    Menu menu;

    string submenu_title = "Grade Tracker";
    vector<string> submenu_options = {
        "1. Record Assignment Grade",
        "2. Calculate Average Grade",
        "3. Display Grades",
        "4. Back to Main Menu"
    };

    int choice;
    do {
        menu.display_menu(submenu_title, submenu_options); // Updated to use display_menu
        choice = input_validation(1, 4, "Enter your choice (1-4): ");

        switch (choice) {
            case 1:
                record_grade();
            break;
            case 2:
                calculate_grades();
            break;
            case 3:
                display_grades();
            break;
            case 4:
                cout << "Returning to Main Menu." << endl;
            break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

void record_grade() {
    string course_name;
    cout << "Enter course name: ";
    getline(cin, course_name);
    course_name = trim(course_name);

    float grade = input_validation(0.0f, 100.0f, "Enter your grade: ");

    string key = to_lower(course_name);
    grades_by_course[key].push_back(grade);
    sorted_grades_by_course[course_name].push_back(grade);
    cout << "Grade recorded succesfully..." << endl;
}

void calculate_grades() {
    string course_name;
    cout << "Enter course name: ";
    getline(cin, course_name);
    course_name = trim(course_name);
    string key = to_lower(course_name);

    auto it = grades_by_course.find(key);
    if (it == grades_by_course.end()) {
        cout << "Course not found in grade records " << endl;
        return;
    }

    const vector<float>& grades = it->second;
    if (grades.empty()) {
        cout << "No grades recorded for " << course_name << endl;
        return;
    }

    float total = 0;
    for (float grade : grades) {
        total += grade;
    }

    float average = total / grades.size();
    cout << fixed << setprecision(2);
    cout << "Average grade: " << course_name << ": " << average << endl;
}


void display_grades() {
    if (sorted_grades_by_course.empty()) {
        cout << "No grade records found..." << endl;
        return;
    }

    cout << "\n=== Grade Records ===" << endl; //improve formatting
    for (const auto& [course_name, grades] : sorted_grades_by_course) {
        cout << setw(20) << left << course_name << ": ";

        for (float grade : grades) {
            cout << fixed << setprecision(1) << grade << " ";
        }

        cout << endl;
    }
}

void save_grades() {
    ofstream file("data/grades_data.txt");
    if (!file) {
        cout << "Error saving grade data." << endl;
        return;
    }

    for (const auto& [course_name, grades] : sorted_grades_by_course) {
        file << course_name;
        for (float grade : grades) {
            file << "," << grade;
        }
        file << endl;
    }

    file.close();
    cout << "Grade data saved successfully." << endl;
}

void load_grades() {
    ifstream file("data/grades_data.txt");
    if (!file) {
        cout << "No saved grade data found." << endl;
        return;
    }

    grades_by_course.clear();
    sorted_grades_by_course.clear();

    string line;
    while (getline(file, line)) {
        size_t pos = 0;
        size_t next_pos = line.find(',');

        string course_name = line.substr(0, next_pos);
        string key = to_lower(course_name);

        vector<float> grades;
        pos = next_pos + 1;

        while ((next_pos = line.find(',', pos)) != string::npos) {
            grades.push_back(stof(line.substr(pos, next_pos - pos)));
            pos = next_pos + 1;
        }

        if (pos < line.size()) {
            grades.push_back(stof(line.substr(pos)));
        }

        grades_by_course[key] = grades;
        sorted_grades_by_course[course_name] = grades;
    }

    file.close();
    cout << "Grade data loaded successfully..." << endl;
}