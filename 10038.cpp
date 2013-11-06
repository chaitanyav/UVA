#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <algorithm>

int main(int argc, char *argv[]) {
  int n, num, prev, diff, m;
  bool flag;
  std::map<int, bool> flagByNum;

  while(scanf("%d", &n) != EOF) {
    prev = 0;
    m = n;
    flagByNum.clear();

    while(n > 0) {
      scanf("%d", &num);
      if(prev == 0) {
        prev = num;
      } else {
        diff = abs(num - prev);
        prev = num;
        if(flagByNum.find(diff) == flagByNum.end()) {
          flagByNum[diff] = true;
        }
      }
      n--;
    }

    flag = true;
    for(num = 1; num <= (m - 1); num++) {
      if(flagByNum.find(num) != flagByNum.end()) {
        flag = flag && true;
      } else {
        flag = false;
        break;

      }
    }

    if(flag) {
      printf("Jolly\n");
    } else {
      printf("Not jolly\n");
    }
  }

  return 0;
}
