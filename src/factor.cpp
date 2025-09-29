#include "factor.h"

using namespace std;

// === member functions for PollardsPho ===
/// @brief constructor
/// @param n the value for fatorization
PollardsPho::PollardsPho(int64_t n) : n(n)
{
  srand(time(0));
}

/// @brief the main function to do the calculation
/// @return result
int64_t PollardsPho::calculate()
{
  int64_t d = 1;
  int64_t cnt = 0;
  int64_t x = selectX0();
  int64_t y = x;

  // trivial cases
  if (n == 1 || n == 2 || n == 3)
    return n;
  else if (n%2 == 0)
    return 2;
  // check prime numbers
  else if (millerRabin())
    return n;

  while(d == 1 || d == n)
  {
    d = basicIteration(x, y);
    if (d == n)
    {
      failure++;
    }

    basicLogging(x, y, d, cnt);

    cnt++;
  }

  return d;
}

/// @brief basic iteration of the algorithm
/// @param x x
/// @param y y
/// @return d
int64_t PollardsPho::basicIteration(int64_t &x, int64_t &y)
{
  selectC(c);
  x = squareMod(x, c);
  y = squareMod(squareMod(y, c), c);
  int64_t d = calculateD(x, y);

  return d;
}

/// @brief  select the initial x
/// @return x
int64_t PollardsPho::selectX0()
{
  return (rand() % (n - 2)) + 2;
}

/// @brief function to calculate f(x) = x^2 + c
/// @param x x
/// @param c c
/// @return f(x)
int64_t PollardsPho::squareMod(int64_t x, int64_t c)
{
  __int128_t output = (x * x + c) % n;
  return output;
}

/// @brief funtion to calculate D = gcd(abs(x-y), n)
int64_t PollardsPho::calculateD(int64_t x, int64_t y)
{
  return gcd(abs(x-y), n);
}

/// @brief function to select c
/// @return c
void PollardsPho::selectC(int64_t& input)
{
  if (failure < 100)
    input = 1;
  else if (failure < 200)
    input = 2;
  else if (failure < 300)
    input = 3;
  // choose from [4, n)
  else
    input = (rand() % (n - 4)) + 4;
}

/// @brief  provides a basic logging showing info for x, y, d, cnt
/// @param x x
/// @param y y
/// @param d d
/// @param cnt cnt
void PollardsPho::basicLogging(int64_t &x, int64_t &y, int64_t &d, int64_t &cnt)
{
  cout << cnt << ":" << endl;
  cout << "x, y, d:" << x << "," << y << "," << d << endl;
}

/// @brief function to check prime (in the cases of none 1, 2, 3 or even)
/// @return bool result
bool PollardsPho::millerRabin()
{
  int64_t d = n - 1;
  int64_t s = 0;
  while(d % 2 == 0)
  {
    d /= 2;
    s++;
  }

  // enough for 64 bit int
  vector<int64_t> bases = {2,3,5,7,11,13,17};
  for(const auto& base : bases)
  {
    if (base >= n)
      continue;

    // calculate x = a^d % n
    int64_t x = mod_pow(base, d);

    if (x == 1 || x == n - 1)
      continue;
    
    bool passed = false;
    for(int64_t i = 1; i < s; i++)
    {
      x = x * x % n;
      if (x == n - 1)
      {
        passed = true;
        break;
      }
    }
    if (!passed)
      return false;
  }
  return true;
}

/// @brief internal function to calculate mod power
/// @param b b
/// @param d d
/// @return mod power result
int64_t PollardsPho::mod_pow(int64_t b, int64_t d)
{
  __int128_t result = 1;
  b = b % n;
  while(d > 0)
  {
    if (d % 2 == 1)
      result = (result * b) % n;
    b = b * b % n;
    d /= 2;
  }
  return result;
}

// === member functions for Factorization ===