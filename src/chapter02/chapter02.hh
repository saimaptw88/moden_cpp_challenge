// Copyright 2023 saito
#ifndef SRC_CHAPTER02_CHAPTER02_HH_
#define SRC_CHAPTER02_CHAPTER02_HH_


#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace chapter02 {
void execute();
int add(int a, int b);

std::vector<std::string> split(const std::string &s, char delim);

int to_integer(std::string str);

namespace Question15 {
class IPv4 {
  public:
    IPv4(std::string ip) : ip_(std::forward<std::string>(ip)) {}
    IPv4(int a, int b, int c, int d)
      : ip_{std::to_string(a) + '.' + std::to_string(b) + '.' + std::to_string(c) + '.' + std::to_string(d)}
    {}

    void print() const {
      std::cout << ip_ << std::endl;
    }

  private:
    std::string ip_;
};
}  // namespace Question15

namespace Question16 {
struct IpAddress {
  int first;
  int second;
  int third;
  int forth;

  IpAddress(int a, int b, int c, int d)
    : first(a), second(b), third(c), forth(d)
  {}

  IpAddress(std::string a, std::string b, std::string c, std::string d)
    : first{to_integer(a)}, second{to_integer(b)}, third{to_integer(c)}, forth{to_integer(d)}
  {}
};
class IPv4 {
  public:
    IPv4(std::string ip) : ip_(std::forward<std::string>(ip)) {}

    IPv4(int a, int b, int c, int d)
      : ip_{std::to_string(a) + '.' + std::to_string(b) + '.' + std::to_string(c) + '.' + std::to_string(d)}
    {}

    auto ip_address() const -> IpAddress {
      auto ip = split(ip_, '.');

      auto result = IpAddress(ip[0], ip[1], ip[2], ip[3]);

      return result;
    }

  private:
    std::string ip_;
};

class PrintIpRange {
  public:
    PrintIpRange(IPv4 big, IPv4 small) {
      auto ip_big = big.ip_address();
      auto ip_small = small.ip_address();

      if (!is_bigger(ip_big, ip_small)) {
        std::swap(ip_big, ip_small);
      }
      bool moved = false;

      for (int f = ip_small.first; f <= ip_big.first; ++f) {
        if (f != ip_small.first) {
          moved = true;
        }

        const int s_max = (f == ip_big.first) ? ip_big.second : kMaxNumber_;
        const int s_min = ip_small.second;

        for (int s = s_min; s <= s_max; ++s) {
          if (s != s_min) {
            moved = true;
          }

          const int t_max = (s == s_max) ? ip_big.third: kMaxNumber_;
          const int t_min = moved ? 0 : ip_small.third;

          for (int t = t_min; t <= t_max; ++t) {
            if (t != t_min) {
              moved = true;
            }

            const int fo_max = (t == t_max) ? ip_big.forth : kMaxNumber_;
            const int fo_min = moved ? 0 : ip_small.forth;

            for (int fo = fo_min; fo <= fo_max; ++fo) {
              std::cout << f << "." << s << "." << t << "." << fo << std::endl;
            }
          }
        }
      }
    }

  private:
    bool is_bigger(IpAddress a, IpAddress b) const {
      if (a.first > b.first) {
        return true;
      } else if (a.first < b.first) {
        return false;
      }

      if (a.second > b.second) {
        return true;
      } else if (a.second < b.second) {
        return false;
      }

      if (a.third > b.third) {
        return true;
      } else if (a.third < b.third) {
        return false;
      }

      if (a.forth >= b.forth) {
        return true;
      }

      return false;
    }

    const int kMaxNumber_ = 255;
};
}  // namespace Question16
}  // namespace chapter02

#endif  // SRC_CHAPTER02_CHAPTER02_HH_
