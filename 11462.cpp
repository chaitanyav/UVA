#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
  int numAges, age, counter;

  while(scanf("%d", &numAges), numAges != 0) {
    std::vector<int>ages(101, 0);

    counter = numAges;
    while(counter> 0) {
      scanf("%d", &age);
      ages[age]++;
      counter--;
    }

    for(age = 0; age < 101; age++) {
      if(ages[age] > 0) {
        while(ages[age] > 0) {
          printf("%d", age);
          ages[age]--;
          if(--numAges > 0) {
            printf(" ");
          }
        }
      }
    }
    printf("\n");
  }
  return 0;
}
