cmake_minimum_required(VERSION 3.9)
project(dt_optional)

set(CMAKE_CXX_STANDARD 17)

set(SRC
        example/main.cpp
        example/AddressBook.cpp
        )

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PRIVATE include)