cc_library(
  name = "factorLib",
  srcs = [
    "factor.cpp"
  ],
  hdrs = [
    "factor.h"
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
  ], 
)