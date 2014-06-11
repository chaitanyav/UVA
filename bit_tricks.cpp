#include <iostream>
#include <cassert>


unsigned int clearLastBit(unsigned int number) {
  return number & (number - 1);
}

unsigned int getLowestSetBit(unsigned int number) {
  return number & ~(number - 1);
}

unsigned int countBitsSet(unsigned int number) {
  // other way to do this
  // is to clear the last bit number & (number - 1) until number is not zero
  // the number of iteration of the loop is the number of bits set
  unsigned int count = 0;
  for(auto index = 0; index < 32; index++) {
    if(number & (1 << index)) {
      ++count;
    }
  }

  return count;
}

unsigned int foldOver(unsigned int number) {
  number |= (number >> 1);
  number |= (number >> 2);
  number |= (number >> 4);
  number |= (number >> 8);
  number |= (number >> 16);

  return number;
}

unsigned int isolateHighestSetBit(unsigned int number) {
  number = foldOver(number);
  return number & ~(number >> 1);
}

unsigned int nextPowerOfTwo(unsigned int number) {
  number = foldOver(number);
  return number + 1;
}

int main(int argc, char *argv[]) {
  assert(clearLastBit(5) == 4);
  assert(clearLastBit(0) == 0);
  assert(clearLastBit(2) == 0);
  assert(clearLastBit(4) == 0);
  assert(clearLastBit(8) == 0);

  assert(getLowestSetBit(1) == 1);
  assert(getLowestSetBit(2) == 2);
  assert(getLowestSetBit(4) == 4);
  assert(getLowestSetBit(8) == 8);
  assert(getLowestSetBit(5) == 1);
  assert(getLowestSetBit(9) == 1);

  assert(countBitsSet(0) == 0);
  assert(countBitsSet(1) == 1);
  assert(countBitsSet(5) == 2);
  assert(countBitsSet(7) == 3);
  assert(countBitsSet(8) == 1);
  assert(countBitsSet(16) == 1);

  assert(foldOver(5) == 7);
  assert(foldOver(0) == 0);
  assert(foldOver(1) == 1);
  assert(foldOver(8) == 15);
  assert(foldOver(6) == 7);

  assert(isolateHighestSetBit(5) == 4);
  assert(isolateHighestSetBit(0) == 0);
  assert(isolateHighestSetBit(7) == 4);

  assert(nextPowerOfTwo(0) == 1);
  assert(nextPowerOfTwo(1) == 2);
  assert(nextPowerOfTwo(6) == 8);
  assert(nextPowerOfTwo(7) == 8);
  assert(nextPowerOfTwo(5) == 8);
  assert(nextPowerOfTwo(4) == 8);
  return 0;
}
