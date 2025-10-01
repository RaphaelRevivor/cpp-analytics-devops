# build
FROM ubuntu:22.04 as builder
RUN apt-get update && apt-get install -y bazel g++ clang
WORKDIR /app
COPY . .

# runtimeFROM ubuntu:22.04
WORKDIR /app
COPY --from=builder /app/bazel-bin/src/api /app/api
EXPOSE 8080
CMD ["./server"]

