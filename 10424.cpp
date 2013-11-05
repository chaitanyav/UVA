#include <iostream>
#include <map>
#include <string>
#include <cstdio>

int digitSum(int n) {
  int sum;
  sum = 0;
  while(n > 0) {
    sum = sum + (n % 10);
    n = (n/10);
  }

  if(sum >= 10) {
    return digitSum(sum);
  } else {
    return sum;
  }
}

int main(int argc, char *argv[]) {
  std::string string1, string2;
  std::map<int, int> asciiValueByChar;
  double ratio;

  int i, j, digitSum1, digitSum2, num, denom;
  j = 1;
  for(i = 65; i <= 90; i++) {
    if(asciiValueByChar.find(i) == asciiValueByChar.end()) {
      asciiValueByChar[i] = j;
      asciiValueByChar[tolower(i)] = j;
      ++j;
    }
  }

  while(std::getline(std::cin, string1)) {
    std::getline(std::cin, string2);
    digitSum1 = 0;
    digitSum2 = 0;
    for(i = 0; i < string1.length(); i++) {
      if(isalpha(string1.at(i))) {
        digitSum1 += asciiValueByChar[string1.at(i)];
      }
    }
    for(i = 0; i < string2.length(); i++) {
      if(isalpha(string2.at(i))) {
        digitSum2 += asciiValueByChar[string2.at(i)];
      }
    }
    num = digitSum(digitSum1);
    denom = digitSum(digitSum2);

    if(num > denom) {
      ratio = ((double) denom) / num;
    } else {
      ratio = ((double) num) / denom;
    }
    printf("%.2f %\n", ratio * 100.0);
  }
  return 0;
}
