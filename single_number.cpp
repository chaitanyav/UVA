#include <iostream>

class Solution {
public:
    int singleNumber(int A[], int n) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
          sum = sum ^ A[i];
        }

        return sum;
    }
};


int main(int argc ,char *argv[]) {
  Solution s;
  int A[] = {1, 1, 2, 2, 3, 4, 4};
  std::cout << s.singleNumber(A, 7) << std::endl;
  return 0;
}
