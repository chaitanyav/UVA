#include <iostream>
#include <string>
#include <sstream>

std::string multiply(std::string &a, std::string &b) {
  std::string result(""), c, d;
  int numDigitsC, numDigitsD, numDigitsResult, indexC, indexD, index, carry, temp, indexResult = -1;



  c = std::string(a.rbegin(), a.rend());
  d = std::string(b.rbegin(), b.rend());

  numDigitsC = (int) c.length();
  numDigitsD = (int) d.length();
  numDigitsResult = numDigitsC + numDigitsD;

  for(index = 0; index < numDigitsResult; index++) {
    result += '0';
  }

  for(indexC = 0; indexC < numDigitsC; indexC++) {
    carry = 0;
    for(indexD = 0; indexD < numDigitsD; indexD++) {
      temp = ((c.at(indexC) - '0') * (d.at(indexD) - '0')) + carry + (result.at(indexC + indexD) - '0');
      result.at(indexC + indexD) = (temp % 10) + '0';
      carry = (temp / 10);
      if(indexResult < indexC + indexD) {
       indexResult = indexC + indexD;
      }
    }
    while(carry != 0) {
      temp = carry + result.at(indexC + indexD) - '0';
      carry = (temp / 10);
      result.at(indexC + indexD) = (temp % 10) + '0';
      if(indexResult < indexC + indexD) {
        indexResult = indexC + indexD;
      }
      indexD++;
    }
  }

  while(indexResult > 0 && (result.at(indexResult) == '0')) {
    indexResult--;
  }

  result = result.substr(0, indexResult + 1);
  result = std::string(result.rbegin(), result.rend());
  return result;
}

int main(int argc, char *argv[]) {
  std::string a, b, input;
  std::stringstream ss;

  std::getline(std::cin, input);
  ss.str("");
  ss.clear();

  ss << input;
  ss >> a >> b;

  std::cout << multiply(a, b) << std::endl;
  return 0;
}





