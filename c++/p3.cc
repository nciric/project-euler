/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 *
 * g++ p3.cc && ./a.out
 */

#include <cmath>
#include <iostream>

// Somewhat brute force approach.
bool IsPrime(int number) {
  // Eliminate even numbers.
  if (number % 2 == 0) return false;

  // Go up to sqrt(number), and only look for odd factors.
  int sqrt_number = sqrt(number);
  for (int i = 3; i < sqrt_number; i += 2) {
    if (number % i == 0) return false;
  }

  return true;
}

int FindSolution() {
  long target = 600851475143L;
  // sqrt(target) to optimize.
  int sqrt_target = sqrt(target);

  int max = 1;
  for (int i = 2; i <= sqrt_target; ++i) {
    // Skip non-prime numbers.
    if (!IsPrime(i)) continue;
    // See if it's a factor of target.
    if (target % i == 0) max = i;
  }

  return max;
}

int main(int argc, char** argv) {
  std::cout << "Solution: " << FindSolution() << std::endl;

  return 0;
}
