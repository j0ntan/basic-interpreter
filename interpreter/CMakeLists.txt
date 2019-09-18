add_library(Constant STATIC Constant.cpp)

add_library(Variable STATIC Variable.cpp)
target_link_libraries(Variable PRIVATE Constant)

add_library(Addition STATIC Addition.cpp)

add_library(Subtraction STATIC Subtraction.cpp)

add_library(Multiplication STATIC Multiplication.cpp)

add_library(Division STATIC Division.cpp)
