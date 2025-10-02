# build
FROM ubuntu:22.04 as builder
RUN apt-get update && apt-get install -y bazel g++ clang
WORKDIR /app
COPY . .
RUN bazel build //src:mainProg

# runtime
FROM ubuntu:22.04
WORKDIR /app
COPY --from=builder /app/bazel-bin/ /app
RUN bazel run //src:mainProg
EXPOSE 8080
CMD ["./server"]

