//
// Created by George on 10/16/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/194/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    int T;
    cin >> T;
    vector<long long> V(T);
    for(int i = 0 ; i < T ; i++)
        cin >> V[i];
    for(int i = 0 ; i < T ; i++){
            if(V[i] % 2 == 0)
                cout << setprecision(40) << 4*V[i]+1 << endl;
            else {
                long long k;
                if( (V[i]+1) % 4 == 0 )
                    k = (V[i] + 1) / double(4);
                else
                    k = (V[i] + 1) / double(2);
                cout << setprecision(40) << (((4*V[i])/double(V[i]+1)) * k) + 1 << endl;
            }
    }
    return 0;
}