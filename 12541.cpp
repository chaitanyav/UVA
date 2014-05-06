#include <iostream>
#include <vector>
#include <algorithm>

typedef struct Person {
 int month;
 int date;
 int year;
 std::string name;
}Person;

bool custom_compare(const Person& person1, const Person& person2) {
  bool result = false;
  if(person1.year < person2.year) {
    result = true;
  } else if(person1.year == person2.year) {
    if(person1.month < person2.month) {
      result = true;
    } else if(person1.month == person2.month) {
      if(person1.date < person2.date) {
        result = true;
      } else {
        result = false;
      }
    }
  }

  return result;
}

int main(int argc, char *argv[]) {
  int num_inputs, n, date, month, year;
  std::vector<Person> persons;
  std::cin >> num_inputs;
  n = num_inputs;

  std::string name, youngest, oldest;

  while(n > 0) {
    std::cin >> name >> date >> month >> year;
    Person person;
    person.name = name;
    person.date = date;
    person.month = month;
    person.year = year;
    persons.push_back(person);
    n--;
  }

  std::sort(persons.begin(), persons.end(), custom_compare);
  int num_persons = (int) persons.size();
  std::cout << persons[num_persons - 1].name << std::endl << persons[0].name << std::endl;

  return 0;
}
