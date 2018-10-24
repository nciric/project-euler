/*
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * clang++ p4.cc && ./a.out
 */

#include <iostream>
#include <vector>

bool IsPalindrome(int number) {
  std::vector<int> digits;
  while (number != 0) {
    digits.push_back(number % 10);
    number /= 10;
  }

  int number_length = digits.size();
  for (int i = 0; i <= number_length/2; i++) {
    if (digits[i] != digits[number_length - i - 1]) return false;
  }

  return true;
}

int FindSolution() {
  int max = 0;
  for (int i = 999; i > 99; --i) {
    for (int j = 999; j > 99; --j) {
      int result = i*j;
      if (!IsPalindrome(result)) continue;

      if (result > max) max = result;
    }
  }

  return max;
}

int main(int argc, char** argv) {
  std::cout << "Solution: " << FindSolution() << std::endl;

  return 0;
}
