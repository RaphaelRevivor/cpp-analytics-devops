#ifndef REST_H
#define REST_H

// #define CPPHTTPLIB_OPENSSL_SUPPORT

#ifdef _MSC_VER
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#include <httplib.h>

#include "src/factor.h"
#include "src/montecarlo.h"

using namespace httplib;

class RestApi
{
public:
  RestApi() = default;
  ~RestApi() = default;
  int runServer();

private:
  Server svr;
};

#endif