/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<vector<char>> v(n);

    for(int i = 0 ; i < n ; i++){
        vector<char> temp(n);
        v.push_back(temp);
        for(int j = 0 ; j < n ; j++){
            v[i].push_back('.');
        }
    }
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         cout << v[i][j];
    //     }
    //     cout << endl;
    // }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i > 0){
                if(j > 0){
                    if(v[i-1][j] == '.' && v[i][j-1] == '.'){
                        v[i][j] = 'C';
                        ans++;
                    }
                } else {
                    if(v[i-1][j] == '.'){
                        v[i][j] = 'C';
                        ans++;
                    }
                }
            } else {
                if(j > 0){
                    if(v[i][j-1] == '.'){
                        v[i][j] = 'C';
                        ans++;
                    }
                } else {
                    v[i][j] = 'C';
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << v[i][j];
        }
        cout << endl;
    }

    return 0;
}