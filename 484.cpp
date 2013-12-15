#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[]) {
	int num;
	std::map<int, int> frequencyByNum;
	std::vector<int> nums;
	while(std::cin >> num) {
		if(frequencyByNum.find(num) == frequencyByNum.end()) {
			frequencyByNum[num] = 1;
			nums.push_back(num);
		} else {
			frequencyByNum[num] = frequencyByNum[num] + 1;
		}
	}

	for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		std::cout << *it << " " << frequencyByNum[*it] << std::endl;
	}

	return 0;
}