#include <iostream>
#include <cassert>

bool power_of_two(unsigned int num) {
  auto onesCount = 0;
  for(auto index = 0; index < 32; index++) {
    if(0x1 & num) {
      ++onesCount;
    }
    num = num >> 1;
  }

  return (onesCount == 1);
}

bool power_of_two_shift(unsigned int num) {
    unsigned int temp = 0x1;
    while(temp != 0) {
      if(temp == num) {
        return true;
      }
      temp = temp << 1;
    }

    return false;
}

int main(int argc, char *argv[]) {
  assert(power_of_two(2));
  assert(power_of_two(4));
  assert(power_of_two(8));
  assert(power_of_two(16));
  assert(power_of_two(2048));

  assert(power_of_two_shift(2));
  assert(power_of_two_shift(4));
  assert(power_of_two_shift(8));
  assert(power_of_two_shift(16));
  assert(power_of_two_shift(2048));

  assert(power_of_two(1));
  assert(power_of_two(0));
  return 0;
}
