#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>

int main(int argc, char *argv[]) {
  std::string input;
  std::set<std::string> words;


  std::string temp("");
  while(std::getline(std::cin, input)) {
    std::transform(input.begin(), input.end(), input.begin(), tolower);

    for(std::string::iterator it = input.begin(); it != input.end(); it++) {
      if(isalpha(*it)) {
        temp += *it;
        if((it - input.begin()) == ((int) input.size() - 1)) {
          words.insert(temp);
          temp = "";
        }
      } else if(((*it) == '-') && ((it - input.begin()) != ((int)input.size() - 1))) {
        temp += *it;
      } else if((*it != '-')  && (temp.compare("") != 0) && (!isalpha(*it))) {
        words.insert(temp);
        temp = "";
      }
    }
  }

  for(std::set<std::string>::iterator it = words.begin(); it != words.end(); it++) {
    std::cout << *it << std::endl;
  }
  return 0;
}
