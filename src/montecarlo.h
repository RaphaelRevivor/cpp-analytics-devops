#ifndef MONTE_H
#define MONTE_H

#include <iostream>
#include <vector>
#include <random>
#include <thread>

using namespace std;

class MonteCarloPi
{
public:
  MonteCarloPi& operator=(const MonteCarloPi&) = delete;

  MonteCarloPi() = default;
  ~MonteCarloPi() = default;

  void estimatePiSingleThread();
  double estimatePi();

private:
  vector<thread> threads = {};
  atomic<int> insideCircle = 0;
};

#endif