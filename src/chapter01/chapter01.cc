// Copyright 2023 saito
#include "../../src/chapter01/chapter01.h"


unsigned long long chapter01::q1(const unsigned long long kNum) {
  unsigned long long sum = 0ll;

  for (long long i = 1; i < 1 + kNum; ++i)
    if (!(i % 3) || !(i % 5)) sum+=i;

  return sum;
}

int chapter01::q2(const unsigned int kA, const unsigned int kB) {
  std::function<int(const int, const int)> gcd;
  gcd = [&](const int kA, const int kB) {
    return (kB == 0) ? kA : gcd(kB, kA % kB);
  };

  const int kMax = std::max(kA, kB);
  const int kMin = std::min(kA, kB);

  return gcd(kMax, kMin);
}

int chapter01::q3(const unsigned int kA, const unsigned int kB) {
  const int kLCM = q2(kA, kB);
  const int kAmultiple = kA / kLCM;

  return kAmultiple * kB;
}

int chapter01::q4(const int kNum) {
  auto is_prime = [](const int num) -> bool {
    if (num < 4) return num > 1;
    else if (!(num % 2) || !(num % 3)) return false;
    else
      for (int i = 5; i*i <= num; i+=6)
        if (num % i == 0 || num % (i+2) == 0) return false;

    return true;
  };

  for (int i = kNum; i > 1; --i)
    if (is_prime(i)) return i;

  return 0;
}

std::vector<std::pair<int, int>> chapter01::q5(const int kNum) {
  std::vector<std::pair<int, int>> ret_val;

  if (kNum < 7) return ret_val;

  auto is_prime = [](const int num) -> bool {
    if (num < 4) return num > 1;
    else if (!(num % 2) || !(num % 3)) return false;
    else
      for (int i = 5; i*i <= num; i+=6)
        if (num % i == 0 || num % (i+2) == 0) return false;

    return true;
  };

  for (int i = 2; i <= kNum - 6; ++i)
    if (is_prime(i) && is_prime(i+6))
      ret_val.push_back({i, i+6});

  return ret_val;
}

std::vector<std::pair<int, int>> chapter01::q6(const int kLimit) {
  std::vector<std::pair<int, int>> ret_val;

  // 真の約数の総和
  auto sum_proper = [](const int kNum) ->int {
    int sum = 1;
    const int kRoot = static_cast<int>(std::sqrt(kNum));

    for (int i = 2; i <= kRoot; ++i)
      if (kNum % i == 0) sum += ((kNum / i) == i) ? i : (i + kNum / i);

    return sum;
  };

  for (int i = 1; i <= kLimit; ++i) {
    int sum = sum_proper(i);

    if (sum > i)
      ret_val.push_back({i, sum - i});
  }

  return ret_val;
}

std::vector<std::pair<int, int>> chapter01::q7() {
  const int kNum = 1000000;

  auto sum_proper = [](const int kNum) ->int {
    int sum = 1;
    const int kRoot = static_cast<int>(std::sqrt(kNum));

    for (int i = 2; i <= kRoot; ++i)
      if (kNum % i == 0) sum += ((kNum / i) == i) ? i : (i + kNum / i);

    return sum;
  };

  std::vector<std::pair<int, int>> ret_val;
  std::vector<int> pass;
  for (int i = 1; i <= kNum; ++i) {
    if (std::binary_search(pass.begin(), pass.end(), i)) continue;

    if (auto sum1 = sum_proper(i); sum1 <= kNum) {
      if (auto sum2 = sum_proper(sum1); sum2 == i && i != sum1) {
        pass.push_back(i);
        pass.push_back(sum1);

        ret_val.push_back({i, sum1});
      }
    }
  }

  return ret_val;
}

std::vector<int> chapter01::q8() {
  std::vector<int> ret_val;

  const int kN = 3;

  for (int i = 100; i < 1000; ++i) {
    const int kThree = i * 0.01;
    const int kTwo = (i - 100 * kThree) * 0.1;
    const int kOne = i % 10;

    float sum = std::pow(kThree, kN) + std::pow(kTwo, kN) + std::pow(kOne, kN);

    if (i == sum) ret_val.push_back(i);
  }

  return ret_val;
}

std::vector<std::pair<int,int>> chapter01::q9(const int kNum) {
  std::vector<int> prime;

  for (int i = 1; i <= kNum; ++i) {
    int count = 0;
    for (int j = 1; j <=i; ++j) {
      if (i%j==0) count++;
    }

    if (count==2) prime.push_back(i);
  }

  std::vector<std::pair<int, int>> ret_val;

  int num = kNum;
  for (int i = 0; i < prime.size(); ++i) {
    if (num == 0) break;

    int coeff = 0;
    while(num % prime[i] == 0) {
      num /= prime[i];

      coeff++;
    }

    if (coeff) ret_val.push_back({prime[i], coeff});
  }

  return ret_val;
}

std::vector<std::pair<std::bitset<5>,std::bitset<5>>> chapter01::q10() {
  std::vector<std::pair<std::bitset<5>,std::bitset<5>>> ret_val;

  auto gray_encode = [](const std::bitset<5>& a) -> std::bitset<5> {
    return a ^ (a >> 1);
  };
  auto gray_decode = [](const std::bitset<5>& a) -> std::bitset<5> {
    std::bitset<5> ret_val;

    ret_val[4] = a[4];

    for (int i = 3; i >= 0; --i) {
      ret_val[i] = ret_val[i+1] ^ a[i];
    }

    return ret_val;
  };

  for (int i = 0; i < (1 << 5); ++i) {
    std::bitset<5> binary_i(i);

    std::bitset<5> gray = gray_encode(binary_i);
    std::bitset<5> binary = gray_decode(gray);

    ret_val.push_back({gray, binary});
  }
  return ret_val;
}

std::string chapter01::q11(const unsigned long long kNum) {
  const std::vector<std::pair<int, const char*>> roman {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
  };

  std::string ret_val;
  int num = kNum;
  for (const auto &[roma_num, roma_str] : roman) {
    while (num >= roma_num) {
      ret_val += roma_str;

      num -= roma_num;
    }
  }

  return ret_val;
}

int chapter01::q12() {
  const int limit = 1000000;

  long length = 0L;
  unsigned long long number = 0LL;

  std::vector<int> cache(limit+1, 0);

  for (long long i = 2; i <= limit; ++i) {
    auto n = i;
    long steps = 0L;

    while (n != 1 && n >= i) {
      if(n%2) n = n * 3 + 1;
      else n /= 2;

      steps++;
    }
    cache[i] = steps + cache[n];

    if (cache[i] > length) {
      length = cache[i];
      number = i;
    }
  }

  return number;
}

double chapter01::q13() {
  auto compute_pi = [](std::mt19937 &engine, std::uniform_real_distribution<> &dist) -> double {
    const int samples = 1000000;

    auto hit = 0;
    for (auto i = 0; i < samples; ++i) {
      auto x = dist(engine);
      auto y = dist(engine);

      if (y <= std::sqrt(1-std::pow(x,2))) hit++;
    }

    return 4.0 * hit / samples;
  };

  std::random_device rd;
  // int型 要素数624の配列作成
  auto seed_data = std::array<int , std::mt19937::state_size> {};
  // 関数オブジェクトrdへの参照を用いてseed_data配列を初期化
  std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
  // seed_seqインスタンス作成
  std::seed_seq seq(std::cbegin(seed_data), std::cend(seed_data));
  // メルセンヌ・ツイスターインスタンスを作成
  auto eng = std::mt19937{seq};
  // 0~1の範囲で一様分布を作成する関数を作成
  auto dist = std::uniform_real_distribution<> {0, 1};

  double pi = 0.0;
  for (int i = 0; i < 10; ++i)
    pi = (pi * i + compute_pi(eng, dist))/(i+1);

  return pi;
}
