// Copyright 2023 saito
#ifndef SRC_CHAPTER02_CHAPTER02_H_
#define SRC_CHAPTER02_CHAPTER02_H_

#include <array>
#include <bitset>
#include <functional>
#include <istream>
#include <iostream>
#include <regex>  // NOLINT
#include <sstream>
#include <string>


namespace chapter02 {
class ipv4 {
 public:
    static void q15() {
      std::string s;
      std::cin >> s;
      ipv4 ip;

      ip.SetAddress(s);
      s = "";

      ip.GetAddress(s);
      std::cout << s << std::endl;
    }
    bool SetAddress(const std::string&);
    bool GetAddress(std::string&);

    ipv4& operator=(const ipv4& other) noexcept {
      ip_address_ = other.ip_address_;

      return *this;
    }
    ipv4(): ip_address_("0.0.0.0") {};

    ipv4(const ipv4& others) noexcept :
      ip_address_(others.ip_address_) {}

 private:
    bool Validate(const std::string&);
    std::string ip_address_;
};

class ipv4_ans {
  std::array<unsigned char, 4> data;

 public:
    // コンストラクタ：引数なしの場合,0で初期化
    constexpr ipv4_ans() : ipv4_ans(0, 0, 0, 0) {}

    // コンストラクタ：引数が４つの場合、data変数を初期化して値を格納
    constexpr ipv4_ans(const unsigned char a, const unsigned char b,
                       const unsigned char c, const unsigned char d):
      data({a, b, c, d}) {}

    // コンストラクタ：引数が１つで数値で与えられた場合、４つの値に分割してコンストラクタを呼び出し
    // コピー初期化不可、暗黙型変換不可
    explicit ipv4_ans(const uint64_t a) {
      auto divide = [] (const uint64_t a) {
        std::pair<int, int> b;
        b.first = a / 1000;
        b.second = a % 1000;

        return b;
      };

      auto d4 = divide(a);
      auto d3 = divide(d4.first);
      auto d2 = divide(d3.first);
      auto d1 = divide(d2.first);

      data = { static_cast<unsigned char>(d1.second),
               static_cast<unsigned char>(d2.second),
               static_cast<unsigned char>(d3.second),
               static_cast<unsigned char>(d4.second)};
    }

    // コンストラクタ：コピーコンストラクタ
    ipv4_ans(const ipv4_ans& other) noexcept : data(other.data) {}

    std::string to_string() const;

    constexpr uint64_t to_int() const noexcept {
      return
        (static_cast<uint32_t>(data[0]) * 1e9) +
        (static_cast<uint32_t>(data[1]) * 1e6) +
        (static_cast<uint32_t>(data[2]) * 1e3)  +
        (static_cast<uint32_t>(data[3]));
    }

    // 代入演算子：
    ipv4_ans& operator=(const ipv4_ans& other) noexcept {
      data = other.data;
      return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const ipv4_ans& a) {
      os << static_cast<int>(a.data[0]) << '.'
         << static_cast<int>(a.data[1]) << '.'
         << static_cast<int>(a.data[2]) << '.'
         << static_cast<int>(a.data[3]);

      return os;
    }

    friend std::istream& operator>>(std::istream& is, ipv4_ans& a) {
      char d1, d2, d3;
      int b1, b2, b3, b4;

      is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;

      if (d1 == '.' && d2 == '.' && d3 == '.') {
        a = ipv4_ans(b1, b2, b3, b4);
      } else {
        is.setstate(std::ios_base::failbit);
      }

      return is;
    }

    static void q15() {
      ipv4_ans address(192, 168, 0, 2);
      std::cout << address << std::endl;

      ipv4_ans ip;
      std::cout << ip << std::endl;
      std::cin >> ip;
      if (!std::cin.fail()) std::cout << ip << std::endl;
    }
};
}  // namespace chapter02

#endif  // SRC_CHAPTER02_CHAPTER02_H_
