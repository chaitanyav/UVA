#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
	int numCases, salary, i, j = 1;
	std::vector<int> salaries;
	std::cin >> numCases;
	while(j <= numCases) {
		salaries.clear();
		i = 0;
		while(i < 3) {
			std::cin >> salary;
			salaries.push_back(salary);
			i++;
		}
		
		sort(salaries.begin(), salaries.end());
		std::cout << "Case " << j << ": " << salaries[1] << std::endl;
		j++;
	}
	return 0;
}