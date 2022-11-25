//
// Created by George on 11/25/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/735/B?f0a28=1
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
double getAvg(vector<int> V, int st, int end);
int main(){
    int N, N1, N2;
    double ans = 0;
    cin >> N >> N1 >> N2;
    vector<int> V(N);
    for(int i = 0 ; i < N ; i++)
        cin >> V[i];
    sort(V.begin(), V.end());
    ans += getAvg(V,V.size()-min(N1, N2), V.size()-1);
    ans += getAvg(V,V.size()-N1-N2, V.size()-min(N1, N2)-1);
    cout << setprecision(20) << ans << endl;
    return 0;
}

double getAvg(vector<int> V, int st, int end){
    double avg = 0;
    for(int i = st; i <= end ; i++)
        avg += V[i]/double((end-st+1));
    return avg;
}