#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>


bool stringCompare(std::string a, std::string b) {
	return ((a.compare(b)) == 0);
}

std::string sortedChars(std::string line) {
	int pos;
	std::string word;
	std::stringstream ss;
	std::vector<char> letters;
	ss.clear();
	ss.str("");
	for(pos = 0; pos < (int) line.size(); pos++) {
		if(line.at(pos) != ' ') {
			letters.push_back(line.at(pos));
		}
	}

	std::sort(letters.begin(), letters.end());

	for(std::vector<char>::iterator it = letters.begin(); it != letters.end(); it++) {
		ss << *it;
	}

	return ss.str();
}

int main(int argc, char *argv[]) {
	std::string input, temp;
	int numInputs, count;
	std::map<std::string, std::string> sortedCharsByString;
	std::vector<std::string> strings;

	count = 0;

	std::cin >> numInputs;
	std::getline(std::cin, input);
	std::getline(std::cin, input);

	while(numInputs > 0) {
		strings.clear();
		sortedCharsByString.clear();
		while(std::getline(std::cin, input)) {
			if(((int)input.length()) == 0) {
				break;
			} else {
				strings.push_back(input);
				sortedCharsByString[input] = sortedChars(input);
			}
		}

		if(count++ > 0) {
			std::cout << std::endl;
		}

		std::unique(strings.begin(), strings.end(), stringCompare);
		std::sort(strings.begin(), strings.end());
		for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
			for(std::vector<std::string>::iterator it1 = (strings.begin() + (it - strings.begin())); it1 != strings.end(); it1++) {
				if((*it).compare(*it1) != 0) {
					if(sortedCharsByString[(*it)].compare(sortedCharsByString[(*it1)]) == 0) {
						std::cout << *it << " = " << *it1 << std::endl;
					}
				}
			}
		}
		numInputs--;
	}

	//std::cin.ignore();
	//std::cin.ignore();
	return 0;
}