# cpp-analytics-devops

A modern **C++ microservice project** demonstrating mathematical analytics, and DevOps practices. This project exposes a lightweight REST API for computational mathematics (prime factorization and Monte Carlo π estimation) and showcases full integration with **Bazel**, **Docker**, **Kubernetes**, and **GitHub Actions**.

---

## 🚀 Features

### 🧮 Math & Analytics API

* **Prime Factorization** using Pollard’s Rho and Miller–Rabin primality test.
* **Monte Carlo Simulation** for estimating the value of π.
* Implemented fully in **C++17**, designed for high performance and modularity.

### 🌐 RESTful API

* Built with [`cpp-httplib`](https://github.com/yhirose/cpp-httplib) (header-only HTTP/HTTPS library).
* Exposes endpoints:

  * `GET /factorize?number=<int>` → returns factors of the input number.
  * `GET /simulate/pi?iterations=<int>` → estimates π via Monte Carlo.

### 🏗️ Modern Build System

* **Bazel** is used for building, testing, and dependency management.
* Reproducible, cross-platform builds compatible with macOS and Ubuntu.

### 🐳 Containerization

* Multi-stage **Dockerfile**:

  * **Builder stage:** compiles with Bazel.
  * **Runtime stage:** runs the compiled binary only (minimal footprint).
* Example build and run:

  ```bash
  docker build -t cpp-analytics-devops .
  docker run -p 8080:8080 cpp-analytics-devops
  ```

### ⚙️ CI/CD Integration

* **GitHub Actions** automates:

  * Build and test pipelines.
  * Docker image creation and publishing.
  * Optional K8s deployment hooks.

---

## 🔧 Endpoints Summary

| Method | Endpoint                        | Description                               |
| ------ | ------------------------------- | ----------------------------------------- |
| GET    | `/factorize?number=<int>`       | Factorizes the given number.              |
| GET    | `/simulate/pi?iterations=<int>` | Estimates π using Monte Carlo simulation. |

Example usage:

```bash
curl "http://localhost:8080/factorize?number=1024"
curl "http://localhost:8080/simulate/pi?iterations=1000000"
```

---

## 🧱 Project Structure

```
cpp-analytics-devops/
├── BUILD                  # Root Bazel build file
├── MODULE.bazel           # Bazel module configuration
├── src/                   # Core source code
│   ├── api/               # REST server implementation
│   ├── factor.cpp/.h      # Pollard's Rho + Miller–Rabin
│   ├── montecarlo.cpp/.h  # Monte Carlo π estimator
│   └── main.cpp           # Entry point
├── tests/                 # Unit tests
├── docker/                # Dockerfile and related assets
├── k8s/                   # Kubernetes manifests
├── docs/                  # Documentation
└── .github/workflows/     # CI/CD pipelines
```

---

## ⚡ Quick Start

### 1️⃣ Build Locally

```bash
bazel build //src:mainProg
```

### 2️⃣ Run Locally

```bash
bazel run //src:mainProg
```

Server starts on `http://0.0.0.0:8080`.

### 3️⃣ Docker

```bash
docker build -t cpp-analytics-devops .
docker run -p 8080:8080 cpp-analytics-devops
```

---

## 🧩 Tech Stack

| Category                      | Tool                           |
| ----------------------------- | ------------------------------ |
| Language                      | C++17                          |
| Build System                  | Bazel                          |
| Web Framework                 | cpp-httplib                    |
| CI/CD                         | GitHub Actions                 |
| Containerization              | Docker                         |
| Orchestration(future work)    | Kubernetes                     |
| DB (future work)              | PostgreSQL integration planned |

---

## 🧠 Future Work

* Add Kubernetes for orchestration
* Integrate PostgreSQL for result persistence.
* Add caching layer for factorization results.

---

## 📄 License

Licensed under the [MIT License](./LICENSE).

---

**Author:** RaphaelRevivor
**Repository:** [cpp-analytics-devops](https://github.com/RaphaelRevivor/cpp-analytics-devops)
