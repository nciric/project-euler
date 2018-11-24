/*
 * I got a new machine, Ryzen 2700x with 8 cores.
 * I'll approach this using knapsack algorithm:
 *  - assign each core a denomination (there is 8)
 *  - find all solutions for that denomination and below
 *  - sum result from each core
 *
 * On windows 10, Ubuntu subsystem use this to compile and run:
 * clang++ p31.cc -pthread && ./a.out
 */

#include <iostream>
#include <future>
#include <vector>
#include <thread>
#include <tuple>

// All denominations available.
constexpr std::array<int, 8> denominations = {200, 100, 50, 20, 10, 5, 2, 1};

// We are trying to hit this number.
constexpr long target = 200;

long Solve(int index, long current) {
  long result = denominations[index] + current;

  if (result == target) return 1;
  if (result > target) return 0;

  int count = 0;
  for (int i = index; i < denominations.size(); ++i) {
    count += Solve(i, result);
  }

  return count;
}

long FindSolution() {
  std::vector<std::future<long>> futures;
  for (int i = 0; i < denominations.size(); ++i) {
    futures.push_back(std::async(Solve, i, 0));
  }

  long result = 0;
  for (auto& future : futures) {
    result += future.get();
  }

  return result;
}

int main(int argc, char** argv) {
  std::cout << "Solution: " << FindSolution() << std::endl;

  return 0;
}