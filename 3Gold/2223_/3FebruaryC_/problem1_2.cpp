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
map<ll, int> check;

int main() {
    cin >> n;
    prefix[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
        // cout << prefix[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=i + 1; j<=n; j++) {
            ini[prefix[j] - prefix[i]]++;
        }
    }
    for (int i=1; i<=n; i++) {
        check[prefix[i]]++;
    }

    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            ll curr = prefix[j] - prefix[i - 1];
            ini[curr]--;
            if (ini[curr] == 0) ini.erase(curr);
            if (i != 1) check[curr]++;
        }
        ll ans = abs(a[i]);
        for (auto thing : check) {
            ll curr = thing.first;
            // cout << "+++" << curr << ' ' << thing.second << endl;
            auto itr = ini.lower_bound(curr);
            if (itr != ini.begin()) {
                auto bot = prev(itr);
                ans = min(ans, abs(curr - bot->first));
            }
            auto top = itr;
            if (top != ini.end()) ans = min(ans, abs(curr - top->first));
            // cout << ans << endl;
        }
        // cout << ini.size() << endl;
        cout << ans << endl;
        for (int j=0; j<i; j++) {
            // cout << 'j' << j;
            ll curr = prefix[i] - prefix[j];
            ini[curr]++;
            check[curr]--;
            if (check[curr] == 0) check.erase(curr);
            // curr = prefix[i + 1] - prefix[j];
            // check[curr]++;
        }

    }
}
