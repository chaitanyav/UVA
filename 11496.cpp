#include <iostream>
#include <cstring>
#include <cstdlib>

int main(int argc, char *argv[]) {
  int sequence[10000];
  int num_sequence = 0;
  int index = 0;

  while(std::cin >> num_sequence) {
    if(num_sequence == 0) {
      break;
    } else {
      int num_peaks = 0;
      memset(sequence, 0, 10000 * sizeof(int));
      for(index = 0; index < num_sequence; index++) {
        std::cin >> sequence[index];
      }

      for(index = 0; index < num_sequence; index++) {

        if(index == 0) {
          if(((sequence[index] > sequence[index + 1]) && (sequence[num_sequence - 1] < sequence[index])) || ((sequence[index] < sequence[index + 1]) && (sequence[num_sequence - 1] > sequence[index]))) {
          num_peaks++;
          }
        } else if(index == (num_sequence - 1)) {
          if(((sequence[index] > sequence[index - 1]) && (sequence[0] < sequence[index])) || ((sequence[index] < sequence[index - 1]) && (sequence[0] > sequence[index]))) {
          num_peaks++;
          }
        } else {
          if(((sequence[index] > sequence[index - 1]) && (sequence[index] > sequence[index + 1])) || ((sequence[index] < sequence[index - 1]) && (sequence[index] < sequence[index + 1]))) {
          num_peaks++;
          }
        }
      }

      std::cout << num_peaks << std::endl;

    }
  }
  return 0;
}
