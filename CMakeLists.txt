cmake_minimum_required(VERSION 3.16)
project(Personal_Class_Management_System)


set(CMAKE_CXX_STANDARD 23)

add_executable(Personal_Class_Management_System
        main.cpp

        #features
        features/schedule_management.cpp
        features/attendance_tracker.cpp
        features/grade_tracker.cpp
        features/main_menu_display.cpp

        #utils
        utils/ensure_data_directory.cpp
        utils/utils.cpp
)