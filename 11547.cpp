#include <iostream>

int main(int argc, char *argv[]) {
	int numInputs, n;
	std::cin >> numInputs;

	while(numInputs > 0) {
		std::cin >> n;
		n = ((((((((n * 567) / 9) + 7492) * 235) / 47) - 498) / 10) % 10);
		std::cout << (n > 0 ? n : -1 * n) << std::endl;
		numInputs--;
	}
	return 0;
}