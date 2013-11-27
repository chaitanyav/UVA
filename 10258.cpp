#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

typedef struct scoreCard {
	int contestant;
	int problems;
	int time;
	int numIncorrectAttempts[10];
	bool solved[10];
	bool exists;
}scoreCard;

bool scoreCompare(scoreCard a, scoreCard b) {
	if(a.problems == b.problems) {
		if(a.time == b.time) {
			return (a.contestant < b.contestant);
		} else {
			return (a.time < b.time);
		}
	} else {
		return (a.problems > b.problems);
	}
}

int main(int argc, char *argv[]) {
	int numInputs, contestant, problem, time, i, count;
	std::string input;
	std::stringstream ss;
	char l;

	count = 0;
	std::cin >> numInputs;
	std::getline(std::cin, input);
	std::getline(std::cin, input);

	while(numInputs > 0) {
		scoreCard sc;
		sc.exists = false;
		std::vector<scoreCard> scoreBoard(101, sc);
		while(std::getline(std::cin, input)) {
			if(input.size() == 0) {
				break;
			} else {
				ss.clear();
				ss.str("");
				ss << input;
				ss >> contestant >> problem >> time >> l;
				if(scoreBoard[contestant].exists == false) {
					scoreBoard[contestant].contestant = contestant;
					scoreBoard[contestant].exists = true;
					scoreBoard[contestant].time = 0;
					scoreBoard[contestant].problems = 0;					
					for(i = 0; i < 10; i++) {
						scoreBoard[contestant].numIncorrectAttempts[i] = 0;
						scoreBoard[contestant].solved[i] = false;
					}
				}
				if(l == 'C') {
					if(scoreBoard[contestant].solved[problem] == false) {
						scoreBoard[contestant].problems++;
						scoreBoard[contestant].time += (time + (20 * scoreBoard[contestant].numIncorrectAttempts[problem]));
						scoreBoard[contestant].solved[problem] = true;
					}
				}
				if(l == 'I') {
					scoreBoard[contestant].numIncorrectAttempts[problem]++;;
				}
			}
		}

		std::sort(scoreBoard.begin(), scoreBoard.end(), scoreCompare);
		if(count++ > 0) {
			std::cout << std::endl;
		}

		for(std::vector<scoreCard>::iterator it = scoreBoard.begin(); it != scoreBoard.end(); it++) {
			if(it->exists) {
				std::cout << it->contestant << " " << it->problems << " " << it->time << std::endl;
			}			
		}


		numInputs--;
	}

	//std::cin.ignore();
	//std::cin.ignore();
	return 0;
}