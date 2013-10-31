#include <iostream>

int main(int argc, char *argv[]) {
	int numInputs, treat, i, numTreated, numTreats;
	i = 0;

	while(std::cin >> numInputs, (numInputs != 0)) {				
		numTreats = numInputs;
		numTreated = 0;
		while(numInputs > 0) {
			std::cin >> treat;
			if(treat == 0) {
				numTreated++;
			}
			numInputs--;
		}
	    std::cout << "Case " << ++i << ": " << (numTreats - 2 * numTreated)  << std::endl;
	}
	return 0;
}