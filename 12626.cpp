#include <iostream>
#include <map>
#include <algorithm>
#include <string>

#define len(s) (int)(s.length())

int main(int argc, char *argv[]) {
	std::string input;
	std::map<char, int> countByChar;
	int numInputs, min;
	char c;

	std::cin >> numInputs;
	std::getline(std::cin, input);

	while(numInputs > 0) {
		std::getline(std::cin, input);
		countByChar.clear();

		for(int pos = 0; pos < len(input); pos++) {
			c = input.at(pos);
			if(countByChar.find(c) == countByChar.end()) {
				countByChar[c] = 1;
			} else {
				countByChar[c] += 1;
			}
		}

		input = "MARGIT";
		min = 999999;
		for(int pos = 0; pos < len(input); pos++) {
			c = input.at(pos);
			if(countByChar.find(c) != countByChar.end()) {
				if(c == 'R') {
					if(min > (countByChar[c] / 2)) {
						min = (countByChar[c] / 2);
					}
				} else if(c == 'A') {
					if(min > (countByChar[c] / 3)) {
						min = (countByChar[c] / 3);
					}
				} else {
					if(min > countByChar[c]) {
						min = countByChar[c];
					}
				}
			} else {
				min = 0;
				break;
			}
		}

		std::cout << min << std::endl;
		numInputs--;
	}

	//std::cin.ignore();
	//std::cin.ignore();
	return 0;
}