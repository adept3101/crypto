cmake_minimum_required(VERSION 3.16)

project(Qt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ui
    main.cc
    main_window.cc
    main_window.h
)

target_link_libraries(ui
    Qt6::Widgets
)
