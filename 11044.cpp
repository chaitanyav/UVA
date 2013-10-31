#include <iostream>

int main(int argc, char *argv[]) {
	int numInputs;
	int n, m;
	std::cin >> numInputs;
	while(numInputs > 0) {
		std::cin >> n >> m;
		std::cout << (n / 3) * (m / 3) << std::endl;
		numInputs--;
	}
	return 0;
}