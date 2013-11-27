#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <ctype.h>

std::string sortedChars(std::string word) {
	std::stringstream ss;
	std::vector<char> letters;
	int pos;
	for(pos = 0; pos < (int) word.length(); pos++) {
		letters.push_back(tolower(word.at(pos)));
	}

	std::sort(letters.begin(), letters.end());
	ss.clear();
	ss.str("");
	for(std::vector<char>::iterator it = letters.begin(); it != letters.end(); it++) {
		ss << *it;
	}

	return ss.str();
}
int main(int argc, char *argv[]) {

	std::string input, temp;
	std::stringstream ss;
	std::string word;
	std::vector<std::string> words;
	std::map<std::string, int> countByWord;

	while(std::getline(std::cin, input)) {
		if(input.compare("#") == 0) {
			break;
		}
		ss.clear();
		ss.str("");
		ss << input;

		while(std::getline(ss, word, ' ')) {
			words.push_back(word);			
			temp = sortedChars(word);

			if(countByWord.find(temp) != countByWord.end()) {
				countByWord[temp]++;
			} else {
				countByWord[temp] = 1;
			}
		}
	}

	std::sort(words.begin(), words.end());
	for(std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++) {
		if(countByWord[sortedChars(*it)] == 1) {
			std::cout << *it << std::endl;
		}
	}

	//std::cin.ignore();
	//std::cin.ignore();
	return 0;
}