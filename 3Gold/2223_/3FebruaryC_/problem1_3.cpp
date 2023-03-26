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

#define f first
#define s second

const int MXN = 5e2+1;
const int INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;


int n;
ll vals[MXN], prefixes[MXN];
ll ans[MXN];
vector<pi> pairs;

bool ini(int num, pi x) {
    return x.f < num && num <= x.s;
}
ll getsum(pi x) {
    return prefixes[x.s] - prefixes[x.f];
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> vals[i];
        prefixes[i] = prefixes[i - 1] + vals[i];
        ans[i] = abs(vals[i]);
    }

    for (int i=0; i<n; i++) {
        for (int j=i + 1; j<=n; j++) {
            pairs.push_back(make_pair(i, j));
        }
    }

    sort(pairs.begin(), pairs.end(),
        []( pi& x, pi& y ) {
            return getsum(x) < getsum(y);
        }
    );
    
    for (int i=0; i<pairs.size() - 1; i++) {
        // for (int i=1; i<=n; i++) {
        //     cout << ans[i];
        //     if (i != n) cout << ' ';
        //     else cout << endl;
        // }

        pi one = pairs[i];
        pi two = pairs[i + 1];
        ll sumone = getsum(one);
        ll sumtwo = getsum(two);
        for (int j=1; j<=n; j++) {
            if ((ini(j, one) && !ini(j, two)) || (ini(j, two) && !ini(j, one))) {
                ans[j] = min(ans[j], abs(sumone - sumtwo));
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << ans[i] << '\n';
    }
}