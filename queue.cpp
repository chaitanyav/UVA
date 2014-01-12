#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

template <typename ValueType>
class Queue {
  public:
    Queue();
    virtual ~Queue();
    int size() const;
    bool isEmpty() const;
    void clear();
    void enqueue(ValueType value);
    ValueType dequeue();
    ValueType peek() const;
    ValueType &front();
    ValueType &back();
  private:
    std::vector<ValueType> ringBuffer;
    int head;
    int tail;
    int count;
    int capacity;
    void expandRingBufferCapacity();
};

const int INITIAL_CAPACITY = 10;

template <typename ValueType>
Queue<ValueType>::Queue() {
  clear();
}

template <typename ValueType>
Queue<ValueType>::~Queue() {
}

template <typename ValueType>
int Queue<ValueType>::size() const {
  return count;
}

template <typename ValueType>
bool Queue<ValueType>::isEmpty() const {
  return count == 0;
}

template <typename ValueType>
void Queue<ValueType>::clear() {
  capacity = INITIAL_CAPACITY;
  ringBuffer = std::vector<ValueType>(capacity, -1);
  head = 0;
  tail = 0;
  count = 0;
}

template <typename ValueType>
void Queue<ValueType>::enqueue(ValueType value) {
  if(count >= capacity - 1) expandRingBufferCapacity();
  ringBuffer[tail] = value;
  tail = (tail + 1) % capacity;
  ++count;
}

template <typename ValueType>
ValueType Queue<ValueType>::dequeue() {
  if(count == 0) {
    throw std::runtime_error("dequeue: Attempting to dequeue an empty queue");
  }
  ValueType value = ringBuffer[head];
  head = (head + 1) % capacity;
  --count;
  return value;
}

template <typename ValueType>
ValueType Queue<ValueType>::peek() const {
  if(count == 0) {
    throw std::runtime_error("peek: Atempting to peek an empty queue");
  }
  return ringBuffer[head];
}

template <typename ValueType>
ValueType& Queue<ValueType>::front() {
  if(count == 0) {
    throw std::runtime_error("front: Attempting to read front an empty queue");
  }
  return ringBuffer[head];
}

template <typename ValueType>
ValueType& Queue<ValueType>::back() {
  if(count == 0) {
    throw std::runtime_error("back: Attempting to read back of an empty queue");
  }
  return ringBuffer[(tail + capacity - 1) % capacity];
}

template <typename ValueType>
void Queue<ValueType>::expandRingBufferCapacity() {
  std::vector<ValueType> copy = ringBuffer;
  ringBuffer = std::vector<ValueType>(2 * capacity, -1);
  for(int i = 0; i <count; ++i) {
    ringBuffer[i] = copy[(head + i) % capacity];
  }

  head = 0;
  tail = count;
  capacity *= 2;
}


int main(int argc, char *argv[]) {
  Queue<int> queue;

  assert(queue.isEmpty());
  queue.enqueue(1);
  assert(queue.isEmpty() == false);
  assert(queue.peek() == 1);
  assert(queue.front() == 1);
  assert(queue.back() == 1);
  queue.enqueue(2);
  assert(queue.front() == 1);
  assert(queue.back() == 2);
  queue.enqueue(3);
  assert(queue.back() == 3);
  assert(queue.front() == 1);
  assert(queue.dequeue() == 1);
  assert(queue.front() == 2);
  queue.enqueue(4);
  assert(queue.back() == 4);
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  assert(queue.isEmpty());


  return 0;
}
