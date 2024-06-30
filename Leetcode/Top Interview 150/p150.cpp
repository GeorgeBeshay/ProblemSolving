/*
 * Created By George on 5/16/2024.
 */
 
 /*
  * Problem Link:       https://leetcode.com/problems/evaluate-reverse-polish-notation/
  * Problem Status:     Accepted.
  */
  
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INT numeric_limits<int>::max()

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operandsStack;
        vector<string> operations = {"+", "-", "/", "*"};
        int op1, op2;

        for (string token : tokens) {

            if (count(operations.begin(), operations.end(),token)) {
                op2 = operandsStack.top();
                operandsStack.pop();
                op1 = operandsStack.top();
                operandsStack.pop();

                switch (token[0]) {
                    case '+':
                        operandsStack.push(op1 + op2);
                        break;
                    case '-':
                        operandsStack.push(op1 - op2);
                        break;
                    case '/':
                        operandsStack.push(op1 / op2);
                        break;
                    case '*':
                        operandsStack.push(op1 * op2);
                        break;
                }

            } else {
                operandsStack.push(stoi(token));
            }

        }

        return operandsStack.top();
    }
};

int main(){

    return 0;
}