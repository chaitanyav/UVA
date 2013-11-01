#include <iostream>

int main(int argc, char *argv[]) {
  int numTestCases, numCreatures, max, speed, i;
  i = 0;
  std::cin >> numTestCases;

  while(numTestCases > 0) {
    std::cin >> numCreatures;
    max = 0;
    while(numCreatures > 0) {
      std::cin >> speed;
      if(speed > max) {
        max = speed;
      }
      numCreatures--;
    }

    std::cout << "Case " << ++i << ": " << max << std::endl;
    numTestCases--;
  }
  return 0;
}
