#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define sz(c) int(c.size())

std::vector<int> merge(const std::vector<int> &left, const std::vector<int> &right) {
    std::vector<int> result;
    int leftIndex = 0, rightIndex = 0;
    while ((leftIndex < sz(left)) && (rightIndex < sz(right))) {
        if (left[leftIndex] <= right[rightIndex]) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        }

        if (left[leftIndex] > right[rightIndex]) {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    while (leftIndex < sz(left)) {
        result.push_back(left[leftIndex]);
        leftIndex++;
    }

    while (rightIndex < sz(right)) {
        result.push_back(right[rightIndex]);
        rightIndex++;
    }
    return result;
}

std::vector<int> mergeSort(const std::vector<int> &numbers) {
    if (sz(numbers) == 1) {
        return numbers;
    }

    int middle = (sz(numbers) / 2);
    std::vector<int> left(numbers.begin(), numbers.begin() + middle);
    std::vector<int> right(numbers.begin() + middle, numbers.end());

    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

int main(int argc, char *argv[]) {
    std::vector<int> numbers;
    srand(time(NULL));
    int randomNumber = 0;
    for (int i = 50000; i > 0; i--) {

        randomNumber = (rand() % 10000 + 1);
        numbers.push_back(randomNumber);
    }

    numbers = mergeSort(numbers);
    std::cout << "printing the sorted numbers" << std::endl;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << (it - numbers.begin()) << ": " << *it << std::endl;
    }
    return 0;
}
