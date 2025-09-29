#ifndef FACTOR_H
#define FACTOR_H

#include <vector>
#include <iostream>
#include <cstdint>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <numeric>

using namespace std;

class Factorization
{
public:
  Factorization(int64_t n);
  ~Factorization() = default;
  vector<int64_t> getAllFactors();
  int64_t getFactor(const int64_t& input);

private:
  int64_t n;
  int64_t c;
  int64_t failure = 0;
  vector<int64_t> factors = {};
  int64_t squareMod(const int64_t& x, const int64_t& c, const int64_t& input);
  int64_t calculateD(const int64_t& x, const int64_t& y, const int64_t& input);
  void selectC(int64_t& input);
  int64_t selectX0(const int64_t& input);
  int64_t pollardsPho(int64_t &x, int64_t &y, const int64_t& input);
  bool millerRabin(const int64_t& input);
  int64_t mod_pow(const int64_t& b, const int64_t& d, const int64_t& input);
  void basicLogging(int64_t &x, int64_t &y, int64_t &d, int64_t &cnt);
};

#endif