#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>


bool customCompare(char a, char b) {
	if(tolower(a) == tolower(b)) {
		return (a < b);
	} else {
		return (tolower(a) < tolower(b));
	}
}

void printLetters(std::vector<char> &letters) {
	std::stringstream ss;
	ss.clear();
	ss.str("");
	for(std::vector<char>::iterator it = letters.begin(); it != letters.end(); it++) {
		ss << *it;
	}
	std::cout << ss.str() << std::endl;;
}

int main(int argc, char *argv[]) {
	std::string word;
	int numWords, pos;
	std::vector<char> letters;

	std::cin >> numWords;
	std::getline(std::cin, word);

	while(numWords > 0) {
		std::getline(std::cin, word);
		letters.clear();
		for(pos = 0; pos < (int) word.length(); pos++) {
			letters.push_back(word.at(pos));
		}

		std::sort(letters.begin(), letters.end(), customCompare);
		printLetters(letters);
		while(std::next_permutation(letters.begin(), letters.end(), customCompare)) {
			printLetters(letters);
		}
		numWords--;
	}

	//std::cin.ignore();
	//std::cin.ignore();
	return 0;
}