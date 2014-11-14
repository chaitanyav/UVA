#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>

typedef std::pair<int, int> EdgeWeight;
typedef std::vector<EdgeWeight> Neighbors;
typedef std::vector<Neighbors> AdjList;

static AdjList adjList;
static Neighbors neighbors;
static std::vector<std::vector<bool> > visited;
static int area = 0;

void floodFill(int i, int j, int color) {
  if((i < 0) || (j < 0) || (i > (int) adjList.size()) || (j > (int) adjList.size()) || ((visited[i])[j]) || (color != 2)) {
    return;
  }

  ((visited[i])[j]) = true;
  area++;
  if(((i - 1) >= 0) && (j >= 0) && ((i - 1) < (int) adjList.size()) && (j < (int) adjList.size())) {
      floodFill(i - 1, j, ((adjList[i - 1])[j]).second);
  }

  if(((i + 1) >= 0) && (j >= 0) && ((i + 1) < (int) adjList.size()) && (j < (int) adjList.size())) {
    floodFill(i + 1, j, ((adjList[i + 1])[j]).second);
  }

  if((i >= 0) && ((j - 1) >= 0) && (i < (int) adjList.size()) && ((j - 1) < (int) adjList.size())) {
    floodFill(i, j - 1, ((adjList[i])[j - 1]).second);
  }

  if((i >= 0) && ((j + 1) >= 0) && (i < (int) adjList.size()) && ((j + 1) < (int) adjList.size())) {
    floodFill(i, j + 1, ((adjList[i])[j + 1]).second);
  }

  if(((i - 1) >= 0) && ((j - 1) >= 0) && ((i - 1) < (int) adjList.size()) && ((j - 1) < (int) adjList.size())) {
    floodFill(i - 1, j - 1, ((adjList[i - 1])[j - 1]).second);
  }

  if(((i - 1) >= 0) && ((j + 1) >= 0) && ((i - 1) < (int) adjList.size()) && ((j + 1) < (int) adjList.size())) {
    floodFill(i - 1, j + 1, ((adjList[i - 1])[j + 1]).second);
  }

  if(((i + 1) >= 0) && ((j - 1) >= 0) && ((i + 1) < (int) adjList.size()) && ((j - 1) < (int) adjList.size())) {
    floodFill(i + 1, j - 1, ((adjList[i + 1])[j - 1]).second);
  }

  if(((i + 1) >= 0) && ((j + 1) >= 0) && ((i + 1) < (int) adjList.size()) && ((j + 1) < (int) adjList.size())) {
    floodFill(i + 1, j + 1, ((adjList[i + 1])[j + 1]).second);
  }
}

int main(int argc, char *argv[]) {

  int numTestCases;
  std::cin >> numTestCases;
  std::string blankline;
  std::getline(std::cin, blankline);
  std::getline(std::cin, blankline);

  std::string input;
  while(std::getline(std::cin, input)) {
    if(input.length() > 0) {
      if(input.at(0) == 'L' || input.at(0) == 'W') {
        for(int i = 0; i < (int) input.length(); i++) {
          EdgeWeight edgeWeight;
          edgeWeight.first  = i;
          if(input.at(i) == 'L') {
            edgeWeight.second = 1;
          } else {
            edgeWeight.second = 2;
          }
          neighbors.push_back(edgeWeight);
        }
        adjList.push_back(neighbors);
        neighbors.clear();
      } else {
        std::stringstream sbuf;
        sbuf << input;
        int i, j;
        sbuf >> i >> j;
        visited.clear();
        for(int row = 0; row < (int) adjList.size(); row++) {
          std::vector<bool> temp(adjList.size(), false);
          visited.push_back(temp);
        }
        floodFill(i - 1, j - 1, 2);
        std::cout << area << std::endl;
        area = 0;
      }
    } else {
      neighbors.clear();
      adjList.clear();

      numTestCases--;
      if(!numTestCases) {
        break;
      }
      else {
        std::cout << std::endl;
      }

    }
  }
  return 0;
}
