#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define sz(c) (int)(c.size())

std::map<std::string, long int> inversionCountByString;

bool compareStrings(std::string a, std::string b) {
  return (inversionCountByString[a] < inversionCountByString[b]);
}

long int mergeInversions(std::vector<int> &array, int low, int mid, int high) {
  long int inversions = 0;

  int n1 = mid - low + 1;
  int n2 = high - mid;
  int left[n1 + 1];
  int right[n2 + 1];

  for(int i = 0; i < n1; i++) {
    left[i] = array[low + i - 1];
  }

  for(int i = 0; i < n2; i++) {
    right[i] = array[i + mid];
  }

  left[n1] = 99999;
  right[n2] = 99999;

  int i = 0;
  int j = 0;
  bool counted = false;
  for(int k = low - 1; k < high; k++) {
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
  int numTestCases, stringLength, numStrings, count = 0;
  std::string input;

  std::vector<std::string> strings;
  std::cin >> numTestCases;
  std::getline(std::cin, input);

  while(numTestCases > 0) {
    ++count;
    std::getline(std::cin, input);
    std::cin >> stringLength >> numStrings;
    std::getline(std::cin, input);

    strings.clear();
    inversionCountByString.clear();

    while(numStrings > 0) {
      std::getline(std::cin, input);
      strings.push_back(input);
      std::vector<int> codes;
      for(int i = 0; i < (int) input.length(); ++i) {
        codes.push_back(input.at(i) - 'A');
      }
      inversionCountByString[input] = countInversions(codes, 1, sz(codes));
      numStrings--;
    }

    std::stable_sort(strings.begin(), strings.end(), compareStrings);
    if(count % 2 == 0) {
      std::cout << std::endl;
    }

    for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
      std::cout << *it << std::endl;
    }
    numTestCases--;
  }
  return 0;
}
