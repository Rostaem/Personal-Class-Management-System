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
private:
	std::vector<Course> courses;

public:
	void add_course();
	void delete_course();
	void edit_course();
	void view_courses();
	void save_courses();
	void load_courses();
	const std::vector<Course>& get_courses() const;
};