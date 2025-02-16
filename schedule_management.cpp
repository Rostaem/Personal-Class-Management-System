#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "schedule_management.h"

using namespace std;

struct Class {
    string name;
    string time;
    string professor;
    float grade;
};

vector<Class> classes;

void manage_schedule() {
    int choice;
    do {
        cout << "=== Schedule Management ===" << endl;
        cout << "1. Add Class" << endl;
        cout << "2. Delete Class" << endl;
        cout << "3. Edit Class" << endl;
        cout << "4. View Classes" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

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
            default:
                cout << "Invalid input, entere a numnber between 1-4." << endl;
        }
    } while (choice != 5);
}

void add_class() {
    Class new_class;
    cout << "Enter class name: ";
    cin.ignore();
    getline(cin, new_class.name);
    cout << "Enter class time: ";
    getline(cin, new_class.time);
    cout << "Enter professor's name: ";
    getline(cin, new_class.professor);

    new_class.grade = 0.0; // Default grade
    classes.push_back(new_class);

    cout << "Class added successfully!" << endl;
}

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

void view_classes() {
    if (classes.empty()) {
        cout << "No classes available." << endl;
        return;
    }

    cout << "\n=== Class Schedule ===" << endl;
    for (const auto &cls : classes) {
        cout << "Name: " << cls.name << ", Time: " << cls.time
             << ", Professor: " << cls.professor << endl;
    }
}

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