#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	int numInputs, i, flag1, flag2;
	std::string input;
	std::cin >> numInputs;
	char one[] = "one";
	char two[] = "two";

	while((numInputs > 0)) {		
		std::getline(std::cin, input);
		if(input.length() == 5) {
			std::cout << 3 << std::endl;
		}
		if(input.length() == 3)
		{
			flag1 = 0;
			flag2 = 0;
			for(i = 0; i < (int)input.length(); i++) {
				if(one[i] != input.at(i)) {
					flag1++;
				}
				if(two[i] != input.at(i)) {
					flag2++;
				}
			}

			if((flag1 == 1) || (flag1 == 0)) {
				std::cout << 1 << std::endl;
			}
			if((flag2 == 1) || (flag2 == 0)) {
				std::cout << 2 << std::endl;
			}
		}

		if(input.length() > 0) {
			numInputs--;
		}
		
	}
	return 0;
}