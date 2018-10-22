/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * g++ p1.cc && ./a.out
 */

#include <iostream>

int FindSolution() {
  int sum = 0;

  for (int i = 1; i < 1000; ++i) {
    if (i % 3 == 0 || i % 5 == 0) sum += i;
  }

  return sum;
}

int main(int argc, char** argv) {
  std::cout << "Solution: " << FindSolution() << std::endl;

  return 0;
}
