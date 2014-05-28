#include <iostream>
#include <sstream>
#include <string>
#include <climits>

class Solution {
public:
    int atoi(const char *str) {
        std::string input(str);
        std::stringstream ss(input);
        ss >> input;
        int sign = 1;
        int output = 0;

        for(int i = 0; i < input.length(); i++) {
            char c = input.at(i);
                //std::cout << c;
               if(i == 0 && (c == '-')) {
                sign = -1;
               } else if((i == 0) && (c == '+')){
                   sign = 1;
               } else if((i >= 0) && !((c >= '0') && (c <= '9'))){
                   break;
               }

             if( (c >= '0') && (c <= '9')) {
               if(output > INT_MAX / 10) {
                 output = -1;
                 break;
               }
               int temp = output * 10;
               output = temp + (c - '0');
             }
        }

        if(sign > 0 && output < 0) {
            output = INT_MAX;
        } else if(sign < 0 && output < 0) {
            output = INT_MIN;
        } else {
            output = sign * output;
        }
        return output;
    }
};

int main() {
  Solution s;
  std::cout << s.atoi("    10522545459") << std::endl;
  std::cout << s.atoi(" ") << std::endl;
  std::cout << s.atoi("-1") << std::endl;
  std::cout << s.atoi("+1") << std::endl;
  std::cout << s.atoi("    +105") << std::endl;
  std::cout << s.atoi("    105") << std::endl;
}
