#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip> // For centering the title
#include "grade_tracker.h"

#include "schedule_management.h"

using namespace std;
const int WIDTH = 50;
struct Grade {
    string course_name;
    vector<float> assignment_grades;
};

vector<Grade> grade_records;

void print_title(const string &title) {
    cout << string((WIDTH - title.length()) / 2, ' ') << title << endl;
}

void manage_grades() {
    int choice;
    do {
        print_title("=== Grade Tracker ==="); // improve formatting
        cout << "1. Record Assignment Grade" << endl;
        cout << "2. Calculate Average Grade" << endl;
        cout << "3. Display Grades" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max());
            cout << "Invalid input. Please enter a choice between 1 and 4: ";
            cin >> choice;
        }

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
    cin.ignore();
    getline(cin, course_name);

    for (auto &record : grade_records) {
        if (record.course_name == course_name) {
            float grade;
            cout << "Enter assignment grade (0 - 100): "; // in the future implement letter grade conversion
            cin >> grade;

            while (cin.fail() || grade < 0 || grade > 100) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid grade. Please enter a grade between 0 and 100: ";
                cin >> grade;
            }

            record.assignment_grades.push_back(grade);
            cout << "Grade recorded successfully!" << endl;
            return;
        }
    }

    Grade new_record;
    new_record.course_name = course_name;

    cout << "Enter assignment grade: ";
    float grade;
    cin >> grade;

    while (cin.fail() || grade < 0 || grade > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max());
        cout << "Invalid grade. Please enter a grade between 0 and 100: ";
        cin >> grade;
    }

    new_record.assignment_grades.push_back(grade);
    grade_records.push_back(new_record);

    cout << "Grade recorded successfully!" << endl;
}

void calculate_grades() {
    string course_name;
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, course_name);

    for (const auto &record : grade_records) {
        if (record.course_name == course_name) {
            if (record.assignment_grades.empty()) {
                cout << "No grades recorded for " << course_name << "." << endl;
                return;
            }

            float total = 0;
            for (float grade : record.assignment_grades) {
                total += grade;
            }

            float average = total / record.assignment_grades.size();
            cout << "Average grade for " << course_name << ": " << average << endl;
            return;
        }
    }

    cout << "Course not found in grade records." << endl;
}

void display_grades() {
    if (grade_records.empty()) {
        cout << "No grade records available." << endl;
        return;
    }

    cout << "\n=== Grade Records ===" << endl;
    for (const auto &record : grade_records) {
        cout << "Course: " << record.course_name << ", Grades: ";
        for (float grade : record.assignment_grades) {
            cout << grade << " ";
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

    for (const auto &record : grade_records) {
        file << record.course_name;
        for (float grade : record.assignment_grades) {
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

    grade_records.clear();
    string line;
    while (getline(file, line)) {
        Grade record;
        size_t pos = 0;
        size_t next_pos = line.find(',');

        record.course_name = line.substr(0, next_pos);
        pos = next_pos + 1;

        while ((next_pos = line.find(',', pos)) != string::npos) {
            record.assignment_grades.push_back(stof(line.substr(pos, next_pos - pos)));
            pos = next_pos + 1;
        }
        record.assignment_grades.push_back(stof(line.substr(pos)));

        grade_records.push_back(record);
    }

    file.close();
    cout << "Grade data loaded successfully." << endl;
}