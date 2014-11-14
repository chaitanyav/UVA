#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <sstream>

// 1 --- .
// 2 --- *
// 3 --- X

typedef std::pair<int, int> VertexWeight;
typedef std::vector<VertexWeight> Neighbors;
typedef std::vector<Neighbors> AdjList;
std::vector<std::vector<bool> > visited;
std::set<int> areas;

Neighbors neighbors;
AdjList adjList;

int floodFill(int i, int j, int color) {
  int area = 0;
  if((i < 0) || (j < 0) || (i > (int) adjList.size()) || (j > (int) (adjList[i]).size()) || ((visited[i])[j]) || (color != 3)) {
    return 0;
  }

  ((visited[i])[j]) = true;
  area = 1;
  std::cout << i << " , " << j << std::endl;
  if(((i - 1) >= 0) && (j >= 0) && ((i - 1) < (int) adjList.size()) && (j < (int) (adjList[i]).size())) {
    area += floodFill(i - 1, j, ((adjList[i - 1])[j]).second);
  }

  if(((i + 1) >= 0) && (j >= 0) && ((i + 1) < (int) adjList.size()) && (j < (int) (adjList[i]).size())) {
    area += floodFill(i + 1, j, ((adjList[i + 1])[j]).second);
  }

  if((i >= 0) && ((j - 1) >= 0) && (i < (int) adjList.size()) && ((j - 1) < (int) (adjList[i]).size())) {
    area += floodFill(i, j - 1, ((adjList[i])[j - 1]).second);
  }

  if((i >= 0) && ((j + 1) >= 0) && (i < (int) adjList.size()) && ((j + 1) < (int) (adjList[i]).size())) {
    area += floodFill(i, j + 1, ((adjList[i])[j + 1]).second);
  }

  return area;
}


int main(int argc, char *argv[]) {


  std::string input;
  int width;
  int height;
  int row = 0;
  int attempt = 0;

  while(std::getline(std::cin, input)) {
    char c = input.at(0);
    if(c == '.' || c == 'X' || c == '*') {
      ++row;
      neighbors.clear();
      for(int pos = 0; pos < (int) input.length(); ++pos) {
        VertexWeight vertexWeight;
        vertexWeight.first = pos;
        char temp = input.at(pos);
        if(temp == '.') {
            vertexWeight.second = 1;
        } else if(temp == '*') {
          vertexWeight.second = 2;
        } else {
          vertexWeight.second = 3;
        }
        neighbors.push_back(vertexWeight);
      }
      adjList.push_back(neighbors);
      if(height == row) {
        visited.clear();
        for(int index = 0; index < height; ++index) {
          visited.push_back(std::vector<bool>(width, false));
        }
        for(int i = 0; i < height; ++i) {
          for(int j = 0; j < width; ++j) {
            if((visited[i])[j] == false) {
              int area = floodFill(i, j, ((adjList[i])[j]).second);
              if(((adjList[i])[j]).second == 3) {
                areas.insert(area);
              }
            }
          }
        }

        std::cout << "Throw " << ++attempt << std::endl;
        int numAreas = (int)areas.size() - 1;
        for(std::set<int>::iterator it = areas.begin(); it != areas.end(); ++it) {
          std::cout << *it;
          if(numAreas--) {
            std::cout << " ";
          }
        }
        std::cout << std::endl;
      }
    } else {
      row = 0;

      std::stringstream sbuf;
      sbuf << input;
      sbuf >> width >> height;

      adjList.clear();
      areas.clear();

      if(width == 0 && height == 0) {
        break;
      }
    }
  }
  return 0;
}
