cmake_minimum_required(VERSION 3.14)
project(hw2)

set(CMAKE_CXX_STANDARD 11)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

file(COPY "examples" DESTINATION ${CMAKE_BINARY_DIR})

set(INTERPRETER_INCLUDE
        ${CMAKE_CURRENT_SOURCE_DIR}/interpreter
        ${CMAKE_CURRENT_SOURCE_DIR}/interpreter/NumericExpressions
        ${CMAKE_CURRENT_SOURCE_DIR}/interpreter/BooleanExpressions
        ${CMAKE_CURRENT_SOURCE_DIR}/interpreter/Commands
        ${CMAKE_CURRENT_SOURCE_DIR}/interpreter/Parser
        )

add_subdirectory(interpreter)

add_subdirectory(tests)
