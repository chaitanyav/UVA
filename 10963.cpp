#include <iostream>
#include <climits>

int main(int argc, char *argv[]) {
  int numTestCases, numColumns, x, y, length;
  bool isGapClosed;

  std::cin >> numTestCases;
  while(numTestCases > 0) {
    length = INT_MAX;
    isGapClosed = true;
    std::cin >> numColumns;
      while(numColumns > 0) {
        std::cin >> x >> y;
        if(length == INT_MAX) {
          length = x - y;
        }

        if(length != (x - y)) {
          isGapClosed = false;
        }
        numColumns--;
      }

      if(isGapClosed) {
        std::cout << "yes" << std::endl;
      } else {
        std::cout << "no" << std::endl;
      }


       numTestCases--;
       if(numTestCases > 0) {
         std::cout << std::endl;
       }

  }
  return 0;
}
