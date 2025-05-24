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
        src/attendance_tracker.cpp
        src/grade_tracker.cpp
        src/menu.cpp


        #utils
        src/utils/ensure_data_directory.cpp
        src/course_management.cpp
        include/course_management.h
        include/main_menu.h
        src/main_menu.cpp
        include/schedule_menu.h
        src/schedule_menu.cpp
        include/attendance_menu.h
        src/attendance_menu.cpp
)

