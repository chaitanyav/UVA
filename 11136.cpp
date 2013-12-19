#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

int main(int argc, char *argv[]) {
  long int numDays, numBills, billAmount, total, max, min;
  std::multiset<long int> billAmounts;
  while(true) {
    scanf("%ld", &numDays);
    if(numDays == 0) {
      break;
    }

    total = 0;
    billAmounts.clear();

    while(numDays > 0) {
      scanf("%ld", &numBills);
      while(numBills > 0) {
        scanf("%ld", &billAmount);
        billAmounts.insert(billAmount);
        numBills--;
      }

      min = 0;
      max = 0;
      for(std::multiset<long int>::iterator it = billAmounts.begin(); it != billAmounts.end(); it++) {
        min = *it;
        break;
      }

      for(std::multiset<long int>::reverse_iterator it = billAmounts.rbegin(); it != billAmounts.rend(); it++) {
        max = *it;
        break;
      }

      billAmounts.erase(billAmounts.find(max));
      billAmounts.erase(billAmounts.find(min));
      total += (max - min);
      numDays--;
    }

   printf("%ld\n", total);
  }
  return 0;
}
