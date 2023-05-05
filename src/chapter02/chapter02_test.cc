// Copyright 2023 saito
#include "../../src/chapter02/chapter02.h"
#include <gtest/gtest.h>

TEST(chapter02, sum_test) {
  EXPECT_EQ(3, sum(1, 2));
}

TEST(chapter02, ipv4_test_case1) {
  chapter02::ipv4 ipv4 = chapter02::ipv4();

  EXPECT_TRUE(ipv4.SetAddress("192.168.0.11"));
}

TEST(chapter02, ipv4_test_case2) {
  chapter02::ipv4 ipv4 = chapter02::ipv4();

  EXPECT_FALSE(ipv4.SetAddress("192.168.0"));
  EXPECT_FALSE(ipv4.SetAddress("192.168.0."));
  EXPECT_FALSE(ipv4.SetAddress("192.168.0.11.0"));
}

TEST(chapter02, ipv4_test_case3) {
  chapter02::ipv4 ipv4 = chapter02::ipv4();

  EXPECT_FALSE(ipv4.SetAddress("192.168.0.1000"));
  EXPECT_FALSE(ipv4.SetAddress("192.168.0."));
}

TEST(chapter02, ipv4_test_case4) {
  chapter02::ipv4 ipv4 = chapter02::ipv4();

  EXPECT_FALSE(ipv4.SetAddress("192.168.i.1"));
}

TEST(chapter02, ipv4_test_case5) {
  chapter02::ipv4 ipv4 = chapter02::ipv4();

  std::string address;
  EXPECT_TRUE(ipv4.SetAddress("192.168.0.1"));
  EXPECT_TRUE(ipv4.GetAddress(address));
  EXPECT_EQ("192.168.0.1", address);
}

TEST(chapter02, ipv4_test_case6) {
  chapter02::ipv4 ipv4 = chapter02::ipv4();

  std::string address;
  EXPECT_FALSE(ipv4.SetAddress("192.168.0."));
  EXPECT_FALSE(ipv4.GetAddress(address));
  EXPECT_EQ("", address);
}
