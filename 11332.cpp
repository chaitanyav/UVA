#include <iostream>

int sumDigits(long int n) {
  long int sum = 0;
  while(n > 0) {
    sum += (n%10);
    n /= 10;
  }
  if(sum >= 10) {
    return sumDigits(sum);
  } else {
    return sum;
  }
}

int main(int argc, char *argv[]) {
  long int n;
  while(std::cin >> n, (n != 0)) {
    std::cout << sumDigits(n) << std::endl;
  }
  return 0;
}
