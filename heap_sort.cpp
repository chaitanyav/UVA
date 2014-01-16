#include <iostream>
#include <vector>
#include <cmath>

template <typename ValueType>
class BinaryHeap {
  private:
    std::vector<ValueType> heap;
    int heapSize;
    void maxHeapify(int i);
    void buildHeap();
  public:
    BinaryHeap();
    void sort();
    ValueType extractMax();
    void add(ValueType value);
};

template <typename ValueType>
void BinaryHeap<ValueType>::maxHeapify(int i) {
  int l = 2 * i;
  int r = (2 * i) + 1;
  int largest = 0;
  if(l <= heapSize && heap[l] > heap[i]) {
    largest = l;
  } else {
    largest = i;
  }

  if(r <= heapSize && heap[r] > heap[largest]) {
    largest = r;
  }

  if(largest != i) {
    std::swap(heap[i], heap[largest]);
    maxHeapify(largest);
  }
}

template <typename ValueType>
void BinaryHeap<ValueType>::buildHeap() {
  heapSize = (int) heap.size();
  heapSize = heapSize - 1;
  int mid = floor(heapSize / 2.0);
  for(int i = mid; i >= 0; i--) {
    maxHeapify(i);
  }
}

template <typename ValueType>
BinaryHeap<ValueType>::BinaryHeap() {
  heap.clear();
}

template <typename ValueType>
void BinaryHeap<ValueType>::sort() {
  buildHeap();

  for(int i = heapSize; i >= 1; i--) {
    std::swap(heap[0], heap[i]);
    heapSize = heapSize - 1;
    maxHeapify(0);
  }

}

template <typename ValueType>
ValueType BinaryHeap<ValueType>::extractMax() {
  buildHeap();
  return heap[0];
}

template <typename ValueType>
void BinaryHeap<ValueType>::add(ValueType value) {
    heap.push_back(value);
}

int main(int argc, char *argv[]) {
  BinaryHeap<int> heap;
  heap.add(9);
  heap.add(4);
  heap.add(1);
  heap.add(20);
  heap.add(14);
  heap.add(17);
  heap.add(8);
  heap.add(6);
  std::cout << heap.extractMax() << std::endl;
  return 0;
}

