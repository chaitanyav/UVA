#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <utility>
#include <cctype>

#define sz(c) (int)c.size()

int main(int argc, char *argv[]) {
  int numDocuments, document = 0;
  std::string input;
  std::stringstream ss;
  std::set<std::string> uniqueWords;
  std::vector<std::string> words;

  scanf("%d", &numDocuments);
  std::getline(std::cin, input);

  while (numDocuments > 0) {
    uniqueWords.clear();
    words.clear();

    while (std::getline(std::cin, input), input.compare("END") != 0) {
      ss.clear();
      ss.str("");
      ss << input;
      std::string word = "";
      for (std::string::iterator it = input.begin(); it != input.end(); it++) {
        if (isalpha(*it)) {
          word += *it;
        }
        else if (word != "" && !isalpha(*it)){
          uniqueWords.insert(word);
          words.push_back(word);
          word = "";
        }
      }
      if (word != ""){
        uniqueWords.insert(word);
        words.push_back(word);
      }
    }

    std::pair<int, int> minRange(1, 999999);
    for (int i = 0; i < sz(words); i++) {
      int index1 = i;
      int index2 = 0;
      std::set<std::string> seenWords;
      for (int j = i; (j < sz(words)) && (j - i) < sz(uniqueWords); j++) {
        if (seenWords.find(words[j]) == seenWords.end()) {
          seenWords.insert(words[j]);
          index2 = j;
        } else {
          break;
        }
      }

      if (sz(seenWords) == sz(uniqueWords)) {
        index1++;
        index2++;
        if((index2 - index1) < (minRange.second - minRange.first)) {
          minRange.first = index1;
          minRange.second = index2;
        } else if((index2 - index1) == (minRange.second - minRange.first)) {
          if(index1 < minRange.first) {
            minRange.first = index1;
            minRange.second = index2;
          }
        }
      }
    }

    printf("Document %d: %d %d\n", ++document, minRange.first, minRange.second);
    numDocuments--;
  }
  return 0;
}
