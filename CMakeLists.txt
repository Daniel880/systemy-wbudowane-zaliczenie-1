cmake_minimum_required(VERSION 3.16)
project(systemy_wbudowane_zaliczenie_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(zaliczenie	
    src/main.cpp
    src/system_info.cpp 
    src/student_output.cpp
)

target_include_directories(zaliczenie PRIVATE include)

if(MSVC)
    target_compile_options(zaliczenie PRIVATE /W4)
else()
    target_compile_options(zaliczenie PRIVATE -Wall -Wextra -Wpedantic)
endif()


