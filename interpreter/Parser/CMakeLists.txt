add_library(ParserHelper ParserHelper.cpp)
target_include_directories(ParserHelper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Parser Parser.cpp)
target_include_directories(Parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Parser PRIVATE ParserHelper NumericExpressions
        BooleanExpressions Commands)
