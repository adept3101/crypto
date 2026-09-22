cmake_minimum_required(VERSION 3.16)

project(main LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(main
    src/ui/main.cc
    src/ui/main_window.cc
    src/ui/main_window.h
    src/crypto/encryptor.cc
    src/crypto/encryptor.h
)

target_include_directories(main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/crypto
)

target_link_libraries(main PRIVATE
    Qt6::Widgets
    sodium
)
