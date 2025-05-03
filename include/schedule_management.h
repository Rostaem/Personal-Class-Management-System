#ifndef SCHEDULE_MANAGEMENT_H
#define SCHEDULE_MANAGEMENT_H

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
using namespace std;

struct course {
	string name;
	string time;
	string professor;
	float grade;
};

extern unordered_map<string, shared_ptr<course>> courses; //pointers

void manage_schedule();
void add_course();
void delete_course();
void edit_course();
void view_courses();
void save_courses();
void load_courses();
void load_courses_hybrid();
void save_courses_hybrid();
bool load_courses_binary();
void save_courses_binary();

#endif // SCHEDULE_MANAGEMENT_H