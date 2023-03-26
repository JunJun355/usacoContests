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

const int MXN = 3e2 + 1;
const int INF = 1e9;
const int MOD = 1e9+7;
using ll = long long;

int n, q;
ll a, b;
int dp[MXN][20][20];
int digs[MXN];

int num_digs(int k) {
    int ans = 0;
    while (k) {ans++;k/=10;}
    return ans;
}

int nth_dig(int place) {
    return (b / pow(10, d - l)) % 10;
}

int main() {
    cin >> n >> a >> b;
    for (int i=0; i<n; i++) cin >> digs[i];

    int d = num_digs(b);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            dp[i][j][j] = 1;
        }
    }
    for (int i=0; i<n; i++) {
        for (int l=0; l<d; l++) {
            for (int r=l+1; r<=d; r++) {
                dp[i][l][r] += dp[i-1][l][r];
                int left_int = b/pow(10, d-l-1)%
            }
        }
    }
}
