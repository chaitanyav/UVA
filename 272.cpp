#include <iostream>
#include <cstdio>

int main(int argc, char *argv[]) {
	char in;
	bool flag = false;
	in = getchar();
	while(in != EOF) {
		if(in == '"') {
			if(!flag) {
				std::cout << "``";
				flag = true;
			} else {
				std::cout << "''";
				flag = false;
			}	
		} else {
			std::cout << in;
		}

		in= getchar();
	}
	return 0;
}