//
// Created by George on 9/27/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/965/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>

using namespace std;

void showVec(vector<pair<int, int>> V);

int main(){
    int N; int K;
    cin >> N >> K;
    char A[N][N];
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> A[i][j];
        }
    }
    // ------------- Separator -------------
    vector< pair<int, int> > Q;
    int B[N][N];
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            B[i][j] = 0;
        }
    }
    // ------------- Separator -------------
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(A[i][j] == '.'){
                Q.push_back(make_pair(i, j));
            } else {
                Q.clear();
            }
//            showVec(Q);
            if(Q.size() == K){
                for(int z = 0 ; z < Q.size() ; z++){
                    B[Q[z].first][Q[z].second]++;
                }
                Q.erase(Q.begin());
            }
        }
        Q.clear();
    }
    // ------------- Separator -------------
    Q.clear();
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(A[j][i] == '.'){
                Q.push_back(make_pair(j, i));
            } else {
                Q.clear();
            }
            if(Q.size() == K){
                for(int z = 0 ; z < Q.size() ; z++){
                    B[Q[z].first][Q[z].second]++;
                }
                Q.erase(Q.begin());
            }
        }
        Q.clear();
    }
    // ------------- Separator -------------
    int current_Max = 0;
    pair<int, int> Max_Loc;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
//            cout << B[i][j] << " ";
            if(B[i][j] > current_Max){
                current_Max = B[i][j];
                Max_Loc = make_pair(i, j);
            }
        }
//        cout << endl;
    }
    // ------------- Separator -------------
    cout << Max_Loc.first + 1 << " " << Max_Loc.second + 1 << endl;
    // ------------- Separator -------------
    return 0;
}

void showVec(vector<pair<int, int>> V){
    for(auto X : V){
        cout << "(" << X.first << ", " << X.second << "), ";
    }
    cout << endl;
}