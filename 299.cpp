#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
  int numTestCases, numInputs, number, i, j, swaps, temp;
  std::vector<int> numbers;

  std::cin >> numTestCases;

  while(numTestCases > 0) {
    std::cin >> numInputs;
    numbers.clear();

    while(numInputs > 0) {
      std::cin >> number;
      numbers.push_back(number);

      numInputs--;
    }

    swaps = 0;
    for(i = 0; i < (int) numbers.size(); i++) {
      for(j = 0; j < ((int) numbers.size()) - i - 1; j++) {
        if(numbers[j] > numbers[j + 1]) {
          swaps++;
          std::swap(numbers[j], numbers[j + 1]);
        }
      }
    }

    std::cout << "Optimal train swapping takes " << swaps << " swaps." << std::endl;
    numTestCases--;
  }
  return 0;
}
