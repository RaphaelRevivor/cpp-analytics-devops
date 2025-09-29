#ifndef FACTOR_H
#define FACTOR_H

#include <vector>
#include <iostream>
#include <cstdint>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <numeric>

class PollardsPho
{
public:
  PollardsPho(int64_t n);
  ~PollardsPho() = default;
  int64_t calculate();

private:
  int64_t n;
  int64_t c;
  int64_t failure = 0;
  int64_t squareMod(int64_t x, int64_t c);
  int64_t calculateD(int64_t x, int64_t y);
  void selectC(int64_t& input);
  int64_t selectX0();
  int64_t basicIteration(int64_t &x, int64_t &y);
  bool millerRabin();
  int64_t mod_pow(int64_t b, int64_t d);
  void basicLogging(int64_t &x, int64_t &y, int64_t &d, int64_t &cnt);
};

// class Factorization
// {
// public:
//   Factorization(int64_t n) : n(n)
//   {
//   }
//   ~Factorization() = default;
// private:
//   int64_t n;
// };

#endif