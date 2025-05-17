#include "course_management.h"
void CourseManager::add_course() {
    Course new_course;
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, new_course.name);

    if (new_course.name.empty()) {
        cout << "Course name cannot be empty. Please try again." << endl;
        return;
    }

    cout << "Enter course time (ex 9:00 AM): ";
    getline(cin, new_course.time);

    cout << "Enter professor's name: ";
    getline(cin, new_course.professor);

    new_course.grade = 0.0;
    courses.push_back(new_course);

    cout << "Course added successfully!" << endl;
}

void CourseManager::delete_course() {
    string course_name;
    cout << "Enter the name of the course to delete: ";
    cin.ignore();
    getline(cin, course_name);

    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (it->name == course_name) {
            courses.erase(it);
            cout << "Course deleted successfully!" << endl;
            return;
        }
    }

    cout << "Course not found." << endl;
}

void CourseManager::edit_course() {
    string course_name;
    cout << "Enter the name of the course to edit: ";
    cin.ignore();
    getline(cin, course_name);

    for (auto &cls : courses) {
        if (cls.name == course_name) {
            cout << "Editing course: " << cls.name << endl;

            cout << "Enter new course time (current: " << cls.time << "): ";
            getline(cin, cls.time);

            cout << "Enter new professor's name (current: " << cls.professor << "): ";
            getline(cin, cls.professor);

            cout << "Course updated successfully!" << endl;
            return;
        }
    }

    cout << "Course not found. Returning to menu." << endl;
}

void CourseManager::view_courses() {
    if (courses.empty()) {
        cout << "No courses available." << endl;
        return;
    }

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
             << setw(20) << cls.name
             << setw(15) << cls.time
             << setw(15) << cls.professor << endl;
    }

    cout << setfill('-') << setw(WIDTH) << "" << endl;
}

void CourseManager::save_courses() {
    ofstream file("data/courses_data.txt");
    if (!file) {
        cout << "Error: Unable to save course data." << endl;
        return;
    }

    for (const auto &cls : courses) {
        file << cls.name << "," << cls.time << "," << cls.professor << "," << cls.grade << endl;
    }

    file.close();
    cout << "Courses saved successfully!" << endl;
}

void CourseManager::load_courses() {
    ifstream file("data/courses_data.txt");
    if (!file) {
        cout << "No saved course data found." << endl;
        return;
    }

    courses.clear();
    string line;
    while (getline(file, line)) {
        Course cls;
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
            cout << "Error: Malformed line in file. Skipping..." << endl;
            continue;
        }

        cls.name = line.substr(0, pos1);
        cls.time = line.substr(pos1 + 1, pos2 - pos1 - 1);
        cls.professor = line.substr(pos2 + 1, pos3 - pos2 - 1);

        try {
            cls.grade = stof(line.substr(pos3 + 1));
        } catch (const invalid_argument &) {
            cout << "Error: Invalid grade format. Skipping..." << endl;
            continue;
        }

        courses.push_back(cls);
    }

    file.close();
    cout << "Courses loaded successfully!" << endl;
}
