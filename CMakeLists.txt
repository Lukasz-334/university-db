
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


cmake_minimum_required(VERSION 3.14)
project(University_DB)
set(CMAKE_CXX_COMPILER g++-10)


enable_testing()


set(SRC
    DataBase.cpp
    Person.cpp
    Student.cpp
    Employee.cpp
)
set(FLAGS
    -Wall
    -Wconversion
    -Wextra
    -Werror
)


add_library(University_DB-lib STATIC ${SRC})
target_compile_options(University_DB-lib PRIVATE ${FLAGS})
target_compile_features(University_DB-lib PRIVATE cxx_std_20)

add_executable(base main.cpp)
target_compile_options(base PRIVATE ${FLAGS})
target_compile_features(base PRIVATE cxx_std_20)

add_executable(test-gt test.cpp)
target_link_libraries(test-gt gtest_main)
add_test(NAME example_test COMMAND test-gt)



target_link_libraries(base University_DB-lib)
target_link_libraries(test-gt University_DB-lib)