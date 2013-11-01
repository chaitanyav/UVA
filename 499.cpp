#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

int main(int argc, char *argv[]) {
  std::string input;
  char alpha[256];
  int i, max;
  memset(alpha, 0, 256);
  while(std::getline(std::cin, input)) {
    max = 0;
    for(i = 0; i < input.length(); i++) {
      if(isalpha(input.at(i))) {
        alpha[input.at(i)]++;
        if(alpha[input.at(i)] >= max) {
          max = alpha[input.at(i)];
        }
      }
    }

    for(i = 0; i < 256; i++) {
      if((alpha[i] == max) && isalpha(i)) {
        printf("%c", i);
      }
    }

    std::cout << " " << max << std::endl;
    memset(alpha, 0, 256);
  }
  return 0;
}
