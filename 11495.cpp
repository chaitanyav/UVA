#include <iostream>
#include <vector>
#include <algorithm>

#define sz(c) (int)(c.size())

long int mergeInversions(std::vector<int> &array, int low, int mid, int high) {
  int n1 = mid - low + 1;
  int n2 = high - mid;
  int left[n1 + 1];
  int right[n2 + 1];

  for(int i = 0; i < n1; i++) {
    left[i] = array[low + i - 1];
  }

  for(int i = 0; i < n2; i++) {
    right[i] = array[mid + i];
  }

  left[n1] = 99999;
  right[n2] = 99999;
  long int inversions = 0;
  bool counted = false;
  int i = 0, j = 0;
  for(int k = low - 1; k < high; ++k) {
    if((counted == false) && (left[i] > right[j])) {
      inversions += n1 - i;
      counted = true;
    }

    if(left[i] <= right[j]) {
      array[k] = left[i];
      i++;
    } else {
      array[k] = right[j];
      j++;
      counted = false;
    }
  }

  return inversions;
}

long int countInversions(std::vector<int> &array, int low, int high) {
  long int inversions = 0;
  if(low < high) {
    int mid = (low + high) / 2;
    inversions += countInversions(array, low, mid);
    inversions += countInversions(array, mid + 1, high);
    inversions += mergeInversions(array, low, mid, high);
  }

  return inversions;
}

int main(int argc, char *argv[]) {
  int arraySize, number;
  std::vector<int> array;

  while(std::cin >> arraySize) {
    if(arraySize == 0) {
      break;
    } else {
      array.clear();
      while(arraySize > 0) {
        std::cin >> number;
        array.push_back(number);
        arraySize--;
      }

      long int inversions = countInversions(array, 1, sz(array));
        if(inversions % 2 == 0) {
          std::cout << "Carlos" << std::endl;
        } else {
          std::cout << "Marcelo" << std::endl;
        }
    }
  }
  return 0;
}
