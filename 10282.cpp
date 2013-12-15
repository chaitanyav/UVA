#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>

#define len(s) (int)(s.length())

int main(int argc, char *argv[]) {
	std::string input;
	std::stringstream ss;
	std::map<std::string, std::string>englishWordByForeignWord;

	while(std::getline(std::cin, input), len(input) != 0) {
		ss.clear();
		ss.str("");
		ss << input;
		std::string englishWord, foreignWord;
        ss >> englishWord >> foreignWord;
		englishWordByForeignWord[foreignWord] = englishWord;
	}

	while(std::getline(std::cin, input)) {
		if(englishWordByForeignWord.find(input) != englishWordByForeignWord.end()) {
			std::cout << englishWordByForeignWord[input] << std::endl;
		} else {
			std::cout << "eh" << std::endl;
		}
	}
	return 0;
}