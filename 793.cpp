#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

typedef std::vector<int> vi;

class UnionFind {
  private:
    vi parent, setSize, rank;
    int numSets;
  public:
    UnionFind( int N);
    virtual ~UnionFind();
    int findSet(int i);
    bool isSameSet(int i, int j);
    void unionSet( int i, int j);
    int numDisjointSets();
    int sizeOfSet(int i);
};

UnionFind::~UnionFind() {
}

UnionFind::UnionFind(int N) {
  setSize.assign(N, 1);
  numSets = N;
  rank.assign(N, 0);
  parent.assign(N, 0);
  for(int i = 0; i < N; ++i) {
    parent[i] = i;
  }
}

int UnionFind::findSet(int i) {
  if(parent[i] == i) {
    return i;
  } else {
    return (parent[i] = findSet(parent[i]));
  }
}

bool UnionFind::isSameSet(int i, int j) {
  return (findSet(i) == findSet(j));
}

void UnionFind::unionSet(int i, int j) {
  if(!isSameSet(i, j)) {
    --numSets;
    int set1 = findSet(i);
    int set2 = findSet(j);
    if(rank[set1] > rank[set2]) {
      parent[set2] = set1;
      setSize[set1] += setSize[set2];
    } else {
      parent[set1] = set2;
      setSize[set2] += setSize[set1];
    }

    if(rank[set1] == rank[set2]) {
      rank[set2]++;
    }
  }
}

int UnionFind::numDisjointSets() {
  return numSets;
}

int UnionFind::sizeOfSet(int i) {
  return setSize[findSet(i)];
}


int main(int argc, char *argv[]) {
  int numDataSets, numComputers, node1, node2, numSuccessful, numUnsuccessful, spaceCount = 0;
  char ch;
  std::stringstream ss;
  std::string input;
  std::cin >> numDataSets;
  std::getline(std::cin, input);
  std::getline(std::cin, input);

  while(numDataSets > 0) {
    std::cin >> numComputers;
    std::getline(std::cin, input);
    numSuccessful = 0;
    numUnsuccessful = 0;
    node1 = 0;
    node2 = 0;
    UnionFind *ufp;
    ufp = new UnionFind(numComputers);

    while(std::getline(std::cin, input)) {
      if((int) input.length() == 0) {
        break;
      }
      ss.clear();
      ss.str("");
      ss << input;
      ss >> ch >> node1 >> node2;
      --node1;
      --node2;
      if(ch == 'c') {
        ufp->unionSet(node1, node2);
      }
      if(ch == 'q') {
        if(ufp->isSameSet(node1, node2)) {
          ++numSuccessful;
        } else {
          ++numUnsuccessful;
        }
      }
    }
    if(spaceCount > 0) {
      std::cout << std::endl;
    }
    spaceCount++;
    delete ufp;
    std::cout << numSuccessful << "," << numUnsuccessful << std::endl;
    numDataSets--;
  }
  return 0;
}
