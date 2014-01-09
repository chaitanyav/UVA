#include <iostream>
#include <string>
#include <sstream>

long long int division(std::string &a, long long int b, std::string &result) {
  long long int remainder = 0;
  int index, numDigitsA, zeroIndex;
  numDigitsA = (int) a.length();

  for(index = 0; index < numDigitsA; index++) {
    remainder = (remainder * 10) + (a.at(index) - '0');
    result += (remainder / b) + '0';
    remainder %= b;
  }

  for(zeroIndex = 0; result.at(zeroIndex) == '0'; zeroIndex++) {
  }

  result = result.substr(zeroIndex, index);
  return remainder;
}

int main(int argc, char *argv[]) {
  std::string input, a, result("");
  long long int b;
  std::stringstream ss;

  std::getline(std::cin, input);
  ss.clear();
  ss.str("");

  ss << input;
  ss >> a >> b;

  std::cout << "Remainder is " << division(a, b, result) << ", quotient is " << result << std::endl;
  return 0;
}
