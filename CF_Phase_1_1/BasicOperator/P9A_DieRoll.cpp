//
// Created by George on 10/20/2022.
//

/*
 * Problem Link:        https://codeforces.com/contest/9/problem/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;

int main() {
    int X, Y, Z;
    std::cin >> Y >> Z;
    // ---------- Separator ----------
    X = 6 - (std::max(Y, Z)) + 1;
    switch(X){
        case 1:
            std::cout << "1/6" << std::endl;
            exit(0);
        case 2:
            std::cout << "1/3" << std::endl;
            exit(0);
        case 3:
            std::cout << "1/2" << std::endl;
            exit(0);
        case 4:
            std::cout << "2/3" << std::endl;
            exit(0);
        case 5:
            std::cout << "5/6" << std::endl;
            exit(0);
        case 6:
            std::cout << "1/1" << std::endl;
            exit(0);
    }
    return 0;
}