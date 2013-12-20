#include <iostream>
#include <set>

int main(int argc, char *argv[]) {
  std::multiset<int> numbers;
  numbers.insert(10);
  numbers.insert(10);
  numbers.insert(10);
  std::multiset<int>::iterator it = numbers.find(10);
  numbers.erase(it);
  std::cout << numbers.count(10) << std::endl;
  return 0;
}
