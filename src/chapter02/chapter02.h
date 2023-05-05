// Copyright 2023 saito
#ifndef SRC_CHAPTER02_CHAPTER02_H_
#define SRC_CHAPTER02_CHAPTER02_H_

#include <iostream>
#include <regex>  // NOLINT
#include <string>


int sum(int, int);
namespace chapter02 {
class ipv4 {
  public:
    bool SetAddress(const std::string&);
    bool GetAddress(std::string&);

  private:
    bool Validate(const std::string&);
    std::string ip_address_;
};
}  // namespace chapter02

#endif  // SRC_CHAPTER02_CHAPTER02_H_
