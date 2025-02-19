cmake_minimum_required(VERSION 3.16)
project(Personal_Class_Management_System)


set(CMAKE_CXX_STANDARD 23)

add_executable(Personal_Class_Management_System
        main.cpp

        #features
        src/features/schedule_management.cpp
        src/features/attendance_tracker.cpp
        src/features/grade_tracker.cpp
        src/features/main_menu_display.cpp
        src/features/

        #utils
        utils/ensure_data_directory.cpp
        utils/utils.cpp
)