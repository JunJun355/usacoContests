/*
ID: 06jajun
TASK: template
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int MXN = 501;

#define ll long long

int n;
ll a[MXN], prefix[MXN];
map<ll, int> ini;

int main() {
    cin >> n;
    prefix[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
        // cout << prefix[i];
    }
    for (int i=0; i<=n; i++) {
        for (int j=i + 1; j<=n; j++) {
            ini[prefix[j] - prefix[i]]++;
        }
    }

    for (int i=1; i<=n; i++) {
        ll ans = abs(a[i]);
        for (int f=0; f<i; f++) {
            for (int s=i; s<=n; s++) {
                ll curr = prefix[s] - prefix[f];
                ini[curr]--;
                if (ini[curr] == 0) ini.erase(curr);
            }
        }
        // for (auto ne : ini) {
        //     cout << ne.first << ' ' << ne.second << '+' << endl;
        // }
        for (int f=0; f<i; f++) {
            for (int s=i; s<=n; s++) {
                ll curr = prefix[s] - prefix[f];

                auto itr = ini.lower_bound(curr);
                if (itr != ini.begin()) {
                    auto bot = prev(itr);
                    ans = min(ans, abs(curr - bot->first));
                }
                auto top = itr;
                if (top != ini.end()) ans = min(ans, abs(curr - top->first));
                // cout << ans << endl;
            }
        }
        for (int f=0; f<i; f++) {
            for (int s=i; s<=n; s++) {
                ini[prefix[s] - prefix[f]]++;
            }
        }
        cout << ans << endl;
    }
}
