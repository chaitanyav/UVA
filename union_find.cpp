#include <iostream>
#include <vector>
#include <cassert>


typedef std::vector<int> vi;

class UnionFind {
  private:
    vi parent, rank, setSize;
    int numSets;
  public:
    UnionFind(int N);
    int findSet(int i);
    bool isSameSet(int i, int j);
    void unionSet(int i, int j);
    int numDisjointSets();
    int sizeOfSet(int i);
};

UnionFind::UnionFind(int N) {
  setSize.assign(N, 1);
  numSets = N;
  rank.assign(N, 0);
  parent.assign(N, 0);
  for(int i = 0; i < N; i++) {
    parent[i] = i;
  }
}

int UnionFind::findSet(int i) {
  if(parent[i] == i ) {
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
  UnionFind UF(5);
  assert(UF.isSameSet(0, 1) == false);
  assert(UF.isSameSet(1, 2) == false);
  assert(UF.isSameSet(2, 3) == false);
  assert(UF.isSameSet(3, 4) == false);
  assert(UF.sizeOfSet(0) == 1);
  assert(UF.sizeOfSet(1) == 1);
  assert(UF.sizeOfSet(2) == 1);
  assert(UF.sizeOfSet(3) == 1);
  assert(UF.sizeOfSet(4) == 1);
  UF.unionSet(0, 1);
  assert(UF.isSameSet(0, 1));
  UF.unionSet(2, 3);
  assert(UF.isSameSet(2, 3));
  UF.unionSet(4, 3);
  assert(UF.isSameSet(4, 3));
  assert(UF.isSameSet(0, 3) ==  false);
  UF.unionSet(0, 3);
  assert(UF.isSameSet(1, 3));
  assert(UF.isSameSet(0, 3));
  assert(UF.sizeOfSet(3) == 5);
  assert(UF.numDisjointSets() == 1);
  return 0;
}
