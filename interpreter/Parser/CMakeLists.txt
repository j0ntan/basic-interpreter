add_library(ParserHelper STATIC ParserHelper.cpp)

add_library(Parser STATIC Parser.cpp)
target_link_libraries(Parser PRIVATE
        NumericExpressions
        BooleanExpressions
        Commands
        )
