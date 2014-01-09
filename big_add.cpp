#include <iostream>
#include <string>
#include <sstream>

std::string add(std::string &a, std::string &b) {
  int index, sum = 0, carry = 0, numDigitsA, numDigitsB;
  std::string result("");

  numDigitsA = (int) a.length();
  numDigitsB = (int) b.length();

  std::string c(a.rbegin(), a.rend());
  std::string d(b.rbegin(), b.rend());

  for(index = 0; index < numDigitsA && index < numDigitsB; index++) {
    sum = (c.at(index) - '0') + (d.at(index) - '0') + carry;
    result += ((sum % 10) + '0');
    carry = (sum / 10);
  }

  for(; index < numDigitsA; index++) {
    sum = c.at(index) + carry - '0';
    result += ((sum % 10) + '0');
    carry = (sum / 10);
  }

  for(; index < numDigitsB; index++) {
    sum = d.at(index) + carry - '0';
    result += ((sum % 10) + '0');
    carry = (sum / 10);
  }

  if(carry != 0) {
    result += carry + '0';
  }

  if(((int) result.length()) == 0) {
    result = "0";
  }

  for(index = ((int) result.length()) - 1; index > 0; index--) {
    if(result.at(index) != '0') {
      break;
    }
  }

  result = result.substr(0, index + 1);
  result = std::string(result.rbegin(), result.rend());
  return result;
}


int main(int argc, char *argv[]) {
  std::string a, b, input;
  std::stringstream ss;

  std::getline(std::cin, input);
  ss.clear();
  ss.str("");

  ss << input;
  ss >> a >> b;
  std::cout << add(a, b) << std::endl;
  return 0;
}
