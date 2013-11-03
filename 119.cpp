#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int main(int argc, char *argv[]) {
	int numPersons, amount, numReceivers, gift, index, i;
	std::vector<std::string> names;
	std::string name, input, giver, receivers;
	std::stringstream ss;
	std::map<std::string, int> amountByName;
	i = 0;
	while(std::cin >> numPersons) {

		while(std::getline(std::cin, input), input.length() == 0){
		}
		ss << input;
		names.clear();
		amountByName.clear();
		while(std::getline(ss, name, ' ')) {
			names.push_back(name);
		}
		ss.clear();
		ss.str("");

		while(numPersons > 0) {
			while(std::getline(std::cin, input), input.length() == 0) {
			}
			ss << input;
			ss >> giver >> amount >> numReceivers;

			if(numReceivers == 0) {
				gift = 0;
			} else {
				gift = (amount / numReceivers);
			}

			if(amountByName.find(giver) != amountByName.end()) {
				amountByName[giver] -= (numReceivers * gift);
			} else {
				amountByName[giver] = -1 * (numReceivers * gift);
			}
			if(numReceivers > 0) {
				while(std::getline(ss, name, ' ')) {
					if(name.length() > 0) {
						if(amountByName.find(name) != amountByName.end()) {
							amountByName[name] += gift;
						} else {
							amountByName[name] = gift;
						}
					}

				}
			}

			ss.clear();
			ss.str("");
			numPersons--;
		}
		if(i != 0) {
			std::cout << std::endl;
			++i;
		} else {
			++i;
		}
		for(index = 0; index < (int) names.size(); index++) {
			std::cout << names[index] << " " << amountByName[names[index]] << std::endl;
		}

	}

	return 0;
}