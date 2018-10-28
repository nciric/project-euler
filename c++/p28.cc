/*
 * If you observe values on diagonals, a pattern emerges:
 * 4, 4 | 8, 8 | 12, 12 | 16, 16 | 20, 20 | 24, 24 |
 * 2, 4 | 6, 8 | 10, 12 | 14, 16 | 18, 20 | 22, 24 |
 *      3      5        7        9        11       13
 *
 * Those numbers are differences between successive values on the same diagonal.
 * 1, 5, 9, 17, 25, 37, 49, 65, 81, ...
 * 1, 3, 7, 13, 21, 31, 43, 57, 73, ...
 */

#include <iostream>
#include <future>
#include <thread>
#include <tuple>

int kLimit = 1001;

long DiagonalOne(int level) {
  int multiplier = (level - 1) / 2;
  int delta = 4 * multiplier;
  return 2 * multiplier * delta + 2 + delta;
}

long DiagonalTwo(int level) {
  int multiplier = (level - 1) / 2;
  int delta = 4 * multiplier;
  int delta_2 = delta - 2;

  return 2 * multiplier * delta_2 + 2 + delta;
}

long SolveOne() {
  long diagonal_one = 1;
  for (int i = 3; i <= kLimit; i += 2) {
    diagonal_one += DiagonalOne(i);
  }

  return diagonal_one;
}

long SolveTwo() {
  long diagonal_two = 0;  
  for (int i = 3; i <= kLimit; i += 2) {
    diagonal_two += DiagonalTwo(i);
  }

  return diagonal_two;
}

long FindSolution() {
  // It's actually slower to do multithreded solution for 1001.
  auto future_1 = std::async(SolveOne);
  auto future_2 = std::async(SolveTwo);

  return future_1.get() + future_2.get();
}

int main(int argc, char** argv) {
  std::cout << "Solution: " << FindSolution() << std::endl;

  return 0;
}