cmake_minimum_required(VERSION 3.16)
project(Personal_Class_Management_System)


set(CMAKE_CXX_STANDARD 23)
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src/utils
)
add_executable(Personal_Class_Management_System
        main.cpp

        #features
        src/schedule_management.cpp
        src/attendance_tracker.cpp
        src/grade_tracker.cpp
        src/menu.cpp


        #utils
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
        tests/test_course_management.cpp
        src/schedule_management.cpp
        src/menu.cpp
        src/grade_tracker.cpp
        src/attendance_tracker.cpp
)

target_link_libraries(run_tests
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_tests
        DISCOVERY_MODE PRE_TEST
        EXTRA_ARGS --gtest_list_tests
)