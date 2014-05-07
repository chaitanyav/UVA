#include <iostream>
#include <set>
#include <map>
#include <algorithm>

int main(int argc, char *argv[]) {
  int num_test_cases, num_trees = 0, counter = 0;
  std::cin >> num_test_cases;
  char newline = '\n';
  std::string input;
  
  std::set<std::string> trees;
  std::map<std::string, int> count_by_tree;
  std::getline(std::cin, input, newline);
  std::getline(std::cin, input, newline);

  while(num_test_cases > 0) {
    count_by_tree.clear();
    trees.clear();
    num_trees = 0;
    while(std::getline(std::cin, input, newline), input.length() != 0) {
      num_trees++;
      if(count_by_tree.find(input) == count_by_tree.end()) {
        count_by_tree[input] = 1;
        trees.insert(input);
      } else {
        count_by_tree[input] += 1;
      }
    }

    if(counter++ != 0) {
      std::cout << std::endl;
    }

    for(std::set<std::string>::iterator it = trees.begin(); it != trees.end(); it++) {
      std::cout.setf(std::ios::fixed, std::ios::floatfield);
      std::cout.precision(4);
      std::cout << *it << " " << ((float)count_by_tree[*it] / num_trees) * 100 << std::endl;
    }
    num_test_cases--;
  }

  return 0;
}
