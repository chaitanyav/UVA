#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

int main(int argc, char *argv[]) {
	int numWords, numJobDescriptions;
	std::map<std::string, long int> salaryByJob;
	std::string job, input, word;
	std::stringstream ss;
	long int salary, total;

	std::cin >> numWords >> numJobDescriptions;
	std::getline(std::cin, input);

	while (numWords > 0) {
		std::getline(std::cin, input);
		ss.clear();
		ss.str("");
		ss << input;
		ss >> job >> salary;
		salaryByJob[job] = salary;
		numWords--;
	}

	while (numJobDescriptions > 0) {
		total = 0;
		while (std::getline(std::cin, input)) {
			if (input.compare(".") != 0) {
				ss.clear();
				ss.str("");
				ss << input;
				while (ss >> word) {
					if (salaryByJob.find(word) != salaryByJob.end()) {
						total += salaryByJob[word];
					}
				}
			}
			else {
				break;
			}

		}
		std::cout << total << std::endl;
		numJobDescriptions--;
	}

	//std::cin.ignore();
	//std::cin.ignore();
	return 0;
}