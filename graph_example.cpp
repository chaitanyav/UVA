#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


int main(int argc, char *argv[]) {
  typedef std::pair<int, int> EdgeWeight;
  typedef std::vector<EdgeWeight> Neighbor;
  typedef std::vector<Neighbor> AdjList;

  Neighbor neighbors;
  AdjList adjList;
  //0
  neighbors.push_back(std::make_pair(1, 0));
  adjList.push_back(neighbors);

  //1
  neighbors.clear();
  neighbors.push_back(std::make_pair(0, 0));
  neighbors.push_back(std::make_pair(2, 0));
  neighbors.push_back(std::make_pair(3, 0));
  adjList.push_back(neighbors);

  //2
  neighbors.clear();
  neighbors.push_back(std::make_pair(1, 0));
  neighbors.push_back(std::make_pair(3, 0));
  adjList.push_back(neighbors);

  //3
  neighbors.clear();
  neighbors.push_back(std::make_pair(1, 0));
  neighbors.push_back(std::make_pair(2, 0));
  neighbors.push_back(std::make_pair(4, 0));
  adjList.push_back(neighbors);

  //4
  neighbors.clear();
  adjList.push_back(neighbors);

  //5
  neighbors.clear();
  adjList.push_back(neighbors);

  //6
  neighbors.clear();
  neighbors.push_back(std::make_pair(7, 0));
  adjList.push_back(neighbors);

  neighbors.clear();
  neighbors.push_back(std::make_pair(6, 0));
  adjList.push_back(neighbors);

  int node = 0;
  for(AdjList::iterator it = adjList.begin(); it != adjList.end(); it++) {
    for(Neighbor::iterator nit = (*it).begin(); nit != (*it).end(); nit++) {
      std::cout << "edge from node " << node << " to " << (*nit).first << " with weight of " << (*nit).second << std::endl;
    }
    ++node;
  }

  return 0;
}
