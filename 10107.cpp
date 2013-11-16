#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

int main(int argc, char *argv[]) {
  int number, n;
  std::vector<int> numbers;

  while(std::cin >> number) {
    numbers.push_back(number);

    std::sort(numbers.begin(), numbers.end());
    n = (int) numbers.size();

    if((n % 2) == 0) {
      std::cout << (numbers[(n / 2) - 1] + numbers[n / 2]) / 2 << std::endl;
    } else {
      std::cout << numbers[n / 2] << std::endl;
    }
  }
  return 0;
}
