# run this file with: docker build -f Dockerfile -t rest-api-container:v1 .
# build
FROM ubuntu:22.04 as builder
RUN apt-get update && apt-get install -y curl gnupg apt-transport-https g++ clang
RUN apt-get update && apt-get install -y curl unzip \
 && ARCH=$(uname -m | sed 's/aarch64/arm64/;s/x86_64/amd64/') \
 && echo "Detected architecture: $ARCH" \
 && curl -fsSL https://releases.bazel.build/8.4.2/release/bazel-8.4.2-linux-$ARCH \
      -o /usr/local/bin/bazel \
 && chmod +x /usr/local/bin/bazel
WORKDIR /app
COPY . .
RUN bazel build //src:mainProg

# runtime
FROM ubuntu:22.04
WORKDIR /app
COPY --from=builder /app/bazel-bin/src/mainProg /app/server
RUN chmod +x /app/server
EXPOSE 8080
CMD ["./server"]
