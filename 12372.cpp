#include <iostream>

int main(int argc, char *argv[]) {
	int numTestCases, length, width, height, i;
	i = 0;
	std::cin >> numTestCases;

	while(numTestCases > 0) {
		std::cin >> length >> width >> height;
		std::cout << "Case " << ++i << ": ";
		if((length <= 20) && (width <= 20) && (height <= 20)) {
			std::cout << "good" << std::endl;
		} else {
			std::cout << "bad" << std::endl;
		}
		numTestCases--;
	}
	return 0;
}