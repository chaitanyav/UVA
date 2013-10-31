#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char *argv[]) {
	std::stringstream ss;
	std::string input;
	std::string keyword;
	int amount, total, numInputs;
	total = 0;
	std::cin >> numInputs;

	while(numInputs > 0) {
		std::getline(std::cin, input);

		if(input.length() > 0) {
			ss << input;
			ss >> keyword >> amount;
			
			if(keyword.compare("donate") == 0) {
				total += amount;
			}
			if(keyword.compare("report") == 0) {
				std::cout << total << std::endl;
			}

			ss.clear();
			ss.str("");
			numInputs--;
		}

	}
	return 0;
}