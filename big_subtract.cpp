#include <iostream>
#include <string>
#include <sstream>

std::string subtract(std::string &a, std::string &b) {
  int numDigitsA, numDigitsB, diff = 0, carry = 0, temp, index = 0;
  bool sign = false;
  std::string result(""), c, d;

  numDigitsA = (int) a.length();
  numDigitsB = (int) b.length();
  c = a;
  d = b;

  // if a has less digits than b
  if(numDigitsA < numDigitsB) {
    c = b;
    d = a;
    temp = numDigitsA;
    numDigitsA = numDigitsB;
    numDigitsB = temp;
    sign = true;
  }

  // if a, b have same number of digits. swap a, b if b is large than a
  if(numDigitsA == numDigitsB) {
    if(a.compare(b) < 0) {
      c = b;
      d = a;
      temp = numDigitsA;
      numDigitsA = numDigitsB;
      numDigitsB = temp;
      sign = true;
    }
  }

  c = std::string(c.rbegin(), c.rend());
  d = std::string(d.rbegin(), d.rend());

  // c is the largest of a,b
  // d is the smallest of a,b
  for(; numDigitsB < numDigitsA; numDigitsB++) {
    d += '0';
  }

  for(index = 0, carry = 0; index < numDigitsA; index++) {
    diff = c.at(index) - d.at(index) - carry;
    if(diff < 0) {
      carry = 1;
      result += (10 + diff + '0');
    } else {
      result += (diff + '0');
      carry = 0;
    }
  }

  for(index = numDigitsA - 1; index > 0; index--) {
    if(result.at(index) != '0') {
      break;
    }
  }
  result = result.substr(0, index + 1);
  if(sign) {
    result += '-';
  }

  result = std::string(result.rbegin(), result.rend());
  return result;
}

int main(int argc, char * argv[]) {
  std::string input, a, b;
  std::stringstream ss;

  std::getline(std::cin, input);
  ss.clear();
  ss.str("");
  ss << input;
  ss >> a >> b;
  std::cout << subtract(a, b) << std::endl;

  return 0;
}
