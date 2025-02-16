#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "grade_tracker.h"

using namespace std;

struct Grade {
    string class_name;
    vector<float> assignment_grades;
};

vector<Grade> grade_records;

void manage_grades() {
    int choice;
    do {
        cout << "=== Grade Tracker ===" << endl;
        cout << "1. Record Assignment Grade" << endl;
        cout << "2. Calculate Average Grade" << endl;
        cout << "3. Display Grades" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

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
    string class_name;
    cout << "Enter class name: ";
    cin.ignore();
    getline(cin, class_name);

    for (auto &record : grade_records) {
        if (record.class_name == class_name) {
            float grade;
            cout << "Enter assignment grade: ";
            cin >> grade;

            record.assignment_grades.push_back(grade);
            cout << "Grade recorded successfully!" << endl;
            return;
        }
    }

    // If class doesn't exist, create a new grade record
    Grade new_record;
    new_record.class_name = class_name;

    cout << "Enter assignment grade: ";
    float grade;
    cin >> grade;

    new_record.assignment_grades.push_back(grade);
    grade_records.push_back(new_record);

    cout << "Grade recorded successfully!" << endl;
}

void calculate_grades() {
    string class_name;
    cout << "Enter class name: ";
    cin.ignore();
    getline(cin, class_name);

    for (const auto &record : grade_records) {
        if (record.class_name == class_name) {
            if (record.assignment_grades.empty()) {
                cout << "No grades recorded for " << class_name << "." << endl;
                return;
            }

            float total = 0;
            for (float grade : record.assignment_grades) {
                total += grade;
            }

            float average = total / record.assignment_grades.size();
            cout << "Average grade for " << class_name << ": " << average << endl;
            return;
        }
    }

    cout << "Class not found in grade records." << endl;
}

void display_grades() {
    if (grade_records.empty()) {
        cout << "No grade records available." << endl;
        return;
    }

    cout << "\n=== Grade Records ===" << endl;
    for (const auto &record : grade_records) {
        cout << "Class: " << record.class_name << ", Grades: ";
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
        file << record.class_name;
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

        record.class_name = line.substr(0, next_pos);
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