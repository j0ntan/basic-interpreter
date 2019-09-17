add_library(Constant STATIC Constant.cpp)

add_library(Variable STATIC Variable.cpp)
target_link_libraries(Variable PRIVATE Constant)

add_library(Addition STATIC Addition.cpp)
