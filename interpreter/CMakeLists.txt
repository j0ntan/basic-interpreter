add_subdirectory(NumericExpressions)

add_subdirectory(BooleanExpressions)

add_subdirectory(Commands)

add_subdirectory(Parser)

add_library(Interpreter Interpreter.cpp)
target_include_directories(Interpreter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Interpreter PUBLIC Command PRIVATE Parser)
