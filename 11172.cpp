#include <iostream>

int main(int argc, char *argv[]) {
	int numInputs, num1, num2;
	std::cin >> numInputs;
	while(numInputs > 0) {
		std::cin >> num1 >> num2;
		if(num1 == num2) {
			std::cout << "=" << std::endl;
		} else if(num1 > num2) {
			std::cout << ">" << std::endl;
		} else if(num1 < num2) {
			std::cout << "<" << std::endl;
		}
		numInputs--;
	}
	return 0;
}