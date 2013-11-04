#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

std::map<std::string, std::string> titleByAuthor;


bool compareBooks(std::string author1, std::string author2) {
  int result;
  result = author1.compare(author2);
  if(result < 0) {
    return true;
  } else if(result > 0) {
    return false;
  } else if(result == 0) {
    std::string title1, title2;
    title1 = titleByAuthor[author1];
    title2 = titleByAuthor[author2];
    result = title1.compare(title2);
    if(result < 0) {
      return true;
    } else if(result > 0) {
      return false;
    }
  }
}

int main(int argc, char *argv[]) {
  std::string title, input, command, author;
  int index;
  std::vector<std::string> titles;
  std::vector<std::string> authors;
  std::vector<std::string>::iterator it;
  std::map<std::string, bool> isBorrowedByTitle;
  std::map<std::string, std::string> authorByTitle;
  unsigned int pos;

  while(std::getline(std::cin, input), input.compare("END") != 0) {
    pos = input.find_last_of("\"");
    title = input.substr(0, pos + 1);
    author = input.substr(pos + 5, input.length() - 1);
    titles.push_back(title);
    authors.push_back(author);
    titleByAuthor[author] = title;
    authorByTitle[title] = author;
    isBorrowedByTitle[title] = false;
  }

  while(std::getline(std::cin, input), input.compare("END") != 0) {
    if(input.compare("SHELVE") != 0) {
      pos = input.find_first_of("\"");
      title = input.substr(pos, input.length() - 1);
      command = input.substr(0, pos - 1);
      if(command.compare("BORROW") == 0) {
        isBorrowedByTitle[title] = true;
        if((it = std::find(authors.begin(), authors.end(), authorByTitle[title])) != authors.end()) {
          authors.erase(it);
        }
      }

      if(command.compare("RETURN") == 0){
        isBorrowedByTitle[title] = false;
        authors.push_back(authorByTitle[title]);
      }
    } else {
      std::sort(authors.begin(), authors.end(), compareBooks);
      if(authors.size() == 1) {
        std::cout << "Put " << titleByAuthor[authors[0]] << " first" << std::endl;
        std::cout << "END" << std::endl;
      } if(authors.size() >= 2) {
        for(index = 0; index < ((int)authors.size()) - 1; index++) {
          std::cout << "Put " << titleByAuthor[authors[index + 1]] << " after " << titleByAuthor[authors[index]] << std::endl;
        }
        std::cout << "END" << std::endl;
      }

    }
  }


  return 0;
}
