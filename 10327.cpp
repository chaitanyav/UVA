
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
  int  numInputs, number, i, j, swaps, temp;
  std::vector<int> numbers;


  while(std::cin >> numInputs) {
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

    std::cout << "Minimum exchange operations : " << swaps << std::endl;
  }
  return 0;
}
