#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::string input;
	int i = 0;
	while(std::getline(std::cin, input), input.compare("#") != 0) {
		++i;
		std::cout << "Case " << i << ": ";
		if(input.compare("HELLO") == 0) {
			std::cout << "ENGLISH" << std::endl;
		} else if(input.compare("HOLA") == 0) {
			std::cout << "SPANISH" << std::endl;
		} else if(input.compare("HALLO") == 0) {
			std::cout << "GERMAN" << std::endl;
		} else if(input.compare("BONJOUR") == 0) {
			std::cout << "FRENCH" << std::endl;
		} else if(input.compare("CIAO") == 0) {
			std::cout << "ITALIAN" << std::endl;
		} else if(input.compare("ZDRAVSTVUJTE") == 0) {
			std::cout << "RUSSIAN" << std::endl;
		} else {
			std::cout << "UNKNOWN" << std::endl;
		}
	}
	return 0;
}