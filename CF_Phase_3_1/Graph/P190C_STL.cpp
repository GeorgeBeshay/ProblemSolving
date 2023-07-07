/*
 * Created By George on 7/7/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/190/problem/C
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> veci;
typedef vector<vector<ll>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void dfs(string& answer, int node, vector<string>& tokens, vector<vector<int>>& adjList);

int main() {

    int n;
    string line, word, answer;
    vector<string> tokens;
    stack<int> tokensStack;

    cin >> n;
    cin.ignore();
    getline(cin, line);

    istringstream ss(line);
    while(ss >> word)
        tokens.push_back(word);

    vector<vector<int>> adjList(tokens.size());

    if(tokens.size() == 1 && tokens[0] == "int"){
        cout << "int" << endl;
        exit(0);
    }

    for(int i = 0 ; i < tokens.size() ; i++){
        if(tokens[i] == "pair")
            tokensStack.push(i);
        else {
            if(tokensStack.empty()){
                cout << "Error occurred" << endl;
                exit(0);
            }
            adjList[tokensStack.top()].push_back(i);
            int tempIndex;
            while(adjList[tokensStack.top()].size() == 2){
                tempIndex = tokensStack.top();
                tokensStack.pop();
                if(!tokensStack.empty())
                    adjList[tokensStack.top()].push_back(tempIndex);
                else
                    break;
            }
        }
    }

    for(int i = 0 ; i < adjList.size() ; i++){
        if((adjList[i].empty() && tokens[i] == "int") || adjList[i].size() == 2)
            continue;
        cout << "Error occurred" << endl;
        exit(0);
    }

    dfs(answer, 0, tokens, adjList);
    cout << answer << endl;

    return 0;
}

void dfs(string& answer, int node, vector<string>& tokens, vector<vector<int>>& adjList){
    if(tokens[node] == "int")
        answer += "int";
    else {
        answer += "pair<";
        dfs(answer, adjList[node][0], tokens, adjList);
        answer += ",";
        dfs(answer, adjList[node][1], tokens, adjList);
        answer += ">";
    }
}