cmake_minimum_required(VERSION 3.30)
project(Personal_Class_Management_System)

set(CMAKE_CXX_STANDARD 26)

add_executable(Personal_Class_Management_System
        main.cpp
        schedule_management.cpp
        attendance_tracker.cpp
        grade_tracker.cpp
        main_menu_display.cpp
)