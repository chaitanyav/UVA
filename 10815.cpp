#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <cctype>

int main(int argc, char *argv[]) {
  std::string input;
  std::set<std::string> words;
  while(std::getline(std::cin, input)) {
    std::transform(input.begin(), input.end(), input.begin(), tolower);
    std::string temp("");
    for(std::string::iterator it = input.begin(); it != input.end(); it++) {
      if(isalpha(*it)) {
        temp += *it;
      } else if(temp.compare("") != 0){
        words.insert(temp);
        temp = "";
      }
    }
    if(temp.compare("") != 0) {
      words.insert(temp);
    }
  }

  for(std::set<std::string>::iterator it = words.begin(); it != words.end(); it++) {
    std::cout << *it << std::endl;
  }
  return 0;
}
