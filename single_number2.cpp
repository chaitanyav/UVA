#include <iostream>
#include <algorithm>

class Solution {
public:
    int singleNumber2(int A[], int n) {
        int ones = 0, twos = 0, common_bit_mask = 0;
        for(int i = 0; i < n; i++) {
            twos = twos | (ones & A[i]);
            ones = (ones ^ A[i]);
            common_bit_mask =   ~(ones & twos);
            ones &= common_bit_mask;
            twos &= common_bit_mask;
        }

        return ones;
    }
};

int main(int argc, char *argv[]) {
  Solution s;
  int A[] = {2, 2, 3, 2};
  std::cout << s.singleNumber2(A, 4) << std::endl;
  return 0;
}
