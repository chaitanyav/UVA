#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <iomanip>
//1 represents B, F, P, or V
//     2 represents C, G, J, K, Q, S, X,  or Z
//     3 represents D or T
//     4 represents L
//     5 represents M or N
//     6 represents R
// letters A, E, I, O, U, H, W, and Y are not represented


int main(int argc, char *argv[]) {
	int alphabets[26], i, j;
	std::string input, output;
	std::stringstream ss;
	alphabets['A' - 65] = 0;
	alphabets['E' - 65] = 0;
	alphabets['I' - 65] = 0;
	alphabets['O' - 65] = 0;
	alphabets['U' - 65] = 0;
	alphabets['H' - 65] = 0;
	alphabets['W' - 65] = 0;
	alphabets['Y' - 65] = 0;

	alphabets['B' - 65] = 1;
	alphabets['F' - 65] = 1;
	alphabets['P' - 65] = 1;
	alphabets['V' - 65] = 1;

	alphabets['C' - 65] = 2;
	alphabets['G' - 65] = 2;
	alphabets['J' - 65] = 2;
	alphabets['K' - 65] = 2;
	alphabets['Q' - 65] = 2;
	alphabets['S' - 65] = 2;
	alphabets['X' - 65] = 2;
	alphabets['Z' - 65] = 2;

	alphabets['D' - 65] = 3;
	alphabets['T' - 65] = 3;

	alphabets['L' - 65] = 4;
	alphabets['M' - 65] = 5;
	alphabets['N' - 65] = 5;
	alphabets['R' - 65] = 6;

	printf("         NAME                     SOUNDEX CODE\n");
	while(std::getline(std::cin, input)) {	

		for(i = 0; i < (int) input.length(); i++) {
			j = input.at(i) - 65;

			if(i == 0) {
				ss << input.at(i);
			} else if(alphabets[input.at(i) - 65] != alphabets[input.at(i - 1) - 65]){
				if(alphabets[j] > 0) {
					ss << alphabets[j];
					if(ss.str().length() >= 4) {
						break;
					}
				}
			}			
		}

		output = ss.str();
		if(output.length() < 4) {
			output = output.append(std::string(4 - output.length(), '0'));
		}
		printf("         %s", input.c_str());
		for(i = 0; i < (25 - (int)input.length()); i++) {
			printf(" ");
		}
		printf("%s\n", output.c_str());
		ss.clear();
		ss.str("");
	}
	for(i = 0; i < 19; i++) {
		printf(" ");
	}
	printf("END OF OUTPUT\n");
	return 0;
}