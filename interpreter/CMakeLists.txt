include_directories(NumericExpressions BooleanExpressions Commands Parser)

add_subdirectory(NumericExpressions)

add_subdirectory(BooleanExpressions)

add_subdirectory(Commands)

add_subdirectory(Parser)

add_library(Interpreter STATIC Interpreter.cpp)
target_link_libraries(Interpreter PRIVATE Parser ParserHelper)
