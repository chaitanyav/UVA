#include <iostream>
#include <map>
#include <algorithm>

int main(int argc, char *argv[]) {
	long int i, j, n, cycleLength, maxCycleLength, originalI, originalJ;
	std::map<long int, long int> cycleLengthByNumber;

	while (std::cin >> i >> j) {
		maxCycleLength = 0;
		originalI = i;
		originalJ = j;
		if (i > j) {
			std::swap(i, j);
		}

		while (j >= i) {
			n = j;
			cycleLength = 0;

			if (cycleLengthByNumber.find(j) == cycleLengthByNumber.end()) {
				while (n > 0) {
					if (n == 1) {
						cycleLength++;
						break;
					}
					else {
						if (cycleLengthByNumber.find(n) == cycleLengthByNumber.end()) {
							if (n % 2 != 0) {
								n = (3 * n) + 1;
							}
							else {
								n /= 2;
							}
							cycleLength++;
						}
						else {
							cycleLength += cycleLengthByNumber[n];
							break;
						}						
					}

					//std::cout << n << std::endl;
				}
				cycleLengthByNumber[j] = cycleLength;
			}
			else {
				cycleLength = cycleLengthByNumber[j];
			}
			if (cycleLength > maxCycleLength) {
				maxCycleLength = cycleLength;
			}
			j--;
		}

		std::cout << originalI << " " << originalJ << " " << maxCycleLength << std::endl;
	}
	return 0;
}