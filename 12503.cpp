#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  int numTestCases, numInstructions, instructionIndex, finalPosition;
  std::vector<int> instructions;
  std::string instruction, same, as;
  std::stringstream ss;

  std::cin >> numTestCases;
  while(numTestCases > 0) {
    std::cin >> numInstructions;
    instructions.clear();

    while(numInstructions > 0) {
      std::getline(std::cin, instruction);
      ss << instruction;
      if(instruction.length() > 0) {
        if(instruction.compare("LEFT") == 0) {
          instructions.push_back(-1);
        }
        if(instruction.compare("RIGHT") == 0) {
          instructions.push_back(1);
        }
        if(instruction.at(0) == 'S') {
          ss >> same >> as >> instructionIndex;
          instructions.push_back(instructions[instructionIndex - 1]);
        }
        numInstructions--;
      }
      ss.clear();
      ss.str("");
    }

    finalPosition = 0;
    for(std::vector<int>::iterator it = instructions.begin(); it != instructions.end(); it++) {
      finalPosition += *it;
    }

    std::cout << finalPosition << std::endl;
    numTestCases--;
  }
  return 0;
}
