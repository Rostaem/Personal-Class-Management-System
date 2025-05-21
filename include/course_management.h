#ifndef COURSE_MANAGEMENT_H
#define COURSE_MANAGEMENT_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Course {
	string code;
	string name;
	string instructor;
};

class CourseManager {
private:
	vector<Course> courses;

public:
	void load_courses();
	void save_courses() const;
	void view_courses() const;
	const vector<Course>& get_courses() const;
};

#endif // COURSE_MANAGEMENT_H
