add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run MainNetworkTest.cpp)

# linking Google_Tests_run with DateConverter_lib which will be tested
target_link_libraries(Google_Tests_run Src)

target_link_libraries(Google_Tests_run gtest gtest_main)

include_directories(../Src)
add_definitions(-DBUILD_FOR_TESTING)