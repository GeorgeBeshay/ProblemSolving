//
// Created By George.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/4/B
 * Problem Status:      Accepted.
 */
 
 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <map>
 using namespace std;
 
 typedef long long ll;
 typedef vector<int> veci;
 typedef vector<vector<int>> vveci;
 typedef pair<int, int> pr;
 
 #define vecOf(type) vector<type>
 #define loop(loopVar, upTo) for(int loopVar = 0 ; loopVar < upTo ; loopVar++)
 
 int main(){
     int d, timeSum, timeSumCopy;
     cin >> d >> timeSum;
     timeSumCopy = timeSum;
     vecOf(pr) myVec(d);
     veci   timetable(d);
     loop(i, d){
         cin >> myVec[i].first >> myVec[i].second;
     }
     loop(i, d){
        if(timeSumCopy >= myVec[i].first){
            timetable[i] = myVec[i].first;
            timeSumCopy -= myVec[i].first;
        } else {
            if(timeSum == 0)
                continue;
            cout << "NO" << endl;
            exit(0);
        }
     }
     if(timeSumCopy > 0){
         loop(i, d){
             if(timeSumCopy > 0){
                 if(timeSumCopy >= myVec[i].second - myVec[i].first) {
                     timetable[i] += myVec[i].second - myVec[i].first;
                     timeSumCopy -= myVec[i].second - myVec[i].first;
                 } else {
                     timetable[i] += timeSumCopy;
                     timeSumCopy = 0;
                 }
             } else
                 break;
         }
     }
     if(timeSumCopy > 0){
         cout << "NO" << endl;
         exit(0);
     }
     cout << "YES" << endl;
     loop(i, d){cout << timetable[i] << " ";}
    return 0;
 }