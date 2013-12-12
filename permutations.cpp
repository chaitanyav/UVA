#include <iostream>
#include <string>

void permute(std::string s, std::string chosen = "") {
  if(s == "") {
    std::cout << chosen << std::endl;
    } else {
    for(int i = 0; i < (int) s.length(); i++) {
      char c = s[i];
      s.erase(i, 1);
      permute(s, chosen + c);
      s.insert(i, 1, c);
    }
  }
}

int main(int argc, char *argv[]) {
  permute("MARTY");
  return 0;
}
