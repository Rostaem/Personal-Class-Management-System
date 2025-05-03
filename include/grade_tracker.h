#ifndef GRADE_TRACKER_H
#define GRADE_TRACKER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <map>

extern std::unordered_map<std::string, std::vector<float>> grades_by_course;
extern std::map<std::string, std::vector<float>> sorted_grades_by_course;

void manage_grades();
void record_grade();
void calculate_grades();
void display_grades();
void save_grades();
void load_grades();
#endif // GRADE_TRACKER_H