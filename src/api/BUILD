cc_library(
  name = "restapiLib",
  srcs = [
    "rest.cpp"
  ],
  hdrs = [
    "rest.h",
  ],
  deps = [
    "@cpp-httplib//:httplib",
    "//src:montecarloLib",
    "//src:factorLib",
  ],
  visibility = [
    "//:__subpackages__",
  ],
)