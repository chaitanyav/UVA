#include <iostream>
#include <vector>
#include <queue>
#include <utility>

typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;

int main(int argc, char *argv[]) {
  int vertices = 100, edges = 100;
  int adjacencyMatrix[100][100];

  //representing a graph by a adjacency matrix
  // can be useful to store small dense graphs
  // vertices <= 1000
  for(int i = 0; i < vertices; ++i) {
    for(int j = 0; j < vertices; ++j) {
      adjacencyMatrix[i][j] = 0;
    }
  }

  std::vector<vii> adjacencyList;
  // ii will contain the other vertex of the edge and weight
  // vii will contain the edge information for a given vertex
  // vector of vii will contain the graph information


  std::priority_queue< std::pair<int, ii> > edgeList;
  return 0;
}
