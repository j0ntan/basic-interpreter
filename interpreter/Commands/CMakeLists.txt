add_library(Command INTERFACE)
target_include_directories(Command INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Print Print.cpp)
target_link_libraries(Print PUBLIC Command PRIVATE NumericExpression)

add_library(AssignVariable AssignVariable.cpp)
target_link_libraries(AssignVariable PUBLIC Command PRIVATE Variable)

add_library(AssignArray AssignArray.cpp)
target_link_libraries(AssignArray PUBLIC Command PRIVATE Variable)

add_library(Goto Goto.cpp)
target_link_libraries(Goto PUBLIC Command)

add_library(IfThen IfThen.cpp)
target_link_libraries(IfThen PUBLIC Command PRIVATE BooleanExpression)

add_library(GoSub GoSub.cpp)
target_link_libraries(GoSub PUBLIC Command)

add_library(Return Return.cpp)
target_link_libraries(Return PUBLIC Command)

add_library(End End.cpp)
target_link_libraries(End PUBLIC Command)

add_library(Commands INTERFACE)
target_link_libraries(Commands INTERFACE Print AssignVariable AssignArray Goto
        IfThen GoSub Return End)
