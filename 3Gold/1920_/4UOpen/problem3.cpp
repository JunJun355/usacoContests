/*
ID: 06jajun
TASK: exercise
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

const string NAME = "exercise";
using ll = long long;

const int MXN = 1e4+1;
const int MXP = 1229+1;
const int INF = 1e9;

int n, m;
int dp[MXP][MXN];
ifstream fin (NAME + ".in");
ofstream fout (NAME + ".out");

int add(int x, int y) {
    int res = x + y;
    if (res > m) return res - m;
    return res;
}

int mult(int x, int y) {
    ll res = (ll) x * y;
    return (int) (res % m);
}

int main() {
    fin >> n >> m;

    bool is_composite[MXN] = {false};
    vector<int> primes;
    for (int i=2; i<=n; i++) {
        if (is_composite[i]) continue;
        primes.push_back(i);
        for (int j=i * 2; j<=n; j+=i) {
            is_composite[j] = true;
        }
    }

    for (int i=0; i<=n; i++) dp[0][i] = 1;

    for (int i = 1; i <= primes.size(); i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i-1][j];
 
            int pp = primes[i-1];
            while (pp <= j) {
                dp[i][j] = add(dp[i][j], mult(pp, dp[i-1][j-pp]));
                pp *= primes[i-1];
            }
        }
    }

    fout << dp[primes.size()][n] << endl;
}
