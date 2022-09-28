//
// Created by George on 9/28/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/99/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void showVec(vector<int> V);
void showSet(set<int> S);

int main() {
    int N;
    set <int> S;
    // -------------- Separator --------------
    cin >> N;
    vector <int> V(N);
    for(int i = 0 ; i < N ; i++) {
        cin >> V[i];
        S.insert(V[i]);
    }
    // -------------- Separator --------------
    if(S.size() == 1){
        cout << "Exemplary pages." << endl;
    } else if (S.size() == 3){
        vector <int> S_Pro;
        for(auto X : S) {
            S_Pro.push_back(X);
        }
        int From = 0;
        int To = 0;
        int count_low = 0;
        int count_high = 0;
        for(int i = 0 ; i < N ; i++){
            if(V[i] == S_Pro[0])
                count_low++;
            else if(V[i] == S_Pro[2])
                count_high++;
            // ------- Separator -------
            if(V[i] == S_Pro[1])
                continue;
            else if (V[i] == S_Pro[0]){
                From = i + 1;
            } else {
                To = i + 1;
            }
            // ------- Separator -------
        }
        if(count_low != 1 || count_high != 1){
            cout << "Unrecoverable configuration." << endl;
        } else {
            if(S_Pro[2] - (S_Pro[1] - S_Pro[0]) == S_Pro[1]){
                cout << S_Pro[1] - S_Pro[0] << " ml. from cup #" << From << " to cup #" << To << "." << endl;
            } else {
                cout << "Unrecoverable configuration." << endl;
            }
        }
    } else if(S.size() == 2){
      if(N == 2){
          vector <int> T;
          for(auto X : S){
              T.push_back(X);
          }
          if((T[1] - T[0]) % 2 == 0){
              int To = 0;
              int From = 0;
              for(int i = 0 ; i < N ; i++){
                  if(V[i] == T[0])
                      From = i + 1;
                  else
                      To = i + 1;
              }
              cout << (T[1] - T[0]) / 2 << " ml. from cup #" << From << " to cup #" << To << "." << endl;
          } else {
              cout << "Unrecoverable configuration." << endl;
          }
      } else {
          cout << "Unrecoverable configuration." << endl;
      }
    } else {
        cout << "Unrecoverable configuration." << endl;
    }
    // -------------- Separator --------------
    return 0;
}

void showSet(set<int> S){
    for(auto X : S){
        cout << X << " ";
    }
    cout << endl;
}

void showVec(vector<int> V){
    for(auto X : V){
        cout << X << " ";
    }
    cout << endl;
}