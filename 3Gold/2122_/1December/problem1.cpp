/*
ID: 06jajun
TASK: template
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MXN = 1e5;
const int INF = 2e9;

int t, n, k, ans;
int dist[MXN], weight[MXN];
vector<int> chain;

int mini() {
    int mn = INF;
    for (int i=0; i<chain.size(); i++) {
        if (i % 2 == 0 || dist[chain[i + 1]] - dist[chain[i - 1]] <= k) {
            mn = min(mn, weight[chain[i]]);
        }
    }
    return mn;
}

int maxi() {
    if (chain.empty()) return 0;
    int dp[MXN][2];
    dp[chain.size()][0] = 0, dp[chain.size()][1] = -INF;
    // cout << "!!!!!" << endl;
    for (int i = chain.size() - 1; i >= 0; i--) {
        dp[i][0] = dp[i + 1][0], dp[i][1] = dp[i + 1][1];
        int bot = i + 1,  top = chain.size();
        while (bot < top) {
            int mid = (bot + top) / 2;
            if (dist[chain[mid]] <= dist[chain[i]] + k) bot = mid + 1;
            if (dist[chain[mid]] > dist[chain[i]] + k) top = mid;
        }
        // cout << i << ' ' << chain[i] << ' ' << bot << endl;
        int ub = bot;
        if (i == 0 || i == chain.size() - 1 ||
            dist[chain[i + 1]] - dist[chain[i - 1]] <= k || (chain.size() - i) % 2 == 0)
            dp[i][0] = max(dp[i][0], dp[ub][1] + weight[chain[i]]);
        if (i == 0 || i == chain.size() - 1 ||
            dist[chain[i + 1]] - dist[chain[i - 1]] <= k || (chain.size() - i) % 2 == 1)
            dp[i][1] = max(dp[i][1], dp[ub][0] + weight[chain[i]]);
    }
    // cout << '-' << (chain.size() & 1 ? dp[0][1] : dp[0][0]) << endl; 
    return (chain.size() & 1 ? dp[0][1] : dp[0][0]);
}
                                                                                                    
void process() {
    if (t == 1 && chain.size() % 2 == 1) ans += mini();
    if (t == 2) ans += maxi();
}

int main() {
    cin >> t >> n >> k;
    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        dist[i] = a;
        weight[i] = b;
        if (i > 0 && dist[i] - dist[i - 1] > k) {
            process();
            chain.clear();
        }
        chain.push_back(i);
    }
    process();
    cout << ans << endl;
}
