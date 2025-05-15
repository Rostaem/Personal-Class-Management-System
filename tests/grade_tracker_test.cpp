#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>
#include "grade_tracker.h"
#include "utils.h"

using namespace std;

TEST(GradeTrackerTest, RecordAndCalculateAverage) {
	grades_by_course.clear();
	sorted_grades_by_course.clear();

	string course_name = "Physics";
	string key = to_lower(course_name);

	grades_by_course[key] = {85.0f, 95.0f};
	sorted_grades_by_course[course_name] = {85.0f, 95.0f};

	ASSERT_EQ(grades_by_course[key].size(), 2);
	ASSERT_EQ(sorted_grades_by_course[course_name].size(), 2);

	const vector<float>& grades = grades_by_course[key];
	float total = 0;
	for (float g : grades) total += g;
	float average = total / grades.size();

	//check avg is correct
	ASSERT_FLOAT_EQ(average, 90.0f);
}