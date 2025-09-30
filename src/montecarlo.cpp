#include "montecarlo.h"

using namespace std;

const int NUM = 4;
const int NUM_EACH_THREAD = 10000000;

void MonteCarloPi::estimatePiSingleThread()
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
      insideCircle++;
  }
}

double MonteCarloPi::estimatePi()
{
  for(int i = 0; i < NUM; i++)
  {
    threads.emplace_back(&MonteCarloPi::estimatePiSingleThread, this);
  }

  for(auto& t : threads)
  {
    t.join();
  }

  // return pi here
  cout << "insideCircle is: " << insideCircle << endl;
  return (4.0 * static_cast<double>(insideCircle) / (NUM * NUM_EACH_THREAD));
}