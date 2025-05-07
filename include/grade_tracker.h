#ifndef GRADE_TRACKER_H
#define GRADE_TRACKER_H
#include <string>
#include <vector>

struct Grade {
	std::string course_name;
	std::vector<float> assignment_grades;
};

extern std::vector<Grade> grade_records;

void manage_grades();
void record_grade();
void calculate_grades();
void display_grades();

void save_grades();
void load_grades();

#endif // GRADE_TRACKER_H