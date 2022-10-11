//
// Created by George on 10/10/2022.
//

/*
 * Problem Link:    https://codeforces.com/problemset/problem/776/B
 * Problem Status:  Accepted.
 */
#include <iostream>
using namespace std;

template <typename T>
void showArr(T A[], int N);
bool IsPrime(int n);

int main(){
    // ---------- Separator ----------
    int N;
    cin >> N;
    int Answer[N];
    bool flag = false;
    // ---------- Separator ----------
    for(int i = 0 ; i < N ; i++)
        if (IsPrime(i+2))
            Answer[i] = 1;
        else {
            Answer[i] = 2;
            flag = true;
        }

    // ---------- Separator ----------
    if(flag)
        cout << 2 << endl;
    else
        cout << 1 << endl;
    showArr(Answer, N);
    // ---------- Separator ----------
    return 0;
}

template <typename T>
void showArr(T A[], int N){
    for(int i = 0 ; i < N ; i++)
        cout << A[i] << " ";
    cout << endl;
}

bool IsPrime(int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}