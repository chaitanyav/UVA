#include <iostream>
#include <string>
#include <sstream>

int recurrence(std::string x0) {
    std::stringstream ss;
    ss << x0;
    int x1 = ss.str().length();
    ss.clear();
    ss.str("");
    ss << x1;
    if(ss.str().compare(x0) == 0) {
      return 1;
    } else {
     return  1 + recurrence(ss.str());
    }
}

int main(int argc, char *argv[]) {
  std::string input;

  while(std::getline(std::cin, input)) {
    if(input.compare("END") == 0) {
      break;
    } else {
      std::cout << recurrence(input) << std::endl;
      }
    }
  return 0;
}
