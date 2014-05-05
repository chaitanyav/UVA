#include <iostream>
#include <cstring>
#include <cstdlib>

bool has_repeated_digits(int n) {
  unsigned char digits[10];
  int digit = 0;
  bool result = false;
  memset(digits, 0, 10);

  while(n > 0) {
    digit = n % 10;
    if(digits[digit] == 0) {
      digits[digit] = 1;
    } else {
      result = true;
      break;
    }
    n = n / 10;
  }

  return result;
}

int main(int argc, char *argv[]) {
  int numbers[5001];
  int index = 0;
  int m, n;

  memset(numbers, 0, sizeof(int) * 5001);
  for(index = 1; index < 5001; index++) {
    if(has_repeated_digits(index)) {
      numbers[index] = numbers[index - 1];
    } else {
      numbers[index] = numbers[index - 1] + 1;
    }
  }


  while(std::cin >> m >> n) {
    std::cout << numbers[n] - numbers[m - 1] << std::endl;
  }
  return 0;
}
