/*
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of
 * the numbers from 1 to 20?
 *
 * clang++ p5.cc && ./a.out
 */

#include <iostream>

bool IsDivisible(long number) {
  for (int i = 1; i <= 20; ++i) {
    if (number % i != 0) return false;
  }

  return true;
}

long FindSolution() {
  long result = 20;

  while (true) {
    if (IsDivisible(result)) return result;
    result += 20;
  }

  return result;
}

int main(int argc, char** argv) {
  std::cout << "Solution: " << FindSolution() << std::endl;

  return 0;
}
