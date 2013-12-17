#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

// a backtracking algorithm can be used
// to generate permutations in this case
std::string toString(std::vector<char> &letters) {
	std::stringstream ss;
	ss.clear();
	ss.str("");

	for(std::vector<char>::iterator it = letters.begin(); it != letters.end(); it++) {
		ss << *it;
	}

	return ss.str();
}

int main(int argc, char *argv[]) {
	std::string input;
	int numInputs, pos;
	std::vector<char> letters;
	std::cin >> numInputs;
	std::getline(std::cin, input);

	while(numInputs > 0) {
		letters.clear();
		std::getline(std::cin, input);
		for(pos = 0; pos < (int) input.length(); pos++) {
			letters.push_back(input.at(pos));
		}

		std::sort(letters.begin(), letters.end());
		std::cout << toString(letters) << std::endl;
		while(std::next_permutation(letters.begin(), letters.end())) {
			std::cout << toString(letters) << std::endl;
		}
		std::cout << std::endl;
		numInputs--;
	}

	//std::cin.ignore();
	//std::cin.ignore();
	return 0;
}