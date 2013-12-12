#include <iostream>
#include <string>
#include <set>
#include <algorithm>

void combinations(std::string s, int length, std::set<std::string> &found, std::string chosen = "") {
  if(length == 0 && (found.find(chosen) == found.end())) {
    std::cout << chosen << std::endl;
    found.insert(chosen);
  } else {
    for(int i = 0; i < (int) s.length(); i++) {
      char c = s[i];
      if(chosen.find(c) == std::string::npos) {
        s.erase(i, 1);
        combinations(s, length - 1, found, chosen + c);
        s.insert(i, 1, c);

      }
    }
  }
}

int main(int argc, char *argv[]) {
  std::set<std::string> found;
  combinations("PARTY", 3, found);
  return 0;
}
