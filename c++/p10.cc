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

bool IsDivisible(int number, const std::vector<int> primes) {
  for (const auto element : primes) {
    if (number < element * element) return false;
    if (number % element == 0) return true;
  }

  return false;
}

long FindSolution() {
  // Lets speed things up, by finding first handful of primes, then go slow
  // way of finding the rest.
  const int limit = 10000;
  std::vector<int> small_primes(limit);
  std::iota(small_primes.begin(), small_primes.end(), 2);
  Sieve(small_primes);
 
  std::vector<int> real_primes(limit);
  auto it = std::copy_if(small_primes.begin(), small_primes.end(),
    real_primes.begin(), [](int number) { return number != 0;});
  real_primes.resize(std::distance(real_primes.begin(),it));

  std::vector<int> primes;
  for (int i = limit + 1; i < 2000000; i += 2) {
    if (!IsDivisible(i, real_primes)) primes.push_back(i);
  }

  return std::accumulate(real_primes.begin(), real_primes.end(), 0L) +
   std::accumulate(primes.begin(), primes.end(), 0L);
}

int main(int argc, char** argv) {
  std::cout << "Solution: " << FindSolution() << std::endl;

  return 0;
}
