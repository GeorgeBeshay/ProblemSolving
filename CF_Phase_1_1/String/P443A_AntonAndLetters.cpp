/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s;
    int ans = 0, index = 0;
    map<char, int> m;
    getline(cin, s);
    while(true){
        char c = s[index++];
        if(c == '}')
            break;
        if(c == '{' || c == ' ' || c == ',')
            continue;
        else{
            m[c]++;
            if(m[c] == 1){
                // cout << c << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}