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
vector<pair<int, int>> chain;

int mini() {
    int mn = INF;
    for (int i=0; i<chain.size(); i++) {
        if (i % 2 == 0 || chain[i + 1].first - chain[i - 1].first <= k) {
            mn = min(mn, chain[i].second);
        }
    }
    return mn;
}

int maxi() {
    int n = chain.size();
    if (!n) return 0;
    vector<pair<int, int>> dp(n + 1);
    dp[n] = {0, -INF};
    for (int i = n - 1; ~i; i--) {
        dp[i] = dp[i + 1];
        int ub = upper_bound(chain.begin(), chain.end(),
                             make_pair(chain[i].first + k, INF)) -
                 chain.begin();
        int bot = i + 1,  top = chain.size();
        while (bot < top) {
            int mid = (bot + top) / 2;
            if (chain[mid].first <= chain[i].first + k) bot = mid + 1;
            if (chain[mid].first > chain[i].first + k) top = mid;
        }
        assert(ub == bot);
        if (i == 0 || i == n - 1 ||
            chain[i + 1].first - chain[i - 1].first <= k || !(n - i & 1))
            dp[i].first = max(dp[i].first, dp[ub].second + chain[i].second);
        if (i == 0 || i == n - 1 ||
            chain[i + 1].first - chain[i - 1].first <= k || (n - i & 1))
            dp[i].second = max(dp[i].second, dp[ub].first + chain[i].second);
    }
    return (n & 1 ? dp[0].second : dp[0].first);
    // if (chain.empty()) return 0;
    // int dp[MXN][2];
    // dp[n][0] = 0, dp[chain.size()][1] = -INF;
    // // cout << "!!!!!" << endl;
    // for (int i = chain.size() - 1; i >= 0; i--) {
    //     dp[i][0] = dp[i + 1][0], dp[i][1] = dp[i + 1][1];
    //     int bot = i + 1,  top = chain.size();
    //     while (bot < top) {
    //         int mid = (bot + top) / 2;
    //         if (dist[chain[mid]] <= dist[chain[i]] + k) bot = mid + 1;
    //         if (dist[chain[mid]] > dist[chain[i]] + k) top = mid;
    //     }
    //     // cout << i << ' ' << chain[i] << ' ' << bot << endl;
    //     int ub = bot;
    //     if (i == 0 || i == chain.size() - 1 ||
    //         dist[chain[i + 1]] - dist[chain[i - 1]] <= k || (chain.size() - i) % 2 == 0)
    //         dp[i][0] = max(dp[i][0], dp[ub][1] + weight[chain[i]]);
    //     if (i == 0 || i == chain.size() - 1 ||
    //         dist[chain[i + 1]] - dist[chain[i - 1]] <= k || (chain.size() - i) % 2 == 1)
    //         dp[i][1] = max(dp[i][1], dp[ub][0] + weight[chain[i]]);
    // }
    // // cout << '-' << (chain.size() & 1 ? dp[0][1] : dp[0][0]) << endl; 
    // return (chain.size() & 1 ? dp[0][1] : dp[0][0]);
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
        chain.push_back({a, b});
    }
    process();
    cout << ans << endl;
}
