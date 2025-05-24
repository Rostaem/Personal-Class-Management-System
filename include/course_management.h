#pragma once

#include <string>
#include <vector>
#include <iostream>

struct Course {
	std::string name;
	std::string time;
	std::string professor;
	float grade = 0.0f;
};

class CourseManager {

public:
	std::vector<Course> courses;
	CourseManager() {
		if (courses.size() == 0) {
			load_courses();
		}
	}
	void add_course();
	void delete_course();
	void edit_course();
	void view_courses();
	void save_courses();
	void load_courses();
	const std::vector<Course>& get_courses() const;
};