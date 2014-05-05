#include <iostream>
#include <climits>

int main(int argc, char *argv[]) {
  int num_inputs, n, date, month, year, youngest_age = INT_MAX, oldest_age = INT_MIN, age;
  std::cin >> num_inputs;
  n = num_inputs;

  std::string name, youngest, oldest;

  while(n > 0) {
    std::cin >> name >> date >> month >> year;
    age = date + month * 100 + year * 10000;
    std::cout << age << " " << youngest_age << " " << oldest_age << std::endl;
    if(age < youngest_age) {
      youngest_age = age;
      youngest = name;
    }
    if(age > oldest_age) {
      oldest_age = age;
      oldest = name;
    }
    n--;
  }

  std::cout << oldest << std::endl << youngest << std::endl;
  return 0;
}
