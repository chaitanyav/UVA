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
  int numDocuments, document = 0, numUniqueWords, wordsCounter;
  std::string input;
  std::stringstream ss;
  std::map<std::string, int> indexByWord;
  std::map<int, int> indexByWordNumber;

  scanf("%d", &numDocuments);
  std::getline(std::cin, input);

  while (numDocuments > 0) {
    indexByWord.clear();
    indexByWordNumber.clear();
    wordsCounter = 0;
    numUniqueWords = 0;

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
          if(indexByWord.find(word) == indexByWord.end()) {
            indexByWord[word] = ++numUniqueWords;
            ++wordsCounter;
            indexByWordNumber[wordsCounter] = numUniqueWords;
          } else {
            ++wordsCounter;
            indexByWordNumber[wordsCounter] = indexByWord[word];
          }
          word = "";
        }
      }
      if (word != ""){
        if(indexByWord.find(word) == indexByWord.end()) {
          indexByWord[word] = ++numUniqueWords;
          ++wordsCounter;
          indexByWordNumber[wordsCounter] = numUniqueWords;
        } else {
          ++wordsCounter;
          indexByWordNumber[wordsCounter] = indexByWord[word];
        }
      }
    }

    std::pair<int, int> minRange(1, 999999);
    for (int i = 1; i <= wordsCounter; i++) {
      int index1 = i;
      int index2 = 0;
      std::set<int> seenIndices;
      for (int j = i; (j <= wordsCounter) && (j - i) <= numUniqueWords; j++) {
        if (seenIndices.find(indexByWordNumber[j]) == seenIndices.end()) {
          seenIndices.insert(indexByWordNumber[j]);
          index2 = j;
        } else {
          break;
        }
      }

      if (sz(seenIndices) == numUniqueWords) {
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
