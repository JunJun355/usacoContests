/*
ID: 06jajun
TASK: template
LANG: C++17
*/

// B < 100

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const int MXN = 3e2;
const int MXB = 4e2;
const int MOD = 1e9+7;
using ll = long long;

int n, q;
ll a, b;
int dp[MXN][MXN + 1][MXB + 1];
int digs[MXN];
int prefixes[MXN][MXN + 1][MXB + 1];

int num_digs(int k) {
    int ans = 0;
    while (k) {ans++;k/=10;}
    return ans;
}

int main() {
    cin >> n >> a >> b;
    assert(b < 400);
    for (int i=0; i<n; i++) {
        cin >> digs[i];
    }

    for (int i=0; i<n; i++) dp[i][i][0] = 1; 
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            for (int k=0; k<=b; k++) {
                dp[i][j + 1][k] += dp[i][j][k];
                dp[i][j + 1][k] %= MOD;

                int to_top = 10 * k + digs[j];
                if (to_top <= b) {
                    dp[i][j+1][to_top] += dp[i][j][k];
                    dp[i][j+1][to_top] %= MOD;
                }

                int to_bot = k + pow(10, num_digs(k)) * digs[j];
                if (to_bot <= b) {
                    dp[i][j+1][to_bot] += dp[i][j][k];
                    dp[i][j+1][to_bot] %= MOD;
                }
            }
        }
    }
    // for (int i=0; i<n; i++) {
    //     prefixes[i][i][0] = 1;
    // }
    // for (int i=0; i<MXN; i++) {
    //     for (int j=0; j<MXN; j++) {
    //         for (int k=0; k<MXB; k++) {
    //             prefixes[i][j][k] = dp[i][j][k];
    //         }
    //     }
    // }
    for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= b; k++) {
                // prefixes[i][j][k] += prefixes[i][j][k - 1];
                prefixes[i][j][k] = dp[i][j][k];
                if (k>=1) prefixes[i][j][k] += prefixes[i][j][k-1];
                prefixes[i][j][k] %= MOD;
            }
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r; l--; r--;
		cout << (prefixes[l][r+1][b] - prefixes[l][r+1][a - 1] + MOD) % MOD << endl;
	}
}
