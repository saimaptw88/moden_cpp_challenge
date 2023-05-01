// Copyright 2023 saito
#include "../../src/chapter01/chapter01.h"


int sum(int a, int b) {
  return a + b;
}

int chapter01::q1(const int kNum) {
  int sum = 0;
  for (int i = 1; i < 1 + kNum; ++i) {
    if (i % 3 == 0) sum+=i;
    else if (i % 5 == 0) sum+=i;
  }

  return sum;
}

int chapter01::q2(const int kA, const int kB) {
  const int kMax = std::max(kA, kB);

  int ret_val = 1;
  for (int i = 1; i < kMax+1; ++i) {
    if (kA%i) continue;
    if (kB%i) continue;

    ret_val = i;
  }

  return ret_val;
}
