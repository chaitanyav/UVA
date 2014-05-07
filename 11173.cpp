#include <iostream>

unsigned int binary_to_grey(unsigned int num) {
  return num ^ (num >> 1);
}

unsigned int grey_to_binary(unsigned int num) {
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1)
    {
        num = num ^ mask;
    }
    return num;
}


int main(int argc, char *argv[]) {
  int num_test_cases, num_bits, position;
  std::cin >> num_test_cases;

  while(num_test_cases > 0) {
    std::cin >> num_bits >> position;
    unsigned int grey = binary_to_grey(position);
    std::cout << grey << std::endl;
    // std::cout << "The postion is " << position<< std::endl;
    // std::cout << "Grey is " << grey << std::endl;
    // unsigned int binary = grey_to_binary(grey);
    // std::cout << "Binary is " << binary << std::endl;
    num_test_cases--;
  }
  return 0;
}
