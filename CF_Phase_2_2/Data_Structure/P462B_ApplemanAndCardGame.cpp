/*
* Problem Link:             https://codeforces.com/contest/462/problem/B
* Problem Status:           Accepted.
*/

# include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>

using namespace std;

typedef long long int ll;

// Functions Prototype
void showVector(vector<char> V);
map<char, int> CountChars(string A);
void showMap(map<char, int> M);
ll getAnswer(map<char, int> M, int K);

int main () {
//    Problem Variables
    int N;
    int K;
    string A;
    map<char, int> myMap;
//    Scanning input
    cin >> N >> K;
    getline(cin, A);
    getline(cin, A);
//    Core
    myMap = CountChars(A);
    cout << getAnswer(myMap, K) << "\n";
    return 0;
}

// Functions Definition
void showVector(vector<char> V){
    for(auto I : V)
        cout << I;
    cout << "\n";
}

map<char, int> CountChars(string A){
    map<char, int> Answer;
    for(auto C : A)
        Answer[C] += 1;
    return Answer;
}

void showMap(map<char, int> M){
    for( auto I : M )
        cout << I.first << ": " << I.second << "\n";
}

ll getAnswer(map<char, int> M, int K){
    vector<int> X;
    ll Ans = 0;
    for( auto I : M)
        X.push_back(I.second);
    sort(X.begin() , X.end());
    for(vector<int>::reverse_iterator i = X.rbegin() ; i != X.rend() ; i++){
        int I = *i;
        if(K == 0){
            break;
        }
        if(I > K){
            Ans += pow(K, 2);
            K = 0;
            break;
        } else {
            Ans += pow(I, 2);
            K -= I;
        }
    }
    return Ans;
}
