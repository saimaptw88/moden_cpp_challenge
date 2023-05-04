// Copyright 2023 saito
#include "../../src/chapter01/chapter01.h"
#include <gtest/gtest.h>


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

// 3
TEST(chapter01, q4_test_case1) {
  EXPECT_EQ(3, chapter01::q4(4));
}

// 1
TEST(chapter01, q4_test_case2) {
  EXPECT_EQ(0, chapter01::q4(1));
}

// 普通
TEST(chapter01, q4_test_case3) {
  EXPECT_EQ(23, chapter01::q4(25));
}

// 2
TEST(chapter01, q4_test_case4) {
  EXPECT_EQ(2, chapter01::q4(2));
}

// ペアなし
TEST(chapter01, q5_test_case1) {
  EXPECT_EQ(0, chapter01::q5(3).size());
}

// 1組
TEST(chapter01, q5_test_case2) {
  EXPECT_EQ(1, chapter01::q5(12).size());
}

// 2組
TEST(chapter01, q5_test_case3) {
  EXPECT_EQ(2, chapter01::q5(14).size());
}

// 0組
TEST(chapter01, q6_test_case1) {
  EXPECT_EQ(0, chapter01::q6(1).size());
}

// 1組
TEST(chapter01, q6_test_case2) {
  EXPECT_EQ(1, chapter01::q6(13).size());
}

// 3組
TEST(chapter01, q6_test_case3) {
  EXPECT_EQ(3, chapter01::q6(20).size());
}

TEST(chapter01, q7_test_case1) {
  EXPECT_EQ(57, chapter01::q7().size());
}

TEST(chapter01, q8_test_case1) {
  EXPECT_EQ(4, chapter01::q8().size()); // 153, 370, 371, 407
}

TEST(chapter01, q9_test_case1) {
  EXPECT_EQ(2, chapter01::q9(10).size());
}

TEST(chapter01, q11_test_case1) {
  EXPECT_EQ("XXX", chapter01::q11(30));
}

TEST(chapter01, q11_test_case2) {
  EXPECT_EQ("CDXLIV", chapter01::q11(444));
}

TEST(chapter01, q12_test_case1) {
  EXPECT_EQ(837799, chapter01::q12());
}
