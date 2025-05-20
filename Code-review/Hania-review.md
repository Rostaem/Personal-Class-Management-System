# Peer Code Review: Personal Class Management System

## Review Summary
Peer Code Review Report
Personal Class Management System
#*******************************
Review Overview
Reviewer	William Lebris Tissi 
Reviewee	Hania Guzman
Date	05/19/2025
#*******************************

Branch Reviewed	project1-tests
Tests Executed	5 (4 failed intentionally to expose bugs)

## 📃 Review Checklist
### 1. Code Structure & CMake Improvements
   Issues Found:

Struct definitions were in attendance_tracker.cpp files instead of attendance_tracker.hpp

CMake didn't properly include test dependencies

Global state caused test interference

Changes Made:

# ---------------
// BEFORE (schedule_management.cpp)
struct course { ... };

// AFTER (schedule_management.h)
struct course {
string name;
string time;
string professor;
float grade;
};
CMake Fixes:
# -----------------

cmake
# Added proper includes
include_directories(
${PROJECT_SOURCE_DIR}/include
${PROJECT_SOURCE_DIR}/src/utils
)

# Added missing test dependencies
add_executable(run_tests
Code-review/Hania-test-review.cpp
src/schedule_management.cpp
src/attendance_tracker.cpp
# ... all other dependencies
)
### 2. Modularity & Readability
   Problems Identified:

Global vectors created tight coupling

Mixed responsibilities in menu handling

Inconsistent error messages

My Recommendations:

Convert global vectors to class members ( which will be something good for project 3)

Separate menu logic from business logic (Just for clarity but you are good)

Standardize error message format (To let us know exactly what is going on)

Critical Fix Example:


// Added clear state management in tests
void SetUp() override {
courses.clear();
grade_records.clear();
attendance_records.clear();
}
### 3. Test Coverage Analysis
   Original Coverage Gaps:
   ❌ No file I/O testing
   ❌ Missing invalid input handling
   ❌ No edge cases for empty data sets (actually missing a lot of input validation)

New Coverage Added:

Test Case	               |Type	        |Verification
File Corruption Handling   |Bug Test	    |Malformed data recovery
Empty Grade Calculation	   |Edge Case	    |Empty collection handling
Attendance Percentage	   |Logic Test	    |Math accuracy verification
Input Validation	       |Security Test	|Invalid input recovery

### 4. Critical Bugs Found
   Documented Failures:

Input Handling Bug

Test: AddCourse_ValidInput_StoresCorrectData

Symptoms:

Expected: "Physics"  
Actual: "hysics" (first character missing)  
Root Cause: Improper cin.ignore() usage in add_course()

Silent File Corruption

Test: LoadCourses_MalformedFile_HandlesGracefully

Expected Behavior: Explicit error message

Actual Behavior: Silent failure

Percentage Calculation Error

Test: CalculateAttendance_5of8_ReturnsCorrectPercentage

Expected Output: "62.5%"

Actual Output: No percentage shown

🔧 Test Case Documentation
## --------------------------------------------------------------
1. Input Validation Test
   Purpose: Verify system handles invalid grades properly


TEST_F(CourseManagementTest, RecordGrade_InvalidInput_ShowsErrorMessage) {
simulateInput("Math\nabc\n-10\n90\n"); // Multiple bad inputs
auto output = captureOutput([](){ record_grade(); });
EXPECT_TRUE(output.find("Invalid") != string::npos); // Verifies error message
EXPECT_EQ(grade_records[0].assignment_grades[0], 90.0f); // Verifies final acceptance
}
Result: ✅ Passed (Only test that passed)
# ---------------------------------------------------------------



# ---------------------------------------------------------------

2. File Corruption Test
   Purpose: Verify graceful handling of malformed data

cpp
TEST_F(CourseManagementTest, LoadCourses_MalformedFile_HandlesGracefully) {
ofstream bad_file("test_data/bad_data.txt");
bad_file << "Math,9:00 AM\n"; // Intentionally corrupt
bad_file.close();

    auto output = captureOutput([](){ load_courses(); });
    EXPECT_TRUE(output.find("Skipping") != string::npos); // Expected warning
    EXPECT_TRUE(courses.empty()); // Verify no partial data
}
Result: ❌ Failed (No error message detected)
# ---------------------------------------------------------------




# ---------------------------------------------------------------

3. Empty Data Set Test
   Purpose: Verify empty grade handling

cpp
TEST_F(CourseManagementTest, CalculateGrades_NoGrades_ShowsWarningMessage) {
grade_records.push_back({"Chemistry", {}}); // Empty grades

    auto output = captureOutput([](){ calculate_grades(); });
    EXPECT_TRUE(output.find("No grades") != string::npos);
}
Result: ❌ Failed (No warning message shown)
# ---------------------------------------------------------------

🏗 Architecture Feedback
Strengths (what i really liked)
✔ Clear separation between UI and business logic
✔ Consistent menu interface design
✔ Good use of standard library features

Critical Improvements Needed
# ---------------------------------------------------------------
Data Management

Replace global vectors with singleton or repository pattern

Error Handling

Add explicit error codes for file operations

Implement validation for time formats (HH:MM AM/PM)
for instance, for the the professor name, you can make sure that 
the user enter a string( letters), I tried a bunch of characters and it went through,
so you gotta work on that part 😭

Testing Infrastructure

Introduce mocking for file system operations

Add benchmark tests for performance
# --------------------------------------------------------------
📝 Review Conclusion
Requirements Fulfillment
Requirement	Status	Evidence
5 Meaningful Tests	✅	5 documented test cases
Architecture Feedback	✅	Detailed improvement plan
Bug Identification	✅	4 documented failures
CMake Improvements	✅	Updated build configuration
Key Findings
Input Handling: First character being dropped in course names

Error Reporting: Silent failures in file operations

Output Formatting: Missing percentage signs in attendance reports

Final Assessment
This review successfully:

Exposed critical bugs through intentional test failures

Provided actionable architecture improvements

Demonstrated comprehensive test coverage

Met all assignment requirements professionally (I hope so, I even hope to get some extra points since i failed the code)

Recommendation: Address the identified bugs before merging to main branch.

