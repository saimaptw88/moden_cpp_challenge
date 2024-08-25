// Copyright 2023 saito
#ifndef SRC_CHAPTER02_CHAPTER02_HH_
#define SRC_CHAPTER02_CHAPTER02_HH_


#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
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

namespace Question17 {

template<typename T>
class DoubleDimmVector {
  public:
    DoubleDimmVector() = default;

    template<typename U>
    DoubleDimmVector(U size) : data_(size) {}

    template <typename U, typename V>
    DoubleDimmVector(U size, V size_second)
      : data_(size, std::vector<T>(size_second)) {};

    template <typename U, typename V>
    DoubleDimmVector(U size, V size_second, T init)
      : data_(size, std::vector<T>(size_second, init)) {};

    template <typename U>
    DoubleDimmVector(U size, std::initializer_list<T> init)
      : data_(size, init.begin(), init.end()) {}

    template <typename U>
    std::vector<T>& at(U i) {
      return data_[i];
    }

    template <typename U>
    T& at(U i, U j) const {
      return data_[i][j];
    }

    std::size_t size() const {
      return data_.size();
    }

    template <typename U>
    std::size_t size(U i) const {
      return data_[i].size();
    }

    T& data() {
      return &data_;
    }

    auto begin() noexcept -> std::vector<std::vector<T>>::iterator {
      return data_.begin();
    }

    auto cbegin() const noexcept ->std::vector<std::vector<T>>::const_iterator {
      return data_.cbegin();
    }

    auto end() noexcept -> std::vector<std::vector<T>>::iterator {
      return data_.end();
    }

    auto cend() const noexcept -> std::vector<std::vector<T>>::const_iterator {
      return data_.cend();
    }

    auto rbegin() noexcept -> std::vector<std::vector<T>>::iterator {
      return data_.rbegin();
    }

    auto crbegin() const noexcept -> std::vector<std::vector<T>>::const_iterator {
      return data_.crbegin();
    }

    auto rend() noexcept -> std::vector<std::vector<T>>::iterator {
      return data_.rend();
    }

    auto crend() const noexcept -> std::vector<std::vector<T>>::const_iterator {
      return data_.crend();
    }

    void print() {
      const auto N = static_cast<int>(data_.size());

      for (int i = 0; i < N; ++i) {
        std::cout << i << ": ";

        for (auto&& elem : data_[i]) {
          std::cout << elem << ", ";
        }
        std::cout << std::endl;
      }
    }

  private:
    std::vector<std::vector<T>> data_;
};
}  // namespace Question17
}  // namespace chapter02

#endif  // SRC_CHAPTER02_CHAPTER02_HH_
