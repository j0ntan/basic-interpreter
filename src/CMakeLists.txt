include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(Expressions/Numeric)

add_subdirectory(Expressions/Boolean)

add_subdirectory(Commands)

add_subdirectory(Parser)

add_subdirectory(Interpreter)

add_executable(test_ALL $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:ConstantTests>
        $<TARGET_OBJECTS:VariableTests> $<TARGET_OBJECTS:AdditionTests>
        $<TARGET_OBJECTS:SubtractionTests> $<TARGET_OBJECTS:MultiplicationTests>
        $<TARGET_OBJECTS:DivisionTests> $<TARGET_OBJECTS:LessThanTests>
        $<TARGET_OBJECTS:EqualsTests> $<TARGET_OBJECTS:PrintTests>
        $<TARGET_OBJECTS:AssignVariableTests> $<TARGET_OBJECTS:AssignArrayTests>
        $<TARGET_OBJECTS:GotoTests> $<TARGET_OBJECTS:IfThenTests>
        $<TARGET_OBJECTS:GoSubTests> $<TARGET_OBJECTS:ReturnTests>
        $<TARGET_OBJECTS:EndTests> $<TARGET_OBJECTS:ParserHelperTests>
        $<TARGET_OBJECTS:ParserTests> $<TARGET_OBJECTS:InterpreterTests>
        )
target_link_libraries(test_ALL PRIVATE Interpreter gtest)

add_subdirectory(main)
