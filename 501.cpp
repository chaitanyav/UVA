#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>

int main(int argc, char *argv[]) {
  std::string input;
  int number, num_elements, num_gets, new_line_counter = 0;
  std::multiset<int> elements;
  std::vector<int> orig_elements;
  std::vector<int> get_sequence;

  int num_datasets;
  std::cin >> num_datasets;

  while(num_datasets > 0) {
    std::getline(std::cin, input);
    elements.clear();
    orig_elements.clear();
    get_sequence.clear();

    std::cin >> num_elements >> num_gets;
    while(num_elements > 0) {
      std::cin >> number;
      orig_elements.push_back(number);
      num_elements--;
    }

    while(num_gets > 0) {
      std::cin >> number;
      get_sequence.push_back(number);
      num_gets--;
    }

    if(new_line_counter++ != 0) {
      std::cout << std::endl;
    }

    int index = 0;
    for(std::vector<int>::iterator it = orig_elements.begin(); it != orig_elements.end(); it++) {
       elements.insert(*it);
       while(!get_sequence.empty() && (get_sequence[0] == elements.size())) {
          get_sequence.erase(get_sequence.begin());

          int msindex = 0;
          for(std::multiset<int>::iterator msit = elements.begin(); msit != elements.end(); msit++, msindex++) {
            if(msindex == index) {
              std::cout << *msit << std::endl;
              index++;
              break;
            }
          }
       }
    }

    num_datasets--;
  }
  return 0;
}
