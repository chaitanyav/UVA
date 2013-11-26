#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <sstream>

int main(int argc, char *argv[]) {
	std::string input, output;
	std::vector<char> letters1, letters2;
	std::stringstream ss;
	int i, counter, distance, maxDistance, absDistance;

	while(std::getline(std::cin, input)) {
		letters1.clear();
		letters2.clear();
		output = "";

		counter = 0;
		maxDistance = -1;


		for(i = 0; i < (int) input.length(); i++) {
			letters1.push_back(input.at(i));
			letters2.push_back(input.at(i));
		}

		// previous permutation		
		while(std::prev_permutation(letters1.begin(), letters1.end())) {
			distance = 27;
			ss.clear();
			ss.str("");

			for(std::vector<char>::iterator it = letters1.begin(); it != letters1.end(); it++) {
				if((it + 1) != letters1.end()) {
					absDistance = abs(*(it) - *(it + 1)); 
					if(absDistance < distance) {
						distance = absDistance;
					}						
				}
				ss << *it;
			}
			//std::cout << ss.str() << distance << std::endl;
			if(distance >= maxDistance) {
				output = ss.str();
				maxDistance = distance;
			}
			++counter;
			if(counter == 10) {
				break;
			}
		}

		//next permutation		
		 do{
			distance = 27;
			ss.clear();
			ss.str("");

			for(std::vector<char>::iterator it = letters2.begin(); it != letters2.end(); it++) {
				if((it + 1) != letters2.end()) {
					absDistance = abs(*(it) - *(it + 1)); 
					if(absDistance < distance) {
						distance = absDistance;
					}						
				}
				ss << *it;

			}
			//std::cout << ss.str() << distance << std::endl;
			if(distance > maxDistance) {
				output = ss.str();
				maxDistance = distance;
			}
			++counter;
			if(counter == 22) {
				break;
			}
		}while(std::next_permutation(letters2.begin(), letters2.end()));

		 if(maxDistance == 27) {
			 maxDistance = 0;
		 }
		std::cout << output << maxDistance << std::endl;
	}

	return 0;
}