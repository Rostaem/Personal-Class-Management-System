cmake_minimum_required(VERSION 3.30)
project(Personal_Class_Management_System)

set(CMAKE_CXX_STANDARD 26)

add_executable(Personal_Class_Management_System
        main.cpp
        utils/schedule_management.cpp
        utils/attendance_tracker.cpp
        utils/grade_tracker.cpp
        utils/main_menu_display.cpp
)