#include "montecarlo.h"

using namespace std;

const int NUM = 8;
const int NUM_EACH_THREAD = 10000000;

MonteCarloPi::MonteCarloPi()
{
  inCircleVec.resize(NUM, 0);
}

void MonteCarloPi::estimatePiSingleThread(int threadId)
{
  random_device rd;
  // mersenne_twister_engine seeded with rd()
  mt19937 gen(rd());
  uniform_real_distribution<double> distrib(0.0, 1.0);
  for(int i = 0; i < NUM_EACH_THREAD; i++)
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
  return (4.0 * accumulate(inCircleVec.begin(), inCircleVec.end(), 0) / (NUM * NUM_EACH_THREAD));
}