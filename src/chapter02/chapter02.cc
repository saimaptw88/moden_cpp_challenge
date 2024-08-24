// Copyright 2023 saito
#include "chapter02.hh"

#include <iostream>


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

namespace Question16 {

}  // namespace Question16
}  // namespace chapter02
