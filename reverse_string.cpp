#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
#include <string>

class Solution {
  public:
    void reverseWords(std::string &s) {
      std::stack<std::string> words;
      std::string word;
      std::stringstream ss;
      ss << s;
      while(ss >> word) {
        words.push(word);

      }

      int counter = 0;
      while(!words.empty()) {
        if(counter != 0) {
          std::cout << " ";
        }

        counter++;
        std::cout << words.top();
        words.pop();

      }
      std::cout << std::endl;

    }

};

int main(int argc, char * argv[]) {
  Solution s;
  std::string sentence = " the   sky   is blue";
  s.reverseWords(sentence);
  return 0;
}
