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
vector<pair<long long, long long>> fracs[MXN];
int counts[MXN];
bool see[MXN][MXN];

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
            if (slope_num * nd <= slope_den * nn) {
                counts[i]++;
                see[i][j] = true;
                see[j][i] = true;
                slope_num = nn, slope_den = nd;
            }
            fracs[i][j] = make_pair(slope_num, slope_den);
            // counts[i][j] = ans;
            // cout << slope_num << ' ' << slope_den << endl;
        }
    }
    for (int i=0; i<n; i++) cout << counts[i];

    cin >> q;
    for (int c=0; c<q; c++) {
        int m, a;
        cin >> m >> a; m--;
        heights[m] += a;
        ans = 0;
        // long long slope_num = fracs[m][max(m - 1, m)].first, slope_den = fracs[m][max(m - 1, m)].second;
        long long slope_num = -2147483648, slope_den = 1;
        for (int j=m + 1; j<n; j++) {
            int nn = heights[j] - heights[m], nd = j - m;
            if (slope_num * nd <= slope_den * nn) {
                if (!see[m][j]) {
                    counts[m]++;
                    see[m][j] = true;
                    see[j][m] = true;
                }
                slope_num = nn, slope_den = nd;
            }
            // fracs[m][j] = make_pair(slope_num, slope_den);
            // counts[i][j] = ans;
            // cout << slope_num << ' ' << slope_den << ' ' << counts[i][j] << endl;
        }
        slope_num = -2147483648, slope_den = 1;
        for (int j=m - 1; j>=0; j--) {
            int nn = heights[j] - heights[m], nd = m - j;
            if (slope_num * nd <= slope_den * nn) {
                if (!see[m][j]) {
                    counts[j]++;
                    see[m][j] = true;
                    see[j][m] = true;
                }
                slope_num = nn, slope_den = nd;
            }
            // fracs[m][j] = make_pair(slope_num, slope_den);
            // counts[i][j] = ans;
            // cout << slope_num << ' ' << slope_den << ' ' << counts[i][j] << endl;
        }
        for (int i=0; i<n; i++) ans += counts[i];
        cout << ans << endl;
    }
}
