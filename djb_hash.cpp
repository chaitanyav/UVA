#include <iostream>
#include <string>

unsigned int djbHash(std::string &str) {
  int i;
  unsigned int hash;

  hash = 5381;
  for(i = 0; i < (int)str.size(); i++) {
    hash = (hash << 5) + hash + str.at(i);
  }

  return hash;
}

int main(int argc, char *argv[]) {
  std::string str(argv[1]);
  std::cout << djbHash(str) << std::endl;
  return 0;
}

