#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#define sz(c) (int)c.size()

int main(int argc, char *argv[]) {
  long int numCases, m, n, number, total;
  std::multiset<int> numbers;
  std::multiset<int>::iterator it;
  scanf("%ld", &numCases);

  while(numCases > 0) {
    numbers.clear();
    total = 0;

    scanf("%ld %ld", &m, &n);
    for(int i = 0; i < m; i++) {
      scanf("%ld", &number);
      numbers.insert(number);
    }

    for(int i = 0; i < n; i++) {
      scanf("%ld", &number);
      if((it = numbers.find(number)) != numbers.end()) {
        numbers.erase(it);
      } else {
        ++total;
      }
    }

    printf("%ld\n", total + sz(numbers));
    numCases--;
  }
  return 0;
}
