//
// Created by George on 10/5/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/431/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getTotal(vector < vector < int > >, int B[] );

int main(){
    // ---------- Separator ----------
    vector < vector<int> > V(5);
    vector < int > A;
    int B[5];
    int Temp;
    // ---------- Separator ----------
    for(int i = 0 ; i < 5 ; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> Temp;
            V[i].push_back(Temp);
        }
    }
    // ---------- Separator ----------
    for(int i = 0 ; i < 5 ; i++){
        B[0] = i;
        for(int j = 0 ; j < 5 ; j++){
            if(j == i)
                continue;
            B[1] = j;
            for(int k = 0 ; k < 5 ; k++){
                if(k == i || k == j)
                    continue;
                B[2] = k;
                for(int u = 0 ; u < 5 ; u++){
                    if(u == i || u == j || u == k)
                        continue;
                    B[3] = u;
                    for(int z = 0 ; z < 5 ; z++){
                        if(z == i || z == j || z == k || z == u)
                            continue;
                        B[4] = z;
                        A.push_back(getTotal(V, B));
                    }
                }
            }
        }
    }
    // ---------- Separator ----------
    sort(A.begin(), A.end());
    cout << A[A.size()-1] << endl;
    // ---------- Separator ----------
    return 0;
}

int getTotal(vector < vector < int > > V, int B[] ){
    int Answer = 0;
    // ---------- Separator ----------
    for(int i = 0 ; i < 5 ; i++){
        for(int j = i ; j < 5 ; j += 2){
            if(j+1 >= 5)
                break;
            Answer += V[B[j]][B[j+1]];
            Answer += V[B[j+1]][B[j]];
        }
    }
    // ---------- Separator ----------
    return Answer;
}