/*
* Problem Link:         https://codeforces.com/contest/222/problem/B
* Problem Status:       Accepted.
*/

#include <iostream>
#include<vector>

using namespace std;

// -------------------------------- Functions Prototype --------------------------------
void showVector(vector<vector<int>> A);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // -------------------------------- Scanning Input --------------------------------
    int N; int M; int K;
    vector<vector<int>> Grid;
    cin >> N >> M >> K;
    vector<int> Columns(M);
    for(int i = 0 ; i < N ; i++){
        vector<int> Temp (M);
        for(int j = 0 ; j < M ; j++){
            Columns[j] = j;
            int X;
            cin >> X;
            Temp[j] = X;
        }
        Grid.push_back(Temp);
    }
    // ----------------------------------- Check -----------------------------------
//    showVector(Grid);
    // ----------------------------------- Separator -----------------------------------
    while(K > 0){
        char S;
        int X;
        int Y;
        cin >> S >> X >> Y;
        X--;
        Y--;
        if(S == 'g')
            cout << Grid[X][Columns[Y]] << "\n";
        else if(S == 'r')
            Grid[X].swap(Grid[Y]);
        else
            swap(Columns[X], Columns[Y]);
        K--;
    }
    // ----------------------------------- Separator -----------------------------------
    return 0;
}

void showVector(vector<vector<int>> A){
    for(int i = 0 ; i < A.size() ; i++){
        for(int j = 0 ; j < A[0].size() ; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
}
