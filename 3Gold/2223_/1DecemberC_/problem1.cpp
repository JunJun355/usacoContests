/*
ID: 06jajun
TASK: template
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define MXN 2000
#define INF 2e9

int n, a, b;
int friends[MXN][3], dp[2 * MXN][MXN];

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        for (int j=0; j<3; j++) {
            cin >> friends[i][j];
        }
    }
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<3; j++) {
    //         cout << friends[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // sort(friends.begin(), friends.end());
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<3; j++) {
    //         cout << friends[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    vector<pair<int, int>> todo;
    todo.push_back(make_pair(0, 0));
    for (int c=0; c < n; c++) {
        // cout << todo.size() << endl;
        int tn = todo.size();
        for (int count = 0; count < tn; count++) {
            pair<int, int> curr = todo[count];
            int x = curr.first, y = curr.second;
            // cout << x << ' ' << y << endl;
            int dx = x + friends[c][1], dy = y;
            do {
                dp[dx][dy] = max(dp[dx][dy], dp[x][y] + friends[c][0]);
                if (dx <= a) {
                    ans = max(ans, dp[x][y] + friends[c][0]);
                // cout << dx << ' ' << dy << endl;
                    todo.push_back(make_pair(dx, dy));
                }
                dy += friends[c][2];
                dx -= 1;
            } while (dy <= b);
            // for (int i=0; i<=b; i++) {
            //     for (int j=0; j<=a; j++) {
            //         cout << dp[j][i] << ' ';
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }
    }
    cout << ans << endl;
}
