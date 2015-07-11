#include <iostream>
#include <map>
#include <string>

int main(int argc, char*argv[]) {
  int numTestCases, numSubjects, days, dueDays;
  std::string subject;
  std::map<std::string, int> daysBySubject;
  std::map<std::string, int>::iterator it;
  std::cin >> numTestCases;
  for(int i = 0; i < numTestCases; i++) {
    std::cin >> numSubjects;
    daysBySubject.clear();

    for(int j = 0; j < numSubjects; j++) {
      std::cin >> subject >> days;
      daysBySubject[subject] = days;
    }
      std::cin >> dueDays;
      std::cin >> subject;

      std::cout << "Case " << i + 1 << ": ";
      it = daysBySubject.find(subject);
      if(it != daysBySubject.end()) {
        days = daysBySubject[subject];
        if(days <= dueDays) {
          std::cout << "Yesss" << std::endl;
        } else if(days <= dueDays + 5) {
          std::cout << "Late" << std::endl;
        } else {
          std::cout << "Do your own homework!" << std::endl;
        }
      } else {
        std::cout << "Do your own homework!" << std::endl;
      }
  }
  return 0;
}
