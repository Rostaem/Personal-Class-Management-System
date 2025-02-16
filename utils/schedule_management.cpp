#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include "schedule_management.h"

#define WIDTH 50

using namespace std;

struct Class {
    string name;
    string time;
    string professor;
    float grade;
};

vector<Class> classes;

// Purpose: Manage the schedule
void manage_schedule() {
    int choice;
    do {
        string title = "Schedule Management";
        int centering = (WIDTH - title.length()) / 2;
        cout << "\n" << setfill('=') << setw(centering) << ""
             << title
             << setfill('=') << setw(WIDTH - title.length() - centering) << ""
             << endl;

        cout << "1. Add Class" << endl;
        cout << "2. Delete Class" << endl;
        cout << "3. Edit Class" << endl;
        cout << "4. View Classes" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice (1-5): ";

        cin >> choice;

        // Input validation
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            continue; // Re-prompt the user
        }

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            continue; // Re-prompt the user
        }

        // Handle valid input
        switch (choice) {
            case 1:
                add_class();
                break;
            case 2:
                delete_class();
                break;
            case 3:
                edit_class();
                break;
            case 4:
                view_classes();
                break;
            case 5:
                cout << "Returning to Main Menu..." << endl;
                break;
        }
    } while (choice != 5);
}

// Purpose: Add a new class
void add_class() {
    Class new_class;
    cout << "Enter class name: ";
    cin.ignore();
    getline(cin, new_class.name);

    if (new_class.name.empty()) {
        cout << "Class name cannot be empty. Please try again." << endl;
        return;
    }

    cout << "Enter class time: ";
    getline(cin, new_class.time);
    cout << "Enter professor's name: ";
    getline(cin, new_class.professor);

    new_class.grade = 0.0; // Default grade
    classes.push_back(new_class);

    cout << "Class added successfully!" << endl;
}

// Purpose: Delete a class
void delete_class() {
    string class_name;
    cout << "Enter the name of the class to delete: ";
    cin.ignore();
    getline(cin, class_name);

    for (auto it = classes.begin(); it != classes.end(); ++it) {
        if (it->name == class_name) {
            classes.erase(it);
            cout << "Class deleted successfully!" << endl;
            return;
        }
    }

    cout << "Class not found." << endl;
}

// Purpose: Edit a class
void edit_class() {
    string class_name;
    cout << "Enter the name of the class to edit: ";
    cin.ignore();
    getline(cin, class_name);

    for (auto &cls : classes) {
        if (cls.name == class_name) {
            cout << "Editing class: " << cls.name << endl;
            cout << "Enter new class time: ";
            getline(cin, cls.time);
            cout << "Enter new professor's name: ";
            getline(cin, cls.professor);
            cout << "Class updated successfully!" << endl;
            return;
        }
    }

    cout << "Class not found." << endl;
}

// Purpose: View all classes
void view_classes() {
    if (classes.empty()) {
        cout << "No classes available." << endl;
        return;
    }

    cout << "\n=== Class Schedule ===" << endl;
    for (const auto &cls : classes) {
        cout << "Name: " << cls.name
             << ", Time: " << cls.time
             << ", Professor: " << cls.professor << endl;
    }
}

// Purpose: Save classes to a file
void save_classes() {
    ofstream file("data/classes_data.txt");
    if (!file) {
        cout << "Error saving class data." << endl;
        return;
    }

    for (const auto &cls : classes) {
        file << cls.name << "," << cls.time << "," << cls.professor << "," << cls.grade << endl;
    }

    file.close();
    cout << "Classes saved successfully." << endl;
}

// Purpose: Load classes from a file
void load_classes() {
    ifstream file("data/classes_data.txt");
    if (!file) {
        cout << "No saved class data found." << endl;
        return;
    }

    classes.clear();
    string line;
    while (getline(file, line)) {
        Class cls;
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        cls.name = line.substr(0, pos1);
        cls.time = line.substr(pos1 + 1, pos2 - pos1 - 1);
        cls.professor = line.substr(pos2 + 1, pos3 - pos2 - 1);
        cls.grade = stof(line.substr(pos3 + 1));

        classes.push_back(cls);
    }

    file.close();
    cout << "Classes loaded successfully." << endl;
}