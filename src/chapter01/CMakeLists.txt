add_library(chapter01 SHARED chapter01.cc)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(chapter01_test ${CMAKE_CURRENT_SOURCE_DIR}/chapter01_test.cc)
target_link_libraries(chapter01_test chapter01 gtest gtest_main pthread)
