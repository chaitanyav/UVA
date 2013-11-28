#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <iomanip>

std::string sortedChars(std::string &word) {
	std::stringstream ss;
	int pos;
	std::vector<char> letters;

	ss.clear();
	ss.str("");

	for(pos = 0; pos < (int) word.length(); pos++) {
		letters.push_back(word.at(pos));
	}

	std::sort(letters.begin(), letters.end());
	for(std::vector<char>::iterator it = letters.begin(); it != letters.end(); it++) {
		ss << *it;
	}

	return ss.str();
}

int main(int argc, char *argv[]) {
	int numTestCases, numDictionaryWords, count, spaceCounter;
	std::string word, sortedCharsString;
	std::map<std::string, std::vector<std::string> > stringsBySortedCharsString;
	spaceCounter = 0;
	std::cin >> numTestCases;
	std::getline(std::cin, word);

	while(numTestCases > 0) {
		std::getline(std::cin, word);
		std::cin >> numDictionaryWords;
		stringsBySortedCharsString.clear();
		std::getline(std::cin, word);

		while(numDictionaryWords > 0) {
			std::getline(std::cin, word);

			sortedCharsString = sortedChars(word);
			if(stringsBySortedCharsString.find(sortedCharsString) != stringsBySortedCharsString.end()) {
				stringsBySortedCharsString[sortedCharsString].push_back(word);
			} else {
				std::vector<std::string> temp;
				temp.push_back(word);
				stringsBySortedCharsString[sortedCharsString] = temp;
			}
			numDictionaryWords--;
		}

		

		while(std::getline(std::cin, word)) {
			if(word.compare("END") == 0) {
				break;
			}
			sortedCharsString = sortedChars(word);
			std::cout << "Anagrams for: " << word << std::endl;
			if(stringsBySortedCharsString.find(sortedCharsString) != stringsBySortedCharsString.end()) {				
				count = 0;				
				for(std::vector<std::string>::iterator it = stringsBySortedCharsString[sortedCharsString].begin(); it != stringsBySortedCharsString[sortedCharsString].end(); it++) {
					std::cout << std::setw(3) ;
					std::cout << ++count;
					std::cout << ") " << *it << std::endl;
				}
			} else {
				std::cout << "No anagrams for: " << word << std::endl;
			}
		}
		if(spaceCounter++ > 0) {
			std::cout << std::endl;
		}
		numTestCases--;
	}
	return 0;
}