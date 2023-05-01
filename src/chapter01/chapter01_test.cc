// Copyright 2023 saito
#include "../../src/chapter01/chapter01.h"
#include <gtest/gtest.h>

TEST(chapter01, sum_test) {
  EXPECT_EQ(3, sum(1, 2));
}

TEST(chapter01, q1_test_case1) {
  int num = 10;
  EXPECT_EQ(33, chapter01::q1(num));
}

TEST(chapter01, q1_test_case2) {
  int num = 2;
  EXPECT_EQ(0, chapter01::q1(num));
}

TEST(chapter01, q1_test_case3) {
  int num = 15;
  EXPECT_EQ(60, chapter01::q1(num));
}
