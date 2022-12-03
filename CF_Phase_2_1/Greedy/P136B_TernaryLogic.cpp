//
// Created by George on 12/3/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/136/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <math.h>
using namespace std;

string convertToTernary(int x);
int convertFromTernary(string s);
string subtractTernaries(string s1, string s2);

int main(){
    int a, b, c;
    string a_, b_, c_;
//    cout << convertFromTernary("1212") << " " << convertToTernary(14);
    cin >> a >> c;
    a_ = convertToTernary(a);
    c_ = convertToTernary(c);
    b_ = subtractTernaries(c_, a_);
//    cout << a_ << " " << c_ << endl;
//    cout << b_ << endl;
    cout << convertFromTernary(b_) << endl;
    return 0;
}

string fill(string s, int x){
    string temp = "";
    for(int i = 0 ; i < x - s.size() ; i++)
        temp += "0";
    return temp + s;
}

string subtractTernaries(string s1, string s2){
    string ans = "";
    if(s1.size() < s2.size()){
        s1 = fill(s1, s2.size());
    } else if(s1.size() > s2.size()){
        s2 = fill(s2, s1.size());
    }
    for(int i = 0 ; i < s1.size() ; i++){
        string temp1 = "";
        temp1 += s1[i];
        string temp2 = "";
        temp2 += s2[i];
        int tempNum = stoi(temp1) - stoi(temp2);
        if(tempNum < 0){
            tempNum = tempNum + 3;
        }
        ans += to_string(tempNum);
    }
    return ans;
}

int convertFromTernary(string s){
    int answer = 0;
    for(int i = 0 ; i < s.size() ; i++){
        string temp = "";
        temp += s[i];
        answer += stoi(temp) * (pow(3, s.size()-1-i));
    }
    return answer;
}

string convertToTernary(int x){
    string answer = "";
    int max = ceil(log(x) / log(3));
    for(int i = max ; i >= 0 ; i--){
        answer += to_string(int(x / pow(3, i)));
        x -= int(x / pow(3, i)) * pow(3, i);
    }
    return answer;
}