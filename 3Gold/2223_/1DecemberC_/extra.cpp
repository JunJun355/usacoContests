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

#define MXN 2001
#define INF 2000000000

int n, q;
int heights[MXN];
int ans;
pair<long long, long long> fracs[MXN][MXN];
int counts[MXN][MXN];

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> heights[i];
    }
    // cout << endl;
    for (int i=0; i<n; i++) {
        long long slope_num = -2147483648, slope_den = 1;
        fracs[i][i] = make_pair(slope_num, slope_den);
        for (int j=i + 1; j<n; j++) {
            int nn = heights[j] - heights[i], nd = j - i;
            counts[i][j] = counts[i][j - 1];
            if (slope_num * nd <= slope_den * nn) {
                counts[i][j]++;
                slope_num = nn, slope_den = nd;
            }
            fracs[i][j] = make_pair(slope_num, slope_den);
            // counts[i][j] = ans;
            // cout << slope_num << ' ' << slope_den << endl;
        }
    }

    cin >> q;
    for (int c=0; c<q; c++) {
        int m, a;
        cin >> m >> a; m--;
        heights[m] += a;
        ans = 0;
        for (int i=0; i<=m; i++) {
            long long slope_num = fracs[i][max(m - 1, i)].first, slope_den = fracs[i][max(m - 1, i)].second;
            for (int j=max(m, i + 1); j<n; j++) {
                int nn = heights[j] - heights[i], nd = j - i;
                counts[i][j] = counts[i][j - 1];
                if (slope_num * nd <= slope_den * nn) {
                    counts[i][j]++;
                    slope_num = nn, slope_den = nd;
                }
                fracs[i][j] = make_pair(slope_num, slope_den);
                // counts[i][j] = ans;
                // cout << slope_num << ' ' << slope_den << ' ' << counts[i][j] << endl;
            }
        }
        for (int i=0; i<n; i++) ans += counts[i][n - 1];
        cout << ans << endl;
    }
}
