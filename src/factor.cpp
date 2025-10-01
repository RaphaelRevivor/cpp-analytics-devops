#include "factor.h"

using namespace std;

// === member functions for Factorization ===
/// @brief constructor
/// @param n the value for fatorization
Factorization::Factorization(int64_t n) : n(n)
{
  srand(time(0));
}

string Factorization::getAllFactorsInString()
{
  string output = "";
  auto factors = getAllFactors();
  for(auto iter = factors.begin(); iter != factors.end(); iter++)
  {
    output += to_string(*iter);
    if (iter != prev(factors.end()))
      output += ",";
  }
  output += "\n";
  return output;
}

vector<int64_t> Factorization::getAllFactors()
{
  vector<int64_t> output = {};
  int64_t tmp = n;
  while(tmp != 1)
  {
    auto factor = getFactor(tmp);
    output.emplace_back(factor);
    tmp = tmp / factor;
  }
  return output;
}

/// @brief the main function to do the calculation
/// @return result
int64_t Factorization::getFactor(const int64_t& input)
{
  int64_t d = 1;
  int64_t cnt = 0;
  int64_t x = selectX0(input);
  int64_t y = x;

  // trivial cases
  if (input == 1 || input == 2 || input == 3)
    return input;
  else if (input%2 == 0)
  {
    return 2;
  }
  // check prime numbers
  else if (millerRabin(input))
  {
    return input;
  }   

  // must have a factor
  while(d == 1 || d == input)
  {
    d = pollardsPho(x, y, input);
    if (d == input)
    {
      failure++;
    }
    // basicLogging(x, y, d, cnt);
    cnt++;
  }

  if (!millerRabin(d))
  {
    d = getFactor(d);
  }

  return d;
}

/// @brief basic iteration of the algorithm
/// @param x x
/// @param y y
/// @return d
int64_t Factorization::pollardsPho(int64_t &x, int64_t &y, const int64_t& input)
{
  selectC(c);
  x = squareMod(x, c, input);
  y = squareMod(squareMod(y, c, input), c, input);
  return calculateD(x, y, input);
}

/// @brief  select the initial x
/// @return x
int64_t Factorization::selectX0(const int64_t& input)
{
  
  int64_t output = (rand() % (input - 2)) + 2;
  return output;
}

/// @brief function to calculate f(x) = x^2 + c
/// @param x x
/// @param c c
/// @return f(x)
int64_t Factorization::squareMod(const int64_t& x, const int64_t& c, const int64_t& input)
{
#ifdef _MSC_VER
  int64_t output = (x * x + c) % input;
#else
  __int128_t output = (x * x + c) % input;
#endif
  return output;
}

/// @brief funtion to calculate D = gcd(abs(x-y), n)
int64_t Factorization::calculateD(const int64_t& x, const int64_t& y, const int64_t& input)
{
  return gcd(abs(x-y), input);
}

/// @brief function to select c
/// @return c
void Factorization::selectC(int64_t& input)
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
void Factorization::basicLogging(const int64_t &x, const int64_t &y, const int64_t &d, const int64_t &cnt)
{
  cout << cnt << ":" << endl;
  cout << "x, y, d: " << x << "," << y << "," << d << endl;
}

/// @brief function to check prime (in the cases of none 1, 2, 3 or even)
/// @return bool result
bool Factorization::millerRabin(const int64_t& input)
{
  int64_t d = input - 1;
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
    if (base >= input)
      continue;

#ifdef _MSC_VER
    int64_t x = mod_pow(base, d, input);
#else
    __int128_t x = mod_pow(base, d, input);
#endif

    // calculate x = a^d % n
    if (x == 1 || x == input - 1)
      continue;
    
    bool passed = false;
    for(int64_t i = 1; i < s; i++)
    {
      x = x * x % input;
      if (x == input - 1)
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
int64_t Factorization::mod_pow(const int64_t& b, const int64_t& d, const int64_t& input)
{

#ifdef _MSC_VER
  int64_t result = 1;
#else
  __int128_t result = 1;
#endif
  int64_t base = b;
  int64_t dd = d;
  base = base % input;
  while(dd > 0)
  {
    if (dd % 2 == 1)
      result = (result * base) % input;
    base = base * base % input;
    dd /= 2;
  }
  return result;
}