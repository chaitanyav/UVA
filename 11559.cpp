#include <iostream>
#include <cstdio>
#include <climits>

int main(int argc, char *argv[]) {
  int numPersons, budget, numHotels, numWeeks, costPerPerson, week, numBeds, weekCost;
  long int stayCost;

  while(scanf("%d %d %d %d", &numPersons, &budget, &numHotels, &numWeeks) != EOF) {
    stayCost = LONG_MAX;
    while(numHotels > 0) {
      week = 0;
      std::cin >> costPerPerson;
      while(week < numWeeks) {
        weekCost = 0;
        std::cin >> numBeds;
        if(numBeds >= numPersons) {
          weekCost = costPerPerson * numPersons;
          if((weekCost <= budget) && (weekCost <= stayCost))  {
            stayCost = weekCost;
          }
        }
        week++;
      }
      numHotels--;
    }

    if(stayCost == LONG_MAX) {
      std::cout << "stay home" << std::endl;
    } else {
      std::cout << stayCost << std::endl;
    }
  }
  return 0;
}
