/*
* Problem Link:                 https://codeforces.com/contest/5/problem/B
* Problem Status:           Accepted.
*/

#include <iostream>
#include <vector>

using namespace std;

void TheAmazingFunction(vector<string> A, int X){
    bool LeftFlag = true;
    cout << string(X+2, '*') << endl;
    for(auto I : A){
        if(  (X - I.size()) % 2 == 0 ){
            cout << "*";
            cout << string( (X-I.size()) / 2 , ' ' );
            cout << I;
            cout << string( (X-I.size()) / 2 , ' ' );
            cout << "*" << endl;
        } else {
            if(LeftFlag){
                LeftFlag = false;
                cout << "*";
                cout << string( (X-I.size()) / 2 , ' ' );
                cout << I;
                cout << string( (X-I.size()) / 2  + 1, ' ' );
                cout << "*" << endl;
            } else {
                LeftFlag = true;
                cout << "*";
                cout << string( (X-I.size()) / 2 + 1, ' ' );
                cout << I;
                cout << string( (X-I.size()) / 2 , ' ' );
                cout << "*" << endl;
            }
        }
    }
    cout << string(X+2, '*') << endl;
}

int main () {
    vector<string> A;
    int Max = 0;
    string S;
    while(getline(cin, S)){
        if(S.length() > Max)
            Max = S.length();
        A.push_back(S);
    }
    TheAmazingFunction(A, Max);
    return 0;
}
