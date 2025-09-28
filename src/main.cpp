#include "main.h"

using namespace std;

int main()
{
  int64_t n = 10967535067;
  auto pollardsPho = PollardsPho(n);
  auto result = pollardsPho.calculate();

  cout << "One factor of " << n << " is: " << result << endl;
}