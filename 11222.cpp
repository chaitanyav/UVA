#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

int main(int argc, char *argv[]) {
  int num_test_cases;
  int test_case = 0;
  std::cin >> num_test_cases;

  unsigned char player1_problems[10001];
  unsigned char player2_problems[10001];
  unsigned char player3_problems[10001];

  while(num_test_cases > 0) {
    int num_players = 3;
    int max_prob = -1;
    int index = 0;

    memset(player1_problems, 0, 10001);
    memset(player2_problems, 0, 10001);
    memset(player3_problems, 0, 10001);

    while(num_players > 0) {
      int num_problems;
      std::cin >> num_problems;

      int temp;
      while(num_problems > 0) {
        std::cin >> temp;

        if(temp > max_prob) {
          max_prob = temp;
        }

          if(num_players == 3) {
            player1_problems[temp] = 1;
          } else if(num_players == 2) {
            player2_problems[temp] = 1;
          } else {
            player3_problems[temp] = 1;
          }

        num_problems--;
      }

      num_players--;
    }

    int player1_solved = 0;
    int player2_solved = 0;
    int player3_solved = 0;
    std::vector<int> player1_uniq_probs;
    std::vector<int> player2_uniq_probs;
    std::vector<int> player3_uniq_probs;

    for(index = 0; index <= max_prob; index++) {
      if(player1_problems[index] == 1 && player2_problems[index] == 0 && player3_problems[index] == 0) {
        player1_solved++;
        player1_uniq_probs.push_back(index);
      }

      if(player1_problems[index] == 0 && player2_problems[index] == 1 && player3_problems[index] == 0) {
        player2_solved++;
        player2_uniq_probs.push_back(index);
      }

      if(player1_problems[index] == 0 && player2_problems[index] == 0 && player3_problems[index] == 1) {
        player3_solved++;
        player3_uniq_probs.push_back(index);
      }
    }


    std::cout << "Case #" << ++test_case << ":" << std::endl;

    if((player1_solved >= player2_solved) && (player1_solved >= player3_solved)) {
      std::cout << "1 " << player1_uniq_probs.size();
      std::sort(player1_uniq_probs.begin(), player1_uniq_probs.end());
      for(std::vector<int>::iterator it = player1_uniq_probs.begin(); it != player1_uniq_probs.end(); it++) {
        std::cout << " " << *it;
      }
      std::cout << std::endl;
    }

    if((player2_solved >= player1_solved) && (player2_solved >= player3_solved)) {
      std::cout << "2 " << player2_uniq_probs.size();
      std::sort(player2_uniq_probs.begin(), player2_uniq_probs.end());
      for(std::vector<int>::iterator it = player2_uniq_probs.begin(); it != player2_uniq_probs.end(); it++) {
        std::cout << " " << *it;
      }
      std::cout << std::endl;
    }

    if((player3_solved >= player1_solved) && (player3_solved >= player2_solved)) {
      std::cout << "3 " << player3_uniq_probs.size();
      std::sort(player3_uniq_probs.begin(), player3_uniq_probs.end());
      for(std::vector<int>::iterator it = player3_uniq_probs.begin(); it != player3_uniq_probs.end(); it++) {
        std::cout << " " << *it;
      }
      std::cout << std::endl;
    }

    num_test_cases--;
  }
  return 0;
}
