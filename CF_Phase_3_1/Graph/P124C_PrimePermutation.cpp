/*
 * Created By George on 7/2/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/124/problem/C
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

vector<int> generatePrimes(int limit);

int main() {
    // ---------------- Separator ----------------
    string input;
    int needed = 0;
    int maxFreq = 0;
    char maxChar;
    cin >> input;

    map<char, int> freq;
    for(char c : input) {
        freq[c]++;
        if(freq[c] > maxFreq){
            maxFreq = freq[c];
            maxChar = c;
        }
    }

    freq.erase(maxChar);
    auto pointer = freq.begin();

    vector<int> primes = generatePrimes(input.size());

    for(int p : primes){
        if(p > input.size() / 2)
            needed++;
    }
    needed = input.size() - needed - 1;

    if(maxFreq < needed){
        cout << "NO" << endl;
        exit(0);
    }

    string output(input.size(), '-');

    for(int p : primes){
        if(p <= output.size() / 2) {
            output[p - 1] = maxChar;
            maxFreq--;
        } else {
            if(pointer->second > 0){
                output[p-1] = pointer->first;
                pointer->second--;
                if(pointer->second == 0)
                    pointer++;
            } else {
                output[p - 1] = maxChar;
                maxFreq--;
            }
        }
    }

    if(pointer->second > 0){
        output[0] = pointer->first;
        pointer->second--;
        if(pointer->second == 0)
            pointer++;
    } else {
        output[0] = maxChar;
        maxFreq--;
    }

    for(int i = 1 ; i < output.size() ; i++){
        if(output[i] != '-')
            continue;
        output[i] = maxChar;
        maxFreq--;
    }

    cout << "YES" << endl << output << endl;
    // ---------------- Separator ----------------    
    return 0;
}

vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);  // Initialize all numbers as prime
    vector<int> primes;

    for (int p = 2; p * p <= limit; p++) {
        // If the current number is prime
        if (isPrime[p]) {
            // Update all multiples of p as non-prime
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Collect all prime numbers
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}