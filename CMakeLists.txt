cmake_minimum_required(VERSION 3.19)
project(cloud_computing)

set(BUILD_FLAGS "-Wall -Wextra -pedantic")

add_executable(pr1_ex1
    "${CMAKE_CURRENT_SOURCE_DIR}/Pr.\ 1/ex_1.cpp"
)

add_executable(pr1_ex2
    "${CMAKE_CURRENT_SOURCE_DIR}/Pr.\ 1/ex_2.cpp"
)

set_target_properties(pr1_ex1 pr1_ex2 #pr2_ex1
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_FLAGS ${BUILD_FLAGS}
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
