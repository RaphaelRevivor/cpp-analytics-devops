#include "montecarlo.h"

using namespace std;

const int NUM = 8;

MonteCarloPi::MonteCarloPi(int n) : n(n)
{
  inCircleVec.resize(NUM, 0);
}

void MonteCarloPi::estimatePiSingleThread(int threadId)
{
  random_device rd;
  // mersenne_twister_engine seeded with rd()
  mt19937 gen(rd());
  uniform_real_distribution<double> distrib(0.0, 1.0);
  // for last thread, run a bit more
  int limit = threadId == NUM - 1 ?  n / NUM + (n - NUM * (n / NUM)) : n / NUM;
  for(int i = 0; i < limit; i++)
  {
    double x = distrib(gen);
    double y = distrib(gen);
    if (x*x + y*y <= 1.0)
      inCircleVec[threadId]++;
  }
}

double MonteCarloPi::estimatePi()
{
  for(int i = 0; i < NUM; i++)
  {
    threads.emplace_back(&MonteCarloPi::estimatePiSingleThread, this, i);
  }

  for(auto& t : threads)
  {
    t.join();
  }

  // return pi here
  return (4.0 * accumulate(inCircleVec.begin(), inCircleVec.end(), 0) / n);
}