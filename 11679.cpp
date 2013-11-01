#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
  int numBanks, numDeb, reserve, bank, debtor, creditor, debenture;
  bool bailout;
  std::vector<int> reserves;

  while(scanf("%d %d", &numBanks, &numDeb), (numBanks || numDeb)) {
    reserves.clear();
    bailout = false;

    while(numBanks > 0) {
      std::cin >> reserve;
      reserves.push_back(reserve);
      numBanks--;
    }
    while(numDeb > 0) {
      std::cin >> debtor >> creditor >> debenture;
      reserves[debtor - 1] -= debenture;
      reserves[creditor - 1] += debenture;
      numDeb--;
    }

    for(bank = 0; bank < (int) reserves.size(); bank++) {
      if(reserves[bank] < 0) {
        bailout = true;
        break;
      }
    }
    if(bailout) {
      std::cout << "N" << std::endl;
    } else {
      std::cout << "S" << std::endl;
    }
  }
  return 0;
}
