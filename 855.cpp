#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
  int numTestCases, gridSizeX, gridSizeY, numLocations, n, x, y;
  std::vector<int> gridX;
  std::vector<int> gridY;

  std::cin >> numTestCases;
  while(numTestCases > 0) {
    std::cin >> gridSizeX >> gridSizeY >> numLocations;
    gridX.clear();
    gridY.clear();

    while(numLocations > 0) {
      std::cin >> x >> y;
      gridX.push_back(x);
      gridY.push_back(y);
      numLocations--;
    }

    std::sort(gridX.begin(), gridX.end());
    std::sort(gridY.begin(), gridY.end());

    numLocations = (int) gridX.size();
    if(numLocations % 2 == 0) {
      n = (numLocations / 2) - 1;
    } else {
      n = (numLocations / 2);
    }
    std::cout << "(Street: " << gridX[n] << ", Avenue: " << gridY[n] << ")" << std::endl;
    numTestCases--;
  }
  return 0;
}
