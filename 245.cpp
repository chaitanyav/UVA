#include <iostream>
#include <string>
#include <list>
#include <ctype.h>

void printToken(std::list<std::string> &words, int index) {
  std::string temp;
  std::list<std::string>::iterator lit = words.begin();
  for(int i = 1; lit != words.end(); lit++,++i) {
    if (i == index) {
      std::cout << *lit;
      temp = *lit;
      break;
    }
  }
  words.remove(temp);
  words.push_front(temp);
}

int main(int argc, char *argv[]) {
  std::string input;
  std::list<std::string> words;
  std::string token;
  int num = 0;
  while(true) {
    std::getline(std::cin, input);
    if(input == "0") {
      break;
    }
    for(std::string::iterator it=input.begin(); it != input.end(); it++) {
      if(isalpha(*it)) {
        std::cout << *it;
        if(token.empty()) {
          token = *it;
        } else {
        token += *it;
        }
      } else if(isdigit(*it)){
        num = ((num * 10) + (*it - '0'));
      } else if(isspace(*it)) {
        if(num > 0) {
          printToken(words, num);
          num = 0;
        } else {
          if(!token.empty()) {
            words.push_front(token);
            token.clear();
          }
        }
        std::cout << *it;
      } else {
        if(num > 0) {
          printToken(words, num);
          num = 0;
        }
        if(!token.empty()) {
          words.push_front(token);
          token.clear();
        }
        std::cout << *it;
      }
    }
    if(num != 0) {
      printToken(words, num);
      num = 0;
    }
    if(!token.empty()) {
      words.push_front(token);
      token.clear();
    }
    std::cout << std::endl;
  }

  return 0;
}
