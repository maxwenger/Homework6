add_executable(dict_test main.cpp unit_test.cpp)

include_directories(${CMAKE_LIBRARY_PATH})
link_directories(${LIBRARY_OUTPUT_PATH})

target_link_libraries(
        dict_test
                    gtest)

add_test(
        NAME
        BinarySearchTreeTests
        COMMAND
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/unit_test
)