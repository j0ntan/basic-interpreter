add_library(FormatStringSpacing FormatStringSpacing.cpp)
add_library(FormatStringSpacingTests FormatStringSpacing.test.cpp)
target_link_libraries(FormatStringSpacingTests PRIVATE FormatStringSpacing gtest)
add_executable(test_FormatStringSpacing
        $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:FormatStringSpacingTests>)
target_link_libraries(test_FormatStringSpacing PRIVATE FormatStringSpacingTests)

add_library(QueryStringProperties QueryStringProperties.cpp)
add_library(QueryStringPropertiesTests QueryStringProperties.test.cpp)
target_link_libraries(QueryStringPropertiesTests PRIVATE QueryStringProperties gtest)
add_executable(test_QueryStringProperties
        $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:QueryStringPropertiesTests>)
target_link_libraries(test_QueryStringProperties PRIVATE QueryStringPropertiesTests)

add_library(ParserHelper ParserHelper.cpp)
add_library(ParserHelperTests ParserHelper.test.cpp)
target_link_libraries(ParserHelperTests PRIVATE ParserHelper gtest)
add_executable(test_ParserHelper $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:ParserHelperTests>)
target_link_libraries(test_ParserHelper PRIVATE ParserHelperTests)


add_library(Parser Parser.cpp)
target_link_libraries(Parser PRIVATE ParserHelper NumericExpressions
        BooleanExpressions Commands)
add_library(ParserTests Parser.test.cpp)
target_link_libraries(ParserTests PRIVATE Parser gtest)
add_executable(test_Parser $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:ParserTests>)
target_link_libraries(test_Parser PRIVATE ParserTests)
