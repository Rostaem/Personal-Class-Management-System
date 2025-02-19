cmake_minimum_required(VERSION 3.16)
project(Personal_Class_Management_System)


set(CMAKE_CXX_STANDARD 23)
include_directories(include)
add_executable(Personal_Class_Management_System
        main.cpp

        #features
        src/schedule_management.cpp
        src/attendance_tracker.cpp
        src/grade_tracker.cpp
        src/main_menu_display.cpp


        #utils
        utils/ensure_data_directory.cpp
        utils/utils.cpp
)