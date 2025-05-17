#ifndef COURSE_MANAGEMENT_H
#define COURSE_MANAGEMENT_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdexcept>
using namespace std;
const int WIDTH = 50;
class Course {
public:
	string name;
	string time;
	string professor;
	float grade = 0.0;

	Course() = default;
};

class CourseManager {
private:
	vector<Course> courses;

public:
	void add_course();
	void delete_course();
	void edit_course();
	void view_courses();
	void save_courses();
	void load_courses();
};
#endif //COURSE_MANAGEMENT_H
