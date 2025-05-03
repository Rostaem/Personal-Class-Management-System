cmake_minimum_required(VERSION 3.14)
project(Personal_Class_Management_System)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src/utils
)

# Main executable
add_executable(Personal_Class_Management_System
        main.cpp

        # Features
        src/schedule_management.cpp
        src/attendance_tracker.cpp
        src/grade_tracker.cpp
        src/menu.cpp

        # Utils
        src/utils/ensure_data_directory.cpp
)

#google test set up
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(run_tests
        tests/test_schedule.cpp
        src/schedule_management.cpp
        src/menu.cpp
        src/grade_tracker.cpp
        src/attendance_tracker.cpp
)

target_link_libraries(run_tests
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_tests)