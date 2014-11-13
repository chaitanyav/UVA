#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
  typedef std::pair<int, int> Edge;
  typedef std::vector<Edge> Edges;
  Edges edges;
  Edge edge;
  edge = std::make_pair(0, 1);
  edges.push_back(edge);

  std::cout << edge.first << " ---- " << edge.second << std::endl;
  edge = std::make_pair(1, 0);
  edges.push_back(edge);

  std::cout << edge.first << " ---- " << edge.second << std::endl;
  for(Edges::iterator it = edges.begin(); it != edges.end(); it++) {
    std::cout << (*it).first << " --- " << (*it).second << std::endl;
  }

  return 0;
}
