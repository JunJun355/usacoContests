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
#include <set>
#include <map>

using namespace std;

const int MXN = 2e5+1;
const long long INF = 9e18;
using ll = long long;

int n;
bool t;
ll as[MXN];
int parent[MXN];
vector<int> children[MXN];

ll tree_size[MXN], need[MXN];
ll dp[2][MXN];
int depth[MXN];

int main() {
    cin >> n >> t;
    for (int i=2; i<=n; i++) {
        int b; ll a;
        cin >> b >> a;
        parent[i] = b;
        children[b].push_back(i);
        need[i] = a;
    }

    for (int a=n; a>0; a--) {
        tree_size[a] = 1;
        for (int b : children[a]) {
            tree_size[a] += tree_size[b];
            need[a] += need[b];
            depth[a] = max(depth[a], depth[b] + 1);
        }

        sort(children[a].begin(), children[a].end(),
            [] (int one, int two) {
                return tree_size[one] * need[two] < tree_size[two] * need[one];
            }
        );
        // for (int b : children[a]) cout << b << ' ';
        // cout << endl;

        ll time_taken = 1;
        for (int b : children[a]) {
            dp[0][a] += time_taken * need[b] + dp[0][b];
            time_taken += 2 * tree_size[b];
        }
        // cout << dp[0][a] << endl;

        if (children[a].empty()) continue;

        dp[1][a] = INF;
        ll suffix_need = 0;
        ll suffix_tree_size = 0;
        for_each(children[a].rbegin(), children[a].rend(), [a, &suffix_need, &suffix_tree_size](int b) {
            if (depth[b] + 1 == depth[a]) {
                dp[1][a] = min(dp[1][a], dp[0][a] - (2 * tree_size[b] * suffix_need) + (suffix_tree_size * need[b]) - dp[0][b] + dp[1][b]);
            }
            suffix_need += need[b];
            suffix_tree_size += 2 * tree_size[b];
        });
    }

    if (t) {
        cout << (
            2 * (n - 1) - depth[1]
        ) << ' ' << dp[1][1];
    }
    else {
        cout << (
            2 * (n - 1)
        ) << ' ' << dp[0][1];
    }
}
