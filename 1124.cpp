#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

	std::string input;
	while(std::getline(std::cin, input)) {
		std:: cout << input << std::endl;
	}
	return 0;
}