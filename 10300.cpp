#include <iostream>

int main(int argc, char *argv[]) {
  int numTestCases, numFarmers, farmSize, numAnimals, farmFriendliness, budget;
  std::cin >> numTestCases;

  while(numTestCases > 0) {
    budget = 0;
    std::cin >> numFarmers;

    while(numFarmers > 0) {
      std::cin >> farmSize >> numAnimals >> farmFriendliness;
      budget += farmSize * farmFriendliness;
      numFarmers--;
    }

    std::cout << budget << std::endl;
    numTestCases--;
  }
  return 0;
}
