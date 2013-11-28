#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

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
	for(std::vector<char>::iterator it = letters.begin(); it != letters.end(); it++){
		ss << *it;
	}

	return ss.str();
}

int main(int argc, char *argv[]) {
	std::string word, temp;
	std::map<std::string, std::vector<std::string> > stringsBySortedChars;
	std::string sortedCharsString;
	// reading in the dictionary words
	while(std::getline(std::cin, word)) {
		if(word.compare("XXXXXX") == 0) {
			break;
		} else {
			sortedCharsString = sortedChars(word);
			if(stringsBySortedChars.find(sortedCharsString) == stringsBySortedChars.end()) {
				std::vector<std::string> temp;
				temp.push_back(word);
				stringsBySortedChars[sortedCharsString] = temp;
			} else {
				stringsBySortedChars[sortedCharsString].push_back(word);
			}

		}
	}

	//reading in the words
	while(std::getline(std::cin, word)) {
		if(word.compare("XXXXXX") == 0) {
			break;
		} else {
			sortedCharsString = sortedChars(word);
			if(stringsBySortedChars.find(sortedCharsString) != stringsBySortedChars.end()) {
				std::sort(stringsBySortedChars[sortedCharsString].begin(), stringsBySortedChars[sortedCharsString].end());
				for(std::vector<std::string>::iterator it = stringsBySortedChars[sortedCharsString].begin(); it != stringsBySortedChars[sortedCharsString].end(); it++) {
					std::cout << *it << std::endl;
				}				
			} else {
				std::cout << "NOT A VALID WORD" <<std::endl;
			}
			std::cout << "******" << std::endl;
		}
	}

	//std::cin.ignore();
	//std::cin.ignore();
	return 0;
}