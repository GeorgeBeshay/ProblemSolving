/*
* Problem Link:             https://codeforces.com/problemset/problem/352/B
* Problem Status:           Accepted.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, vector<int>> TheAmazingFunction(vector<int> V);

// Functions Prototype
map<int, vector<int>> TheAmazingFunction(vector<int> V);
void showVector(vector<int> V);
void showMap(map<int, vector<int>> M);
void showSolution(map<int, vector<int>> M);
// =====================

int main() {
    // Problem Variables
    int N;
    vector<int> V;
    map<int, vector<int>> myMap;
    // Scanning Input
    cin >> N;
    for(int i = 0 ; i < N ; i++) {
        int X;
        cin >> X;
        V.push_back(X);
    }
    // =====================================
    myMap = TheAmazingFunction(V);
    // =====================================
    showSolution(myMap);
    // =====================================
    return 0;
}

map<int, vector<int>> TheAmazingFunction(vector<int> V){
    map<int, vector<int>> Answer;
    for(int i = 0 ; i < V.size() ; i++)
            Answer[V[i]].push_back(i);
    return Answer;
}

void showVector(vector<int> V){
    cout << "[ ";
    for( auto It : V )
        cout << It << " ";
    cout << "]";
}

void showMap(map<int, vector<int>> M){
    for( auto it : M){
        int Num = it.first;
        auto V = it.second;
        cout << "{ " << Num << " : ";
        showVector(V);
        cout << " }\n";
    }
}

void showSolution(map<int, vector<int>> M){
    int C = 0;
    vector<vector<int>> Answers;
    for(auto it: M){
        int Num = it.first;
        auto V = it.second;
        if(V.size() == 1){
            C++;
            Answers.push_back({Num, 0});
        } else if(V.size() == 2){
            C++;
            Answers.push_back({Num, V[1]-V[0]});
        } else {
            bool Flag = true;
            for(int i = 1 ; i < V.size() - 1 ; i++){
                if(V[i] - V[i-1] != V[i+1] - V[i]){
                    Flag = false;
                }
            }
            if(Flag){
                C++;
                Answers.push_back({Num, V[1]-V[0]});
            }
        }
    }
    cout << C << "\n";
    for(auto it: Answers){
        cout << it[0] << " " << it[1] << "\n";
    }
}
