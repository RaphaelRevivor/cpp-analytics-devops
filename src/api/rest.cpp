#include "rest.h"

int RestApi::runServer()
{
  svr.Get("/factorize", [&] (const Request& req, Response& res) {
    auto nStr = req.get_param_value("number");
    int64_t n = stoll(nStr);
    auto factorization = Factorization(n);
    auto factorsStr = factorization.getAllFactorsInString();

    // cout << "Server is trying to reply: " << factorsStr << endl;

    res.status = 200;
    res.set_content(factorsStr, "text/plain");
  });

  svr.Get("/simulate/pi", [&] (const Request& req, Response& res) {
    auto nStr = req.get_param_value("iterations");
    int64_t n = stoll(nStr);
    auto montecarloPi = MonteCarloPi(n);
    auto piStr = to_string(montecarloPi.estimatePi());

    // cout << "Server is trying to reply: " << piStr << endl;

    res.status = 200;
    res.set_content(piStr, "text/plain");
  });

  if (!svr.listen("0.0.0.0", 8080)) {
      std::cerr << "Error starting server\n";
      return 1;
  }
}



