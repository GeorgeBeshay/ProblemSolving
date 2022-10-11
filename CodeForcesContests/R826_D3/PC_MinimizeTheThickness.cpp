//
// Created by George on 10/11/2022.
//

/*
 * Problem Link:            https://codeforces.com/contest/1741/problem/C
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getSumOfVec(vector<int> V);
int suppMethod(vector<int> X, int Start, int reqSum);
vector<int> getSeg(vector<int> X, int L, int R);
int getSumOfSum(vector<vector<int>> V);
int theAmazingFunction(vector<int> X);
void showVecOfVecs(vector<vector<int>> V);
void showVec(vector<int> V);
int getMaxLen(vector<vector<int>> V);

int main(){
    // --------------- Separator ---------------
    int T;
    int size;
    cin >> T;
    // --------------- Separator ---------------
    while(T){
        T--;
        // --------------- Separator ---------------
        cin >> size;
        vector<int> A(size);
        for(int i = 0 ; i < size ; i++)
            cin >> A[i];
        // --------------- Separator ---------------
        cout << theAmazingFunction(A) << endl;
        // --------------- Separator ---------------
    }
    // --------------- Separator ---------------
    return 0;
}

int theAmazingFunction(vector<int> X){
    vector<int> Answers;
    vector< vector<int> > segments;
    vector<int> seg;
    for(int i = 0 ; i < X.size() ; i++){
        seg.clear();
        segments.clear();
        int sum = 0;
        int temp = 0;
        int tempStart = i+1;
        bool flag = true;
        for(int j = 0 ; j <= i ; j++)
            seg.push_back(X[j]);
        segments.push_back(seg);
        sum = getSumOfVec(seg);
        temp = suppMethod(X, tempStart, sum);
        while(temp != -1){
            segments.push_back(getSeg(X, tempStart, temp));
            tempStart = temp + 1;
            temp = suppMethod(X, tempStart, sum);
        }
        if(getSumOfVec(X) == getSumOfSum(segments)){
            Answers.push_back(getMaxLen(segments));
        }
    }
    sort(Answers.begin(), Answers.end());
    return Answers[0];
}

int getMaxLen(vector<vector<int>> V){
    int max = 0;
    for(auto I : V){
        if(I.size() > max)
            max = I.size();
    }
    return max;
}

void showVecOfVecs(vector<vector<int>> V){
    for(auto I : V)
        showVec(I);
}

void showVec(vector<int> V){
    for(auto I : V)
        cout << I << " ";
    cout << endl;
}

vector<int> getSeg(vector<int> X, int L, int R){
    vector<int> Ans;
    for(int i = L ; i <= R ; i++)
        Ans.push_back(X[i]);
    return Ans;
}

int getSumOfSum(vector<vector<int>> V){
    int Sum = 0;
    for(auto I : V)
        Sum += getSumOfVec(I);
    return Sum;
}

int suppMethod(vector<int> X, int Start, int reqSum){
    int temp = 0;
    int i = Start;
    for(; i < X.size() ; i++){
        temp += X[i];
        if(temp == reqSum)
            break;
    }
    if(temp == reqSum)
        return i;
    else
        return -1;
}

int getSumOfVec(vector<int> V){
    int Ans = 0;
    for(auto I : V)
        Ans += I;
    return Ans;
}