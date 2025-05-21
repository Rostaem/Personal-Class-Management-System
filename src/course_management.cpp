#include "course_management.h"
#include <fstream>
#include <iomanip>

void CourseManager::load_courses() {
	ifstream file("data/courses.txt");
	Course course;
	while (getline(file, course.code) &&
		   getline(file, course.name) &&
		   getline(file, course.instructor)) {
		courses.push_back(course);
		   }
}

void CourseManager::save_courses() const {
	ofstream file("data/courses.txt");
	for (const Course& course : courses) {
		file << course.code << endl
			 << course.name << endl
			 << course.instructor << endl;
	}
}

void CourseManager::view_courses() const {
	cout << "Courses:" << endl;
	for (const Course& course : courses) {
		cout << setw(10) << left << course.code
			 << setw(30) << course.name
			 << setw(20) << course.instructor << endl;
	}
}

const vector<Course>& CourseManager::get_courses() const {
	return courses;
}