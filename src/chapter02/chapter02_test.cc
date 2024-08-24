// Copyright 2023 saito
#include "chapter02.hh"

#include <gtest/gtest.h>


namespace chapter02 {
TEST(add_test, sample) {
  EXPECT_EQ(3, add(1,2));
}
}  // namespace chapter02
