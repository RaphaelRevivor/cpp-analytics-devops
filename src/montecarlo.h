#ifndef MONTE_H
#define MONTE_H

#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <algorithm>
#include <numeric>

using namespace std;

class MonteCarloPi
{
public:
  MonteCarloPi& operator=(const MonteCarloPi&) = delete;

  MonteCarloPi(int n);
  ~MonteCarloPi() = default;

  void estimatePiSingleThread(int threadId);
  double estimatePi();

private:
  int n = 0;
  vector<thread> threads = {};
  vector<int> inCircleVec = {};
};

#endif