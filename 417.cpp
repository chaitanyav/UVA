#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <queue>

#define len(s) (int)(s.length())

int main(int argc, char *argv[]) {
	std::string input;
	std::queue<std::string>words;
	std::map<std::string, int> indexByWord;

	for(char c = 'a'; c <= 'z'; c++){
		words.push(std::string(1, c));
	}

	int counter = 1;

	// generating words in lexigraphical order
	while(!words.empty()) {
		std::string word = words.front();
		words.pop();
		indexByWord[word] = counter++;
		if(len(word)  == 5) continue;
		for(char c = word[len(word) - 1] + 1; c <= 'z'; c++) {
			words.push(word + c);
		}
	}

	while(std::getline(std::cin, input)) {
		if(indexByWord.find(input) != indexByWord.end()) {
			std::cout << indexByWord[input] << std::endl;
		} else {
			std::cout << "0" << std::endl;
		}
	}
	return 0;
}