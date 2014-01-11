#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <cassert>

template <typename ValueType>
class Stack {
  public:
    Stack();
    virtual ~Stack();
    int size() const;
    bool isEmpty() const;
    void clear();
    void push(ValueType value);
    ValueType pop();
    ValueType peek() const;
    ValueType &top();
  private:
    std::vector<ValueType> elements;
};

template <typename ValueType> Stack<ValueType>::Stack() {

}

template <typename ValueType> Stack<ValueType>::~Stack() {

}

template <typename ValueType> int Stack<ValueType>::size() const {
  return (int) elements.size();
}

template <typename ValueType> void Stack<ValueType>::push(ValueType value) {
  elements.push_back(value);
}

template <typename ValueType> bool Stack<ValueType>::isEmpty() const {
  return elements.empty();
}

template <typename ValueType> ValueType Stack<ValueType>::pop() {
  if(isEmpty()) {
    throw std::runtime_error("pop: attempting to pop an empty stack");
  }
  ValueType top = elements[size() - 1];
  elements.pop_back();
  return top;
}

template <typename ValueType> ValueType Stack<ValueType>::peek() const {
  if(isEmpty()) {
    throw std::runtime_error("peek: attempting to peek an empty stack");
  }
  return elements[size() - 1];
}

template <typename ValueType> ValueType& Stack<ValueType>::top() {
  if(isEmpty()) {
    throw std::runtime_error("top: attempting to read top of an empty stack");
  }
  return elements.back();
}

template <typename ValueType> void Stack<ValueType>::clear() {
  elements.clear();
}

int main(int argc, char *argv[]) {
  Stack<int> stack;
  stack.push(1);
  assert(stack.peek() == 1);
  stack.push(2);
  assert(stack.peek() == 2);
  stack.push(3);
  assert(stack.peek() == 3);
  int &c = stack.top();
  c = 4;
  assert(stack.peek() == 4);
  assert(stack.isEmpty() == false);
  assert(stack.pop() == 4);
  assert(stack.pop() == 2);
  assert(stack.pop() == 1);
  assert(stack.isEmpty());
  stack.push(1);
  assert(stack.pop() == 1);
  assert(stack.isEmpty());
  stack.push(2);
  stack.clear();
  assert(stack.isEmpty());

  return 0;
}
