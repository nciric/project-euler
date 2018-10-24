/*
 * The sum of the squares of the first ten natural numbers is,
 *
 * 12 + 22 + ... + 102 = 385
 * The square of the sum of the first ten natural numbers is,
 *
 * (1 + 2 + ... + 10)2 = 552 = 3025
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 *
 * clang++ p6.cc && ./a.out
 */

#include <iostream>

long FindSolution() {
  int n = 100;

  // See https://brilliant.org/wiki/sum-of-n-n2-or-n3/
  long n_sum = n*(n+1)/2;
  long n_sum_squared = n_sum * n_sum;

  long n_squared_sum = n*(n+1)*(2*n+1)/6;

  return n_sum_squared - n_squared_sum;
}

int main(int argc, char** argv) {
  std::cout << "Solution: " << FindSolution() << std::endl;

  return 0;
}
