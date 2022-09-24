//
// Created by George on 9/24/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/318/B
 * Problem Status:      Accepted.
 */

//  ----------------------- Separator -----------------------
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//  ----------------------- Functions Prototype -----------------------
long long TheAmazingFunction(string s);
void showArray(int A[], int size);
//  ----------------------- Separator -----------------------
int main() {
    string input;
    getline(cin, input);
    cout << TheAmazingFunction(input) << endl;
    return 0;
}
//  ----------------------- Separator -----------------------
void showArray(int A[], int size){
    for(int i = 0 ; i < size ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
long long TheAmazingFunction(string s){
    long long Answer = 0;
    int count_1 = 0;    // "Heavy"
    int count_2 = 0;    // "Metal"
    int N[s.size()];
    int M[s.size()];
    int index = 0;
    // ----------- Separator -----------
    for(int i = 0 ; i < s.size() ; i++){
        N[i] = 0;
        M[i] = 0;
    }
    // ----------- Separator -----------
    for(auto I : s){
        switch (count_1) {
            case 0:
                if (I == 'h')
                    count_1++;
                break;
            case 1:
                if (I == 'e')
                    count_1++;
                else if (I == 'h')
                    count_1 = 1;
                else
                    count_1 = 0;
                break;
            case 2:
                if (I == 'a')
                    count_1++;
                else if (I == 'h')
                    count_1 = 1;
                else
                    count_1 = 0;
                break;
            case 3:
                if (I == 'v')
                    count_1++;
                else if (I == 'h')
                    count_1 = 1;
                else
                    count_1 = 0;
                break;
            case 4:
                if (I == 'y') {
                    M[index] = 1;
                    count_1 = 0;
                } else if (I == 'h')
                    count_1 = 1;
                else
                    count_1 = 0;
                break;
            default:
                break;
        }
        index++;
    }
    reverse(s.begin(), s.end());
    index = s.size()-1;
    for(auto I : s){
        switch (count_2) {
            case 0:
                if(I == 'l')
                    count_2++;
                break;
            case 1:
                if(I == 'a')
                    count_2++;
                else if (I == 'l')
                    count_2 = 1;
                else
                    count_2 = 0;
                break;
            case 2:
                if(I == 't')
                    count_2++;
                else if (I == 'l')
                    count_2 = 1;
                else
                    count_2 = 0;
                break;
            case 3:
                if(I == 'e')
                    count_2++;
                else if (I == 'l')
                    count_2 = 1;
                else
                    count_2 = 0;
                break;
            case 4:
                if(I == 'm') {
                    N[index] = 1;
                    count_2 = 0;
                } else if (I == 'l')
                    count_2 = 1;
                else
                    count_2 = 0;
                break;
            default:
                break;
        }
        index--;
    }
    // ----------- Separator -----------
    for(int i = s.size() - 2 ; i >= 0 ; i--){
        N[i] += N[i+1];
    }
    for(int i = 0 ; i < s.size() ; i++){
        if(M[i] == 1){
            Answer += N[i];
        }
    }
    // ----------- Separator -----------
    return Answer;
}
//  ----------------------- Separator -----------------------