#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

int main(int argc, char *argvv[]) {
    long long int numInputs, count = 0;
    std::set<long long int>divisors;
    long long int cookies, remaining;

    std::cin >> numInputs;

    while (numInputs > 0) {
        std::cin >> cookies >> remaining;
        divisors.clear();
        std::cout << "Case #" << ++count << ":";
        if (cookies == remaining) {
            std::cout << " 0" << std::endl;
        } else {
            long long int diff = cookies - remaining;
            long long int squareRoot = (long long int)(sqrt(diff));
            
            // only check for numbers until the square root of the difference
            // if (x % i) == 0), (x / (x/i))) is also a factor
            for (long long int i = 1; i <= squareRoot; i++) {
                if (diff % i == 0) {
                    if(i > remaining) {
                        divisors.insert(i);
                    }
                    long long int quotient = diff / i;
                    if(quotient > remaining){
                        divisors.insert(quotient);
                    }
                }
            }

            for (std::set<long long int>::iterator it = divisors.begin(); it != divisors.end(); it++) {
                std::cout << " " << *it;
            }
            std::cout << std::endl;
        }
        numInputs--;
    }
    return 0;
}
