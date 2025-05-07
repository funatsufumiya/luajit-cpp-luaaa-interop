cmake_minimum_required(VERSION 3.10)
project(luajit-cpp-luaaa-interop)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LUAJIT REQUIRED luajit)

include_directories(
    ${LUAJIT_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/luaaa
)
link_directories(${LUAJIT_LIBRARY_DIRS})

set(LIB_SOURCES
    src/example.cpp
)

add_library(example SHARED ${LIB_SOURCES})
target_link_libraries(example ${LUAJIT_LIBRARIES})

add_executable(luajit-cpp-luaaa-interop src/main.cpp)
target_link_libraries(luajit-cpp-luaaa-interop ${LUAJIT_LIBRARIES} example)

file(COPY ${CMAKE_SOURCE_DIR}/scripts/ DESTINATION ${CMAKE_BINARY_DIR}/scripts/)
