#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string input;
  int i;
  i = 0;

  while(std::getline(std::cin, input), input.compare("*") != 0) {
    std::cout << "Case " << ++i << ": ";
    if(input.compare("Hajj") == 0) {
      std::cout << "Hajj-e-Akbar" << std::endl;
    } else {
      std::cout << "Hajj-e-Asghar" << std::endl;
    }
  }
  return 0;
}
