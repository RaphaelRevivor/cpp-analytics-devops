#include "main.h"

using namespace std;

int main(int argc, char** argv)
{
  string input = "";
  if (argc > 1)
    input = argv[1];
  else
  {
    throw invalid_argument("No argument is passed!");
  }
    
  // might throw std::invalid_argument or std::out_of_range in case not able to parse
  int64_t n = stoll(input);

  auto pollardsPho = PollardsPho(n);
  auto result = pollardsPho.calculate();

  cout << "One factor of " << n << " is: " << result << endl;
}