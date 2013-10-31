#include <iostream>

int main(int argc, char *argv[]) {
	int numQueries, divX, divY, resX, resY;
	while(std::cin >> numQueries, (numQueries != 0)) {
		std::cin >> divX >> divY;
		while(numQueries > 0) {
			std::cin >> resX >> resY;
			if((resX == divX) || (resY == divY)) {
				std::cout << "divisa" << std::endl;
			}
			if(resX < divX) {
				if(resY < divY) {
					std::cout << "SO" << std::endl;
				}
				if(resY > divY) {
					std::cout << "NO" << std::endl;
				}
			}
			if(resX > divX) {
				if(resY < divY) {
					std::cout << "SE" << std::endl;
				}
				if(resY > divY) {
					std::cout << "NE" << std::endl;
				}
			}
			numQueries--;
		}
	}
	return 0;
}
