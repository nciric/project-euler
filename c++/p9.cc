#include <cmath>
#include <iostream>

int FindSolution() {
  for (int a = 1; a < 500; ++a) {
    for (int b = a + 1; b < 500; ++b) {
      int c_pow_2 = std::pow(a, 2) + std::pow(b, 2);
      int c = sqrt(c_pow_2);
      if (c * c != c_pow_2) continue;

      if (a + b + c == 1000) {
        std::cout << a << ", " << b << ", " << c << std::endl;
        return a * b * c;
      }
    }
  }

  return 0;
}

int main(int argc, char** argv) {
  std::cout << "Solution: " << FindSolution() << std::endl;

  return 0;
}
