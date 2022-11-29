//
// Created by George on 11/27/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/46/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    int K;
    string s;
    map<string, int> M;
    string A[5];
    A[0] = "S";A[1] = "M";A[2] = "L";A[3] = "XL";A[4] = "XXL";
    cin >> M["S"] >> M["M"] >> M["L"] >> M["XL"] >> M["XXL"] >> K;
    getline(cin, s);
    while(K){
        K--;
        getline(cin, s);
        if(M[s] > 0){
            cout << s << endl;
            M[s]--;
        } else {
            int i = 0;
            for( ; i < 5 ; i++){
                if(A[i] == s)
                    break;
            }
            int left = -1;
            int right = 1;
            while(i + right <= 4 || i + left >= 0) {
                if (i + right <= 4) {
                    if (M[A[i + right]] > 0) {
                        cout << A[i + right] << endl;
                        M[A[i + right]]--;
                        break;
                    } else if (i + left >= 0) {
                        if (M[A[i + left]] > 0) {
                            cout << A[i + left] << endl;
                            M[A[i + left]]--;
                            break;
                        } else {
                            left--;
                            right++;
                        }
                    } else {
                        left--;
                        right++;
                    }
                } else if (i + left >= 0) {
                    if (M[A[i + left]] > 0) {
                        cout << A[i + left] << endl;
                        M[A[i + left]]--;
                        break;
                    } else {
                        left--;
                        right++;
                    }
                } else {
                    cout << " ERROR " << endl;
                }
            }
        }
    }
    return 0;
}