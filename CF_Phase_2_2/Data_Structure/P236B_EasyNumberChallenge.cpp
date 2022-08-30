/*
* Problem Link:         https://codeforces.com/contest/236/problem/B
* Problem Status:       Accepted.
*/

#include<iostream>
using namespace std;

// Functions Prototype
int TheAmazingFunction(int X);

// Global Variables
int Table[100*100*100+1] = {0};

int main(){
    int A, B, C, Answer;
    Answer = 0;
    cin >> A >> B >> C;
    for(int i = 1 ; i <= A ; i++ )
        for(int j = 1 ; j <= B ; j++)
            for(int k = 1 ; k <= C ; k++)
                Answer += TheAmazingFunction(i*j*k);
    cout << Answer % 1073741824;
    return 0;
}

int TheAmazingFunction(int X){
    if(Table[X] == 0){
        int Temp = 0;
        for(int i = 1 ; i * i <= X ; i++)
            if(X % i == 0){
                Temp += 1;
                if(i * i != X)
                    Temp += 1;
            }
        Table[X] = Temp;
    }
    return Table[X];
}
