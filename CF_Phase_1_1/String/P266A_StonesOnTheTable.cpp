// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int main() {
    // Write C++ code here
    // cout << "Hello world!";
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for(int i = 1 ; i < n ; i++){
        char c = s[i];
        if(c != s[i-1])
            continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}