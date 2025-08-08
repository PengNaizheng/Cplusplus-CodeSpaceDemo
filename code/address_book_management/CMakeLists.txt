cmake_minimum_required(VERSION 3.10)


project(addr_book_manage VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure_file(addrConfig.h.in addrcConfig.h)


add_subdirectory(management)

add_executable(addr_book_manage main.cpp)

target_link_libraries(addr_book_manage PUBLIC management)

target_include_directories(addr_book_manage PUBLIC "${PROJECT_SOURCE_DIR}/management")

# target_include_directories()