add_library(chapter02 SHARED chapter02.cc)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(chapter02_test ${CMAKE_CURRENT_SOURCE_DIR}/chapter02_test.cc)
target_link_libraries(chapter02_test chapter02 gtest gtest_main pthread)
