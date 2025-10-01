#include "rest.h"

int RestApi::runServer()
{
  svr.Get(R"(/factorize?number=(\d+))", [&] (const Request& req, Response& res) {
    auto nStr = req.matches[1];
    int64_t n = stoll(nStr);
    auto factorization = Factorization(n);
    auto factorsStr = factorization.getAllFactorsInString();
    res.set_content(factorsStr, "text/plain");
  });

  // svr.Get()

  if (!svr.listen("localhost", 8080)) {
      std::cerr << "Error starting server\n";
      return 1;
  }
}



