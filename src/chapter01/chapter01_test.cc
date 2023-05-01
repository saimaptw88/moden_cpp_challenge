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

// 片方が最大公約数になる
TEST(chapter01, q2_test_case1) {
  EXPECT_EQ(5, chapter01::q2(5, 15));
}

// 最大公約数が1
TEST(chapter01, q2_test_case2) {
  EXPECT_EQ(1, chapter01::q2(10, 33));
}

// 同じ値
TEST(chapter01, q2_test_case3) {
  EXPECT_EQ(10, chapter01::q2(10, 10));
}

// 普通
TEST(chapter01, q2_test_case4) {
  EXPECT_EQ(3, chapter01::q2(24, 15));
}

// 普通
TEST(chapter01, q3_test_case1) {
  EXPECT_EQ(12, chapter01::q3(3, 4));
}

// 最小公倍数が片方の値
TEST(chapter01, q3_test_case2) {
  EXPECT_EQ(12, chapter01::q3(3, 12));
}

// 同じ値
TEST(chapter01, q3_test_case3) {
  EXPECT_EQ(3, chapter01::q3(3, 3));
}
