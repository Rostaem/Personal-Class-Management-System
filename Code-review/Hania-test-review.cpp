#include <gtest/gtest.h>
#include <sstream>
#include <filesystem>
#include <fstream>

// Include all necessary headers
#include "../include/schedule_management.h"
#include "../include/grade_tracker.h"
#include "../include/attendance_tracker.h"

using namespace std;
namespace fs = filesystem;

// Declare global variables from other files
extern vector<course> courses;
extern vector<Grade> grade_records;
extern vector<Attendance> attendance_records;

class CourseManagementTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Clear global state
        courses.clear();
        grade_records.clear();
        attendance_records.clear();

        // Create test directory
        fs::create_directories("test_data");
    }

    void TearDown() override {
        // Clean up test files
        try { fs::remove_all("test_data"); } catch (...) {}
    }

    // Helper to simulate user input
    void simulateInput(const string& input) {
        static stringstream ss;
        ss.str(input);
        cin.rdbuf(ss.rdbuf());
    }

    // Helper to capture output
    string captureOutput(function<void()> func) {
        testing::internal::CaptureStdout();
        func();
        return testing::internal::GetCapturedStdout();
    }
};

// 1. Tests valid course addition (Edge Case)
TEST_F(CourseManagementTest, AddCourse_ValidInput_StoresCorrectData) {
    simulateInput("Physics\n11:00 AM\nDr. Newton\n");
    add_course();

    ASSERT_EQ(courses.size(), 1);
    EXPECT_EQ(courses[0].name, "Physics");
    EXPECT_EQ(courses[0].professor, "Dr. Newton");
}

// 2. Tests invalid grade input handling (Invalid Input)
TEST_F(CourseManagementTest, RecordGrade_InvalidInput_ShowsErrorMessage) {
    courses.push_back({"Math", "9:00 AM", "Dr. Einstein", 0.0f});

    auto output = captureOutput([&]{
        simulateInput("Math\nabc\n-10\n90\n");
        record_grade();
    });

    EXPECT_TRUE(output.find("Invalid") != string::npos);
    EXPECT_EQ(grade_records[0].assignment_grades[0], 90.0f);
}

// 3. Tests empty grade calculation (Missed Edge Case)
TEST_F(CourseManagementTest, CalculateGrades_NoGrades_ShowsWarningMessage) {
    grade_records.push_back({"Chemistry", {}});

    auto output = captureOutput([&]{
        simulateInput("Chemistry\n");
        calculate_grades();
    });

    EXPECT_TRUE(output.find("No grades") != string::npos);
}

// 4. Tests attendance percentage (Logic Verification)
TEST_F(CourseManagementTest, CalculateAttendance_5of8_ReturnsCorrectPercentage) {
    attendance_records.push_back({"Biology", 8, 5});

    auto output = captureOutput([&]{
        simulateInput("Biology\n");
        calculate_attendance();
    });

    EXPECT_TRUE(output.find("62.5%") != string::npos);
}

// 5. Tests file corruption handling (Bug Identification)
TEST_F(CourseManagementTest, LoadCourses_MalformedFile_HandlesGracefully) {
    ofstream bad_file("test_data/bad_data.txt");
    bad_file << "Math,9:00 AM\n"; // Missing professor/grade
    bad_file.close();

    auto output = captureOutput([&]{
        load_courses();
    });

    EXPECT_TRUE(output.find("Skipping") != string::npos);
    EXPECT_TRUE(courses.empty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}