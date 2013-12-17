#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <vector>


int main(int argc, char *argv[]){
  int numInputs;
  std::string input, first, second;
  std::map<std::string, std::string> childByParent;
  std::map<std::string, std::string> characteristicByPerson;
  std::map<std::string, std::vector<std::string> > parentByChild;
  std::stringstream ss;
  std::set<std::string> persons;

  std::cin >> numInputs;
  std::getline(std::cin, input);

  while(numInputs > 0) {
    std::getline(std::cin, input);
    ss.clear();
    ss.str("");
    ss << input;
    ss >> first >> second;

    persons.insert(first);

    if((second.compare("dominant") == 0) || (second.compare("recessive") == 0) || (second.compare("non-existent") == 0)){
      characteristicByPerson[first] = second;
    } else {
      childByParent[first] = second;
      persons.insert(second);
      parentByChild[second].push_back(first);

      if(((int)parentByChild[second].size() == 2) && (characteristicByPerson.find(second) == characteristicByPerson.end())) {
        std::vector<std::string> parents = (parentByChild[second]);
        if(((characteristicByPerson[parents[0]].compare("non-existent") != 0) && (characteristicByPerson[parents[1]].compare("non-existent") != 0)) || ((characteristicByPerson[parents[0]].compare("dominant") == 0) || (characteristicByPerson[parents[1]].compare("dominant") == 0))) {

          if(((characteristicByPerson[parents[0]].compare("dominant") == 0) && (characteristicByPerson[parents[1]].compare("dominant") == 0)) || ((characteristicByPerson[parents[0]].compare("dominant") == 0) && (characteristicByPerson[parents[1]].compare("recessive") == 0)) || ((characteristicByPerson[parents[0]].compare("recessive") == 0) && (characteristicByPerson[parents[1]].compare("dominant") == 0))) {
            characteristicByPerson[second] = "dominant";
          } else {
            characteristicByPerson[second] = "recessive";
          }
        } else {
          characteristicByPerson[second] = "non-existent";
        }
      }
    }
    numInputs--;
  }

  for(std::set<std::string>::iterator it = persons.begin(); it != persons.end(); it++) {
    std::cout << *it << " " << characteristicByPerson[*it] << std::endl;
  }


  return 0;
}
