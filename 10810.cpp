#include <iostream>
#include <vector>
#include <algorithm>
#define sz(c) (int)(c.size())

int inversions = 0;

std::vector<int> merge(const std::vector<int> &left, const std::vector<int> &right) {
  std::vector<int> result;
  int leftIndex = 0, rightIndex = 0;
  while(left[leftIndex] < right[rightIndex]) {
    result.push_back(left[leftIndex]);
    leftIndex++;
  }

  while(left[leftIndex] > right[rightIndex]) {
    result.push_back(right[rightIndex]);
    inversions++;
    rightIndex++;
  }

  while(leftIndex < sz(left)) {
    result.push_back(left[leftIndex]);
    leftIndex++;
  }
  while(rightIndex < sz(right)) {
    result.push_back(right[rightIndex]);
    rightIndex++;
  }
  return result;
}


std::vector<int> mergeSort(const std::vector<int> &numbers) {
  if(sz(numbers) == 1) {
    return numbers;
  } else {
    int middle = (sz(numbers) / 2);
    std::vector<int> left(numbers.begin(), numbers.begin() + middle);
    std::vector<int> right(numbers.begin() + middle, numbers.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
  }
}

int main(int argc, char *argv[]) {
  int testCase, num;
  std::vector<int> numbers;

  while(std::cin >> testCase) {
    if(testCase == 0) {
      break;
    } else {
      numbers.clear();
      while(testCase > 0) {
        std::cin >> num;
        numbers.push_back(num);
        testCase--;
      }

      inversions = 0;
      mergeSort(numbers);
      std::cout << inversions << std::endl;
    }
  }
  return 0;
}

