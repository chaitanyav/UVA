#include <iostream>

int main(int argc, char *argv[]) {
  int numTestCases, callDurations, mile, juice, callDuration, diff, kase;
  kase = 0;
  std::cin >> numTestCases;

  while(numTestCases > 0) {
    std::cin >> callDurations;
    mile = 0;
    juice = 0;
    while(callDurations > 0) {
      std::cin >> callDuration;
      mile += (callDuration / 30) * 10;
      diff = (callDuration % 30);
      if((diff >= 0) && (diff < 30)) {
        mile += 10;
      }
      juice += (callDuration / 60) * 15;
      diff = (callDuration  % 60);
      if((diff >= 0) && (diff < 60)) {
        juice += 15;
      }
      callDurations--;
    }

    std::cout << "Case " << ++kase << ": ";
    if(mile < juice) {
      std::cout << "Mile " << mile << std::endl;
    } else if(juice < mile) {
      std::cout << "Juice " << juice << std::endl;
    } else if(juice == mile) {
      std::cout << "Mile Juice " << mile << std::endl;
    }
    numTestCases--;
  }
  return 0;
}
