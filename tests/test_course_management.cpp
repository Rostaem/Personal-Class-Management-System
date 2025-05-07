#include <gtest/gtest.h>
#include "schedule_management.h"
#include "grade_tracker.h"

using namespace std;

void clear_global_state() {
	courses.clear();
	grade_records.clear();
}

/*
	1. Function Test: testing average grade calculation correctly
*/
TEST(grade_tracker_test, calculates_average_grade_correctly) {
	clear_global_state();

	Grade test_grade;
	test_grade.course_name = "Math";
	test_grade.assignment_grades = {90.0f, 80.0f, 70.0f};
	grade_records.push_back(test_grade);

	testing::internal::CaptureStdout();
	calculate_grades();
	string output = testing::internal::GetCapturedStdout();

	EXPECT_NE(output.find("Average grade for Math: 80"), string::npos);
}

/*
	2. Control Flow Test: deleting a course
*/
TEST(schedule_management_test, deletes_course_successfully) {
	clear_global_state();

	course test_course;
	test_course.name = "History";
	test_course.time = "10:00 AM";
	test_course.professor = "Dr. Smith";
	test_course.grade = 90.0f;
	courses.push_back(test_course);

	// Simulate user input
	testing::internal::CaptureStdout();
	istringstream input("History\n");
	cin.rdbuf(input.rdbuf());

	delete_course();
	string output = testing::internal::GetCapturedStdout();

	EXPECT_TRUE(courses.empty());
	EXPECT_NE(output.find("Course deleted successfully!"), string::npos);
}

/*
	3. Edge Case Test: adding empty course name
*/
TEST(schedule_management_test, handles_empty_course_name) {
	clear_global_state();

	istringstream input("\n");
	cin.rdbuf(input.rdbuf());

	testing::internal::CaptureStdout();
	add_course();
	string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(courses.size(), 0);
	EXPECT_NE(output.find("Course name cannot be empty"), string::npos);
}