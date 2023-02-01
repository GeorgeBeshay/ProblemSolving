//
// Created by George on 2/1/2023.
//

/*
 * Problem Link:
 * Problem Status:
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> getScore(string game);

int main(){
    int n, m;
    cin >> n >> m;
    string game = "b";
    bool vasyaTurn = true;
    if(n % 2 == 0 && m % 2 == 0){
        if(n >= m)
            game = "r";
    } else {
        if((n <= m && n % 2 == 1)|| (n % 2 == 1 && m % 2 == 0))
            game = "r";
    }
    if(game[0] == 'r')
        n--;
    else
        m--;
    while(n + m > 0){
        if(!vasyaTurn) {
            if ( (game[game.size() - 1] == 'r' || m == 0) && n > 0) {
                game += 'r';
                n--;
            } else {
                game += 'b';
                m--;
            }
        } else {
            if ( (game[game.size() - 1] == 'r' || n == 0) && m > 0) {
                game += 'b';
                m--;
            } else {
                game += 'r';
                n--;
            }
        }
        vasyaTurn = !vasyaTurn;
    }
    vector<int> ans = getScore(game);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}

vector<int> getScore(string game){
//    cout << game << endl;
    int petya = 0;
    int vasya = 0;
    for(int i = 0 ; i < game.size() - 1 ; i++){
        if(game[i] == game[i+1])
            petya++;
        else
            vasya++;
    }
    vector<int> v = {petya, vasya};
    return v;
}