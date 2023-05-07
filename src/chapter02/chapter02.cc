// Copyright 2023 saito
#include "../../src/chapter02/chapter02.h"


bool chapter02::ipv4::SetAddress(const std::string& kAddress) {
  if (!Validate(kAddress)) return false;

  ip_address_ = kAddress;

  return true;
}

bool chapter02::ipv4::GetAddress(std::string& ip_address) {
  if (ip_address_ == "") return false;

  ip_address = ip_address_;

  return true;
}

bool chapter02::ipv4::Validate(const std::string& kAddress) {
  std::regex IsAddress(R"(([0-9]{1,3})\.([0-9]{1,3})\.([0-9]{1,3})\.([0-9]{1,3}))");
  if (std::regex_match(kAddress, IsAddress)) return true;

  return false;
}

std::string chapter02::ipv4_ans::to_string() const {
  std::stringstream sstr;
  sstr << this;
  return sstr.str();
}
