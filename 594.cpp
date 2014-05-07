#include <iostream>

int main(int argc, char *argv[]) {
  int in_number, out_number = 0;

  while(std::cin >> in_number) {
      unsigned int b0 = (in_number & 0xff);
      unsigned int b1 = (in_number & 0xff00);
      unsigned int b2 = (in_number & 0xff0000);
      unsigned int b3 = (in_number & 0xff000000);

      out_number = (b0 << 24) | (b1 << 8) | (b2 >> 8) | (b3 >> 24);
      std::cout << in_number << " converts to " << out_number << std::endl;
  }
  return 0;
}
