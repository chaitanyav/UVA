#include <iostream>
#include <vector>
#include <algorithm>

void diceRoll(int dice, std::vector<int> &chosen) {
  if(dice == 0) {
    for(std::vector<int>::iterator it = chosen.begin(); it != chosen.end(); it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  } else {
    for(int i = 1; i <= 6; ++i) {
      chosen.push_back(i);
      diceRoll(dice - 1, chosen);
      chosen.erase(chosen.begin() + ((int) chosen.size()) - 1);
    }
  }
}


int main(int argc, char *argv[]) {
  std::vector<int> chosen;
  diceRoll(3, chosen);
  return 0;
}
