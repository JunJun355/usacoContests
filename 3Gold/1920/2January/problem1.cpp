/*
ID: 06jajun
TASK: time
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define MXN 1000
#define INF 1000000000

int n, m, c;
int gains[MXN];
vector<int> edges[MXN];
int dp[MXN+1][MXN+1];
ifstream fin ("time.in");
ofstream fout ("time.out");

int main() {
    fin >> n >> m >> c;
    for (int i=0; i<n; i++) {
        fin >> gains[i];
    }
    for (int i=0; i<m; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        // edges[b].push_back(a);
    }
    for (int i=0; i<MXN; i++) for (int j=0; j<MXN; j++) {
        dp[i][j] = -INF;
    }
    dp[0][0] = 0;
    for (int i=0; i<MXN; i++) {
        bool t = false;
        int z = c*((i << 1) + 1);
        for (int j=0; j<n; j++) {
            if (dp[i][j] >= -INF) {
                t = true;
                for (int k : edges[j]) {
                    dp[i+1][k] = max(dp[i+1][k], dp[i][j] + gains[k] - z);
                }
            }
        }
        if (!t) break;
        // for (int i=0; i<10; i++) {
        //     for (int j=0; j<10; j++) {
        //         cout << dp[j][i] << ' ';
        //     }
        //     cout << endl;
        // }
    }
    int mx = 0;
    for (int i=0; i<MXN; i++) {
        mx = max(mx, dp[i][0]);
    }
    fout << mx << endl;
}
