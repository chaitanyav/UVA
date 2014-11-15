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

void floodFill3(int i, int j, int color);
void floodFill(int i, int j, int color);
typedef std::pair<int, int> VertexWeight;
typedef std::vector<VertexWeight> Neighbors;
typedef std::vector<Neighbors> AdjList;
std::vector<std::vector<bool> > visited;
std::vector<int> areas;
int area = 0;

Neighbors neighbors;
AdjList adjList;

void floodFill3(int i, int j, int color) {
  if((i < 0) || (j < 0) || (i > (int) adjList.size()) || (j > (int) (adjList[i]).size()) || ((visited[i])[j]) || (color != 3)) {
      if((color == 2) && !((visited[i])[j])) {
        //std::cout << "Calling flood fill " << i << " , " << j << std::endl;
        floodFill(i, j, 2);
      } else {
        return;
      }
  }

  ((visited[i])[j]) = true;
  if(((i - 1) >= 0) && (j >= 0) && ((i - 1) < (int) adjList.size()) && (j < (int) (adjList[i]).size())) {
    floodFill3(i - 1, j, ((adjList[i - 1])[j]).second);
  }

  if(((i + 1) >= 0) && (j >= 0) && ((i + 1) < (int) adjList.size()) && (j < (int) (adjList[i]).size())) {
    floodFill3(i + 1, j, ((adjList[i + 1])[j]).second);
  }

  if((i >= 0) && ((j - 1) >= 0) && (i < (int) adjList.size()) && ((j - 1) < (int) (adjList[i]).size())) {
    floodFill3(i, j - 1, ((adjList[i])[j - 1]).second);
  }

  if((i >= 0) && ((j + 1) >= 0) && (i < (int) adjList.size()) && ((j + 1) < (int) (adjList[i]).size())) {
    floodFill3(i, j + 1, ((adjList[i])[j + 1]).second);
  }
}

void floodFill(int i, int j, int color) {
  if((i < 0) || (j < 0) || (i > (int) adjList.size()) || (j > (int) (adjList[i]).size()) || ((visited[i])[j]) || (color != 2)) {
    if(color == 3 && !((visited[i])[j])) {
      area++;
      //std::cout << "calling flood fillx " << i << " , " << j << std::endl;
      floodFill3(i, j, 3);
    } else {
      return;
    }
  }

  ((visited[i])[j]) = true;
  if(((i - 1) >= 0) && (j >= 0) && ((i - 1) < (int) adjList.size()) && (j < (int) (adjList[i]).size())) {
    floodFill(i - 1, j, ((adjList[i - 1])[j]).second);
  }

  if(((i + 1) >= 0) && (j >= 0) && ((i + 1) < (int) adjList.size()) && (j < (int) (adjList[i]).size())) {
    floodFill(i + 1, j, ((adjList[i + 1])[j]).second);
  }

  if((i >= 0) && ((j - 1) >= 0) && (i < (int) adjList.size()) && ((j - 1) < (int) (adjList[i]).size())) {
    floodFill(i, j - 1, ((adjList[i])[j - 1]).second);
  }

  if((i >= 0) && ((j + 1) >= 0) && (i < (int) adjList.size()) && ((j + 1) < (int) (adjList[i]).size())) {
    floodFill(i, j + 1, ((adjList[i])[j + 1]).second);
  }
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
            if((visited[i])[j] == false && ((adjList[i])[j]).second != 1) {
              area = 0;
              floodFill(i, j, ((adjList[i])[j]).second);
              if(area)
              areas.push_back(area);
            }
          }
        }

        std::cout << "Throw " << ++attempt << std::endl;
        std::sort(areas.begin(), areas.end());
        int numAreas = (int)areas.size() - 1;
        for(std::vector<int>::iterator it = areas.begin(); it != areas.end(); ++it) {
          std::cout << *it;
          if(numAreas--) {
            std::cout << " ";
          }
        }
        std::cout << std::endl;
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
