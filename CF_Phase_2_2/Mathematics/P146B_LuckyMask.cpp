//
// Created by George on 11/13/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/146/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
bool checkIfLucky(int num, int luckyNum);

int main(){
    int a, b;
    cin >> a >> b;
    for(int i = 0 ; i < pow(10, 5) ; i++){
        if(checkIfLucky(++a, b)){
            cout << a << endl;
            return 0;
        }
    }
    return 0;
}

bool checkIfLucky(int num, int luckyNum){
    string tempString = to_string(num);
    string templuckyNum = "";
    for(char x : tempString){
        if(x == '4' || x == '7')
            templuckyNum += x;
    }
    if(templuckyNum == to_string(luckyNum))
        return true;
    return false;
}
