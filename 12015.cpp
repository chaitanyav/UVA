#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

int main(int argc, char *argv[]) {
  int numTestCases, relevance, maxRelevance, n, kase;
  std::stringstream ss;
  std::string input, site;
  std::map<std::string, int> relevanceBySite;
  std::vector<std::string> sites;
  std::cin >> numTestCases;

  maxRelevance = 0;
  kase = 0;

  std::getline(std::cin, input);

  while(numTestCases > 0) {
    maxRelevance = 0;
    sites.clear();
    relevanceBySite.clear();
    for(n = 0; n < 10; n++) {
      std::getline(std::cin, input);
      ss << input;
      ss >> site >> relevance;
      sites.push_back(site);
      ss.clear();
      ss.str("");

      if(relevance > maxRelevance) {
        maxRelevance = relevance;
      }
      relevanceBySite[site] = relevance;
    }

    std::cout << "Case #" << ++kase << ":" << std::endl;
    for(std::vector<std::string>::iterator it = sites.begin(); it != sites.end(); it++) {
      if(relevanceBySite[*it] == maxRelevance) {
        std::cout << *it << std::endl;
      }
    }

    numTestCases--;
  }
  return 0;
}
