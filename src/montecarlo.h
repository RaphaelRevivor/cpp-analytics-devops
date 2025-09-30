#ifndef MONTE_H
#define MONTE_H

#include <vector>
#include <random>
#include <thread>

using namespace std;

class MonteCarloPi
{
public:
  double estimatePiSingleThread();
  void estimatePi();

private:
  vector<thread> threads = {};
  atomic<int> insideCircle = 0;

};

#endif