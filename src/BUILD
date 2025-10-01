cc_library(
  name = "factorLib",
  srcs = [
    "factor.cpp"
  ],
  hdrs = [
    "factor.h"
  ],
  visibility = [
    "//:__subpackages__",
  ],
)

cc_library(
  name = "montecarloLib",
  srcs = [
    "montecarlo.cpp"
  ],
  hdrs = [
    "montecarlo.h"
  ],
  visibility = [
    "//:__subpackages__",
  ],
)

cc_binary(
  name = "mainProg",
  srcs = [
    "main.cpp",
    "main.h",
  ],
  deps = [
    ":factorLib",
    ":montecarloLib",
    "//src/api:restapiLib",
  ], 
)