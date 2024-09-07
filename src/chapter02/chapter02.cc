// Copyright 2023 saito
#include "chapter02.hh"

#include <functional>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>


namespace chapter02 {
void execute() {
  std::cout << "***** CHAPTER 2 *****" << std::endl;

  auto ip_address1 = Question15::IPv4("192.0.0.2");
  ip_address1.print();

  auto ip_address2 = Question15::IPv4(192, 0, 3, 2);
  ip_address2.print();


  auto ip_address3 = Question16::IPv4("255.255.255.254");
  auto ip_address4 = Question16::IPv4("255.255.254.254");

  Question16::PrintIpRange(ip_address3, ip_address4);

  using Vecs = std::vector<Question17::DoubleDimmVector<int>>;

  std::unique_ptr<Vecs> vecs;
  vecs = std::make_unique<Vecs>();

  vecs->emplace_back(10);
  vecs->emplace_back(10, 3);
  vecs->emplace_back(10, 3, 1);

  for (auto&& vec : *vecs) {
    vec.print();
  }

  std::cout << "compared = " << Question18::compare(std::greater<>(), 1,2,3,4,5,6,7,8) << std::endl;
  std::cout << "min = " << Question18::minimum(1,2,3,4,5) << std::endl;

  std::vector<int> vec { 1, 2, 3 };

  Question19::push_back(vec, 4,5,6,7,8,9);

  for (auto&& v : vec) {
    std::cout << v << std::endl;
  }

  std::vector<int> v {1,2,3,4,5};
  const int value = 7;
  const auto has_any = Question20::contains_any(v, value, 8, 9, 10, 1);
  std::cout << "has any " << value << " ? " << (has_any ? "T" : "F") << std::endl;

  const auto has_all = Question20::contains_all(v, 1, 4, 5, 6);
  std::cout << "has all ? " << (has_all ? "T" : "F") << std::endl;

  const auto has_none = Question20::contains_none(v, 0, 7, 9, 2);
  std::cout << "has none ? " << (has_none ? "T" : "F") << std::endl;
}

int add(int a, int b) {
  return a + b;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    std::string item;

    for (char ch: s) {
        if (ch == delim) {
            if (!item.empty())
                elems.push_back(item);
            item.clear();
        }
        else {
            item += ch;
        }
    }

    if (!item.empty())
        elems.push_back(item);

    return elems;
}

int to_integer(std::string str) {
  const auto size = static_cast<int>(str.size());

  int result = 0;

  for (int i = 0; i < size; ++i) {
    result *= 10;
    result += str[i] - '0';
  }

  return result;
}
}  // namespace chapter02
