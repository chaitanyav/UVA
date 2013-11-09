#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <sstream>

int main(int argc, char *argv[]) {
  int n, numCards, prevIndex, length, index, numCardsDropped;
  std::string input, card, word;
  std::stringstream ss;

  while(std::getline(std::cin, input), input.compare("0") != 0) {
    ss << input;
    ss >> n;
    ss.clear();
    ss.str("");


    std::vector<std::string>  cards(n, "");
    numCards = n;
    index = 0;
    numCardsDropped = 0;
    while(n > 0) {
      std::getline(std::cin, input);
      ss << input;
      ss >> card >> word;
      ss.clear();
      ss.str("");

      length = (int)word.length();

      index = (index + length) % (numCards);
        if(index > 0) {
          if(cards[index - 1].compare("") == 0) {
            cards[index - 1] = card;
            //break;
          } else {
            //index = (index + 1) % numCards;
          }
        } else {
          if(cards[index].compare("") == 0) {
            cards[index] = card;
            //break;
          } else {
            //index = (index + 1) % numCards;
          }
        }

      std::cout << "card " << card <<" index  " << (index - 1) << " " <<  " numCards " <<  numCards << std::endl;
      n--;
    }

    for(std::vector<std::string>::iterator it = cards.begin(); it != cards.end(); it++) {
      if((*it).compare("") == 0) {
        std::cout << "-";
      } else {
        std::cout << *it;
      }

      if((it + 1) != cards.end()) {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
