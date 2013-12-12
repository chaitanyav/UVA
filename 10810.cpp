#include <iostream>
#include <vector>
#include <algorithm>
#define sz(c) (int)(c.size())

long int MergeInversions(std::vector<int> &array, int low, int mid,  int high)
{
  int n1 = mid - low + 1;
  int n2 = high -mid;
  int left[n1 + 1];
  int right[n2 + 1];

  for(int i = 0; i < n1; i++) {
    left[i] = array[low + i - 1];
  }

  for(int i = 0; i < n2; i++) {
    right[i] = array[i + mid];
  }

  // sentinels
  left[n1] = 999999;
  right[n2] = 999999;

  int i = 0;
  int j = 0;

  long int inversions = 0;
  bool counted = false;
  for(int k = low - 1; k < high; k++) {

    if((counted == false) && (left[i] > right[j] )) {
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

long int CountInversions(std::vector<int> &array, int low, int high){
  long int inversions = 0;
  if (low < high)
  {
    int mid = (low + high) / 2;
    inversions += CountInversions(array, low, mid);
    inversions += CountInversions(array, mid + 1, high);
    inversions += MergeInversions(array, low, mid, high);
  }
  return inversions;
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

      std::cout << CountInversions(numbers, 1, sz(numbers)) << std::endl;
    }
  }
  return 0;
}

