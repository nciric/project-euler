/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 *
 * clang++ p7.cc && ./a.out
 */

// Using prime number theorem, we can estimate the range of numbers needed
// to ~200,000 - n/ln(n).
// We'll apply naive sieve with all numbers in memory - bcs. we can.

#include <iostream>
#include <numeric>
#include <vector>

void Sieve(std::vector<int>& numbers) {
  for (int i = 0; i < numbers.size() - 1; ++i) {
    int divisor = numbers.at(i);
    if (divisor == 0) continue;
    for (int j = i + 1; j < numbers.size(); ++j) {
      if (numbers.at(j) % divisor == 0) numbers[j] = 0;
    }
  }
}

int FindSolution() {
  std::vector<int> primes(200000);
  // Fill in the range from 2, incrementing by 1.
  std::iota(primes.begin(), primes.end(), 2);

  Sieve(primes);

  int count = 0;
  for (const auto element : primes) {
    if (element != 0) count++;
    if (count == 10001) return element;
  }

  return -1;
}

int main(int argc, char** argv) {
  std::cout << "Solution: " << FindSolution() << std::endl;

  return 0;
}
