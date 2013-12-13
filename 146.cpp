#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, char *argv[]) {
    std::string input;    
    std::vector<char> characters;
    while(std::getline(std::cin, input), input.compare("#") != 0) {
        characters.clear();
        for(int i = 0; i < (int) input.length(); i++) {
            characters.push_back(input.at(i));            
        }
        
        bool flag = false;
        while(std::next_permutation(characters.begin(), characters.end())) {
            flag = true;
            for(std::vector<char>::iterator it = characters.begin(); it != characters.end(); it++) {
                std::cout << *it;
            }
            std::cout << std::endl;
            break;
        }
        if(!flag){
            std::cout << "No Successor" << std::endl;
        }
    }        
    return 0;
}
