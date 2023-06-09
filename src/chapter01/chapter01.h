// Copyright 2023 saito
#ifndef SRC_CHAPTER01_CHAPTER01_H_
#define SRC_CHAPTER01_CHAPTER01_H_

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <random>
#include <regex>  // NOLINT
#include <string>
#include <utility>
#include <vector>


namespace chapter01 {
unsigned int q1(int);
int q2(unsigned int, unsigned int);
int q3(unsigned int, unsigned int);
int q4(int);
std::vector<std::pair<int, int>> q5(int);
std::vector<std::pair<int, int>> q6(int);
std::vector<std::pair<int, int>> q7();
std::vector<int> q8();
std::vector<std::pair<int, int>> q9(int);
std::vector<std::pair<std::bitset<5>, std::bitset<5>>> q10();
std::string q11(unsigned int);
int q12();
double q13();
bool q14(const std::string&);
}  // namespace chapter01

#endif  // SRC_CHAPTER01_CHAPTER01_H_
