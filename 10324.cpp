#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
  std::string input;
  std::stringstream ss;
  int numQueries, i, j, kase;
  bool same;

  kase = 0;
  while(std::getline(std::cin, input)) {
    if(input.length() == 0) {
      break;
    } else {
      std::vector<int> bitString(input.length(), 0);
      for(i = 1; i < input.length(); i++) {
        if(input.at(i) == input.at(i - 1)) {
          bitString[i] = bitString[i - 1];
        } else {
          bitString[i] = bitString[i - 1] + 1;
        }
      }
      std::getline(std::cin, input);
      ss << input;
      ss >> numQueries;
      ss.clear();
      ss.str("");

      std::cout << "Case " << ++kase << ":" << std::endl;

      while(numQueries > 0) {
        std::getline(std::cin, input);
        ss << input;
        ss >> i >> j;
        ss.clear();
        ss.str("");

        if(i > j) {
          i = i ^ j;
          j = i ^ j;
          i = i ^ j;
        }

        if(bitString[i] == bitString[j]) {
          std::cout << "Yes" << std::endl;
        } else {
          std::cout << "No" << std::endl;
        }
        numQueries--;
      }
    }
  }
  return 0;
}
