#include <iostream>

int main(int argc, char *argv[]) {
  int numTestCases, height, prevHeight, i;
  bool asc, desc;
  std::cin >> numTestCases;

  std::cout << "Lumberjacks:" << std::endl;

  while(numTestCases > 0) {
    asc = true;
    desc = true;
    prevHeight = 0;

    for(i = 0; i < 10; i++) {
      std::cin >> height;
      if(prevHeight != 0) {
        if(prevHeight < height) {
          asc = asc & true;
          desc = desc & false;
        }
        if(prevHeight > height){
          asc = asc & false;
          desc = desc & true;
        }
      }
      prevHeight = height;
    }

    if(asc || desc) {
      std::cout << "Ordered" << std::endl;
    } else {
      std::cout << "Unordered" << std::endl;
    }

    numTestCases--;
  }
  return 0;
}
