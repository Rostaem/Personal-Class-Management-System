#ifndef SCHEDULE_MANAGEMENT_H
#define SCHEDULE_MANAGEMENT_H

#include <vector>
#include <string>
using namespace std;

struct course {
	string name;
	string time;
	string professor;
	float grade;
};

extern vector<course> courses;

void manage_schedule();
void add_course();
void delete_course();
void edit_course();
void view_courses();
void save_courses();
void load_courses();

#endif // SCHEDULE_MANAGEMENT_H