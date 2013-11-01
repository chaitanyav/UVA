#include <iostream>

int main(int argc, char *argv[]) {
  int numTestCases, highJumps, lowJumps, numJumps, prevJump, jump, i;
  i = 0;
  std::cin >> numTestCases;

  while(numTestCases > 0) {
    std::cin >> numJumps;
    prevJump = 0;
    lowJumps = 0;
    highJumps = 0;
    while(numJumps > 0) {
      std::cin >> jump;
      if((prevJump != 0)) {
        if(prevJump > jump) {
          lowJumps++;
        }
        if(prevJump < jump) {
          highJumps++;
        }
      }
      prevJump = jump;
      numJumps--;
    }
    std::cout << "Case " << ++i << ": " << highJumps << " " << lowJumps << std::endl;
    numTestCases--;
  }

  return 0;
}
