#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
	int numInputs, numStores, store, minDist;
	std::vector<int> stores;
	std::cin >> numInputs;
	while(numInputs > 0) {
		minDist = 0;
		stores.clear();
		std::cin >> numStores;
		while(numStores > 0) {
			std::cin >> store;
			stores.push_back(store);
			numStores--;
		}

		std::sort(stores.begin(), stores.end());
		minDist = stores[stores.size() - 1] - stores[0];
		std::cout << 2 * minDist << std::endl;
		numInputs--;
	}
	return 0;
}