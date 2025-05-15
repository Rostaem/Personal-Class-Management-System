#include <gtest/gtest.h>
#include <memory>
#include <schedule_management.h>
#include <unordered_map>
#include <string>
#include "schedule_management.h"
#include "utils.h"

using namespace std;

extern unordered_map<string, shared_ptr<course>> courses;

TEST(schedule_test, add_course_stores_correctly) {
	courses.clear();

	auto cls = make_shared<course>();
	cls->name = "astronomy";
	cls->time = "10:00 Am";
	cls->professor = "Isaac Miller";


	string key = to_lower(trim(cls->name));
	courses[key] = cls;

	ASSERT_TRUE(courses.count("astronomy")) << "Course 'astronomy' not found in map";
	EXPECT_EQ(courses["astronomy"]->professor, "Isaac Miller");
	EXPECT_EQ(courses["astronomy"]->time, "10:00 Am");

}