#include <iostream>

int main(int argc, char *argv[]) {
  int numTestCases;
  std::cin >> numTestCases;
  std::string input;
  int inputLength;

  while(numTestCases > 0) {
    std::getline(std::cin, input);

    inputLength = input.length();

    if(inputLength != 0) {
      if((input.compare("1") == 0) || (input.compare("4") == 0) || (input.compare("78") == 0)) {
        std::cout << "+" << std::endl;
      } else if((input.at(inputLength - 2) == '3') && (input.at(inputLength - 1) == '5')) {
        std::cout << "-" << std::endl;
      } else if((input.at(0) == '9') && (input.at(inputLength - 1) == '4')) {
        std::cout << "*" << std::endl;
      } else if((input.at(0) == '1') && (input.at(1) == '9') && (input.at(2) == '0')) {
        std::cout << "?" << std::endl;
      } else {
        std::cout << "+" << std::endl;
      }

      numTestCases--;
    }

  }
  return 0;
}
