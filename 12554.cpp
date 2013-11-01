#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, char *argv[]) {
  int numPersons, word, numWords, i;
  std::string song[16] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
  std::string name;
  std::vector<std::string> names;

  std::cin >> numPersons;
  while(numPersons > 0) {
    std::getline(std::cin, name);
    if(name.length() > 0) {
      names.push_back(name);
      numPersons--;
    }
  }

  numPersons = names.size();
  numWords = 16;
  i = 1;
  do {
    numWords = i * 16;
    i++;
  }while(numWords < numPersons);
    for(word = 0; word < numWords; word++) {
      std::cout << names[word % numPersons] << ": " << song[word % 16] << std::endl;
    }
  return 0;
}
