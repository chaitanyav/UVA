#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <utility>


int main(int argc, char *argv[]) {
  int numTestCases, numBattleFields, numGreen, numBlue, power, countSpace = 0;
  std::multiset<int> greenArmy;
  std::multiset<int> blueArmy;
  std::vector< std::pair<int, int> > battlePair;

  scanf("%d", &numTestCases);

  while(numTestCases > 0) {
    greenArmy.clear();
    blueArmy.clear();

    scanf("%d %d %d", &numBattleFields, &numGreen, &numBlue);

    while(numGreen > 0) {
      scanf("%d", &power);
      greenArmy.insert(power);
      numGreen--;
    }

    while(numBlue > 0) {
      scanf("%d", &power);
      blueArmy.insert(power);
      numBlue--;
    }

    while(!greenArmy.empty() && !blueArmy.empty()) {

      battlePair.clear();
      int battles = 0;
      while(!greenArmy.empty() && !blueArmy.empty() && (battles < numBattleFields)) {
        int greenPower, bluePower;

        for(std::multiset<int>::reverse_iterator it = greenArmy.rbegin(); it != greenArmy.rend(); it++) {
          greenPower = *it;
          break;
        }

        for(std::multiset<int>::reverse_iterator it = blueArmy.rbegin(); it != blueArmy.rend(); it++) {
          bluePower = *it;
          break;
        }
        std::pair<int, int> soldiers = std::make_pair(greenPower, bluePower);
        battlePair.push_back(soldiers);
        std::multiset<int>::iterator it1 = greenArmy.find(greenPower);
        std::multiset<int>::iterator it2 = blueArmy.find(bluePower);
        greenArmy.erase(it1);
        blueArmy.erase(it2);
        battles++;
      }

      while(battles > 0) {
        std::pair<int, int> soldiers = battlePair[battles - 1];
        int diff;
        if(soldiers.first > soldiers.second) {
          diff = soldiers.first - soldiers.second;
          greenArmy.insert(diff);
        } else if(soldiers.second > soldiers.first) {
          diff = soldiers.second - soldiers.first;
          blueArmy.insert(diff);
        }
        battles--;
      }
    }

    if(countSpace++ > 0) {
      printf("\n");
    }
    if(greenArmy.empty() && blueArmy.empty()) {
      printf("green and blue died\n");
    } else if(!greenArmy.empty()) {
      printf("green wins\n");
      for(std::multiset<int>::reverse_iterator it = greenArmy.rbegin(); it != greenArmy.rend(); it++) {
        printf("%d\n", *it);
      }
    } else if(!blueArmy.empty()) {
      printf("blue wins\n");
      for(std::multiset<int>::reverse_iterator it = blueArmy.rbegin(); it != blueArmy.rend(); it++) {
        printf("%d\n", *it);
      }
    }

    numTestCases--;
  }
  return 0;
}
