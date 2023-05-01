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

int chapter01::q3(const int kA, const int kB) {
  const int kLCM = q2(kA, kB);

  const int kAmultiple = kA / kLCM;
  const int kBmultiple = kB / kLCM;

  return kLCM * kAmultiple * kBmultiple;
}

int chapter01::q4(const int kNum) {
  if (kNum == 1) return 0;
  if (kNum == 2) return 1;

  int ret_val = 0;

  for (int i = 2; i < kNum; ++i) {
    int count = 0;

    for (int j = 1; j <= i; ++j) {
      if (i % j != 0) continue;

      count++;
    }

    if (count != 2) continue;
    if (i > ret_val) ret_val = i;
  }

  return ret_val;
}

std::vector<std::pair<int, int>> chapter01::q5(const int kNum) {
  std::vector<std::pair<int, int>> ret_val;

  if (kNum < 7) return ret_val;

  int num = 0;
  std::vector<int> lcm;

  for (int i = 2; i < kNum; ++i) {
    int count = 0;

    for (int j = 1; j <= i; ++j) {
      if (i % j) continue;

      count ++;
    }

    if (count != 2) continue;

    if (i <= num) continue;

    num = i;
    lcm.push_back(num);
  }

  for (int i = 0; i < lcm.size(); ++i) {
    auto itr = std::find(lcm.begin(), lcm.end(), lcm[i]+6);

    if (itr != lcm.end()) ret_val.push_back({lcm[i], lcm[i]+6});
  }

  return ret_val;
}

std::vector<std::pair<int, int>> chapter01::q6(const int kLimit) {
  std::vector<std::pair<int, int>> ret_val;

  if (kLimit < 1) return ret_val;

  for (int i = 1; i <= kLimit; ++i) {
    int sum = 0;

    for (int j = 1; j <= i; ++j)
      if (i%j == 0) sum += j;

    if (sum > i*2) ret_val.push_back({i, sum});
  }

  return ret_val;
}
