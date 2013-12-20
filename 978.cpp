#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>

int main(int argc, char *argv[]) {
  int numTestCases, numBattleFields, numGreen, numBlue, power, countSpace = 0;
  std::priority_queue<int> greenArmy;
  std::priority_queue<int> blueArmy;
  std::vector< std::pair<int, int> > battlePair;

  scanf("%d", &numTestCases);

  while(numTestCases > 0) {
    greenArmy = std::priority_queue<int>();
    blueArmy = std::priority_queue<int>();

    scanf("%d %d %d", &numBattleFields, &numGreen, &numBlue);

    while(numGreen > 0) {
      scanf("%d", &power);
      greenArmy.push(power);
      numGreen--;
    }

    while(numBlue > 0) {
      scanf("%d", &power);
      blueArmy.push(power);
      numBlue--;
    }

    while(!greenArmy.empty() && !blueArmy.empty()) {

      battlePair.clear();
      int battles = 0;
      while(!greenArmy.empty() && !blueArmy.empty() && (battles < numBattleFields)) {
        std::pair<int, int> soldiers = std::make_pair(greenArmy.top(), blueArmy.top());
        battlePair.push_back(soldiers);
        greenArmy.pop();
        blueArmy.pop();
        battles++;
      }

      while(battles > 0) {
        std::pair<int, int> soldiers = battlePair[battles - 1];
        int diff;
        if(soldiers.first > soldiers.second) {
          diff = soldiers.first - soldiers.second;
          greenArmy.push(diff);
        } else if(soldiers.second > soldiers.first) {
          diff = soldiers.second - soldiers.first;
          blueArmy.push(diff);
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
      while(!greenArmy.empty()) {
        printf("%d\n", greenArmy.top());
        greenArmy.pop();
      }
    } else if(!blueArmy.empty()) {
      printf("blue wins\n");
      while(!blueArmy.empty()) {
        printf("%d\n", blueArmy.top());
        blueArmy.pop();
      }
    }

    numTestCases--;
  }
  return 0;
}
