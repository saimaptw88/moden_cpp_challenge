#!/bin/sh

# Check argument
if [ $# -ne 1 ]; then
  echo "Need only one argument for directory name."
  exit 1
fi

# Handle command line argument
NAME=$1
UPPER_NAME=`echo $1 | tr '[a-z]' '[A-Z]'`
TEST_NAME=$1"_"test
HOME_DIR=/cpp-dev
NEW_DIR="$HOME_DIR/src/$NAME"

# Create directory
if [ -e $NEW_DIR ]; then
  echo "Directory is aleady exist."
  exit 1
else
  mkdir -p $NEW_DIR
fi

# Create files
CMAKE_FILE="$NEW_DIR/CMakeLists.txt"
CPP_FILE="$NEW_DIR/$NAME.cc"
H_FILE="$NEW_DIR/$NAME.h"
TEST_FILE=$NEW_DIR/$TEST_NAME.cc

touch $CMAKE_FILE
touch $CPP_FILE
touch $H_FILE
touch $TEST_FILE

# Write template code to CMakeTexts.txt
GTEST_ROOT='${GTEST_ROOT}'
CMAKE_ROOT='${CMAKE_CURRENT_SOURCE_DIR}'

text="add_library($NAME SHARED $NAME.cc)

# test
set(GTEST_ROOT /usr/local/)
include_directories($GTEST_ROOT/include/)
link_directories($GTEST_ROOT/lib/)

add_executable($TEST_NAME $CMAKE_ROOT/$TEST_NAME.cc)
target_link_libraries($TEST_NAME $NAME gtest gtest_main pthread)"

echo "$text" > $CMAKE_FILE

# Write template code to $NAME.h
GUARD=SRC_$UPPER_NAME"_"$UPPER_NAME"_H_"

text="// Copyright $(date +%Y) saito
#ifndef $GUARD
#define $GUARD

#include <iostream>


int sum(int, int);

#endif  // $GUARD
"
echo "$text" > $H_FILE

# Write template code to $NAME.cc
INCLUDE_FILE_NAME='"../../src/'$NAME/$NAME.h'"'
text="// Copyright $(date +%Y) saito
#include $INCLUDE_FILE_NAME


int sum(int a, int b) {
  return a + b;
}
"
echo "$text" > $CPP_FILE

# Write template code to $NAME_test.cc
text="// Copyright $(date +%Y) saito
#include $INCLUDE_FILE_NAME
#include <gtest/gtest.h>

TEST($NAME, sum_test) {
  EXPECT_EQ(3, sum(1, 2));
}
"
echo "$text" > $TEST_FILE

# Add library link to $HOME_DIR/src/CMakeLists.txt
sed -i -e "11a $NAME" $HOME_DIR/src/CMakeLists.txt

# Add subdirectory to $HOME_DIR/src/CMakeLists.txt
FILE="$HOME_DIR/src/CMakeLists.txt"
LINE=`wc -l $FILE | cut -d " " -f1`
sed -i -e "$LINE"a" add_subdirectory($NAME)" $FILE
