#include <iostream>
#include <list>
#include <algorithm>
#include <string>

int main(int argc, char *argv[]) {
  std::list<char> beiju_text;
  std::string input;
  while(std::getline(std::cin, input)) {
    std::string::iterator sit = input.begin();
    std::list<char>::iterator lit = beiju_text.begin();
    for(; sit != input.end(); sit++) {
      char c = *sit;
      if(c == '[') {
        lit = beiju_text.begin();
      } else if(c == ']') {
        lit = beiju_text.end();
      } else {
        beiju_text.insert(lit, c);
      }
    }

    for(lit = beiju_text.begin(); lit != beiju_text.end(); lit++) {
      std::cout << *lit;
    }
    std::cout << std::endl;
    beiju_text.clear();
  }
  return 0;
}
