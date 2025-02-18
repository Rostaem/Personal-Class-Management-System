cmake_minimum_required(VERSION 3.16)
project(Personal_Class_Management_System)

set(CMAKE_CXX_STANDARD 23)

add_executable(Personal_Class_Management_System
        main.cpp
        utils/schedule_management.cpp
        utils/attendance_tracker.cpp
        utils/grade_tracker.cpp
        utils/main_menu_display.cpp
        utils/ensure_data_directory.cpp
        utils/utils.cpp
)