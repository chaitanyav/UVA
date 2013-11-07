#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
	int numTestCases,numDays, numParties, parameter, day, party, totalHartals;
	std::vector<int> hartalParameterByParty, hartalsByDay;
	std::cin >> numTestCases;

	while(numTestCases > 0) {
		hartalParameterByParty.clear();
		hartalsByDay.clear();
		std::cin >> numDays;
		std::cin >> numParties;

		while(numParties > 0) {
			std::cin >> parameter;
			hartalParameterByParty.push_back(parameter);
			numParties--;
		}

		totalHartals = 0;
		for(day = 0; day < numDays; day++) {
			hartalsByDay.push_back(0);
			if(((day % 7) != 5) && ((day % 7) != 6)) {
				//std::cout<< "day " << day << std::endl;
				for(party = 0; party < (int) hartalParameterByParty.size(); party++) {
					if((((day + 1) % (hartalParameterByParty[party])) == 0)) {						
						//std::cout << "party " << party << " parameter" << (hartalParameterByParty[party] - 1) << std::endl;
						if(hartalsByDay[day] == 0) {
							hartalsByDay[day]++;
							totalHartals++;
						}
					}
				}
			}
		}
		std::cout << totalHartals << std::endl;
		numTestCases--;
	}
	return 0;
}