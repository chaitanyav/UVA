#include <iostream>
#include <cstdio>

int main(int argc, char *argv[]) {
  int a, b, answer;
  while(scanf("%d %d", &a, &b), ((a != -1) && (b != -1))) {
    if((a == 0 && b == 99) || (a == 99 && b == 0)) {
      answer = 1;
    } else if(a < b) {
      answer = b - a;
    } else if(a > b) {
      answer = a - b;
    } else if(a == b) {
      answer = 0;
    }

    if(answer > 50) {
      answer = 100 - answer;
    }
    std::cout << answer << std::endl;
  }
  return 0;
}
