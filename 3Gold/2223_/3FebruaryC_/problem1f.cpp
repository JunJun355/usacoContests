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

const int MXN = 5e2 + 1;
const long long INF = 1e15;

int n;
long long a[MXN], prefixes[MXN];
long long ans[MXN];
vector<pair<int, int>> subarrays;

struct by_sum {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return (prefixes[a.second] - prefixes[a.first]) < (prefixes[b.second] - prefixes[b.first]);
    }
};

bool ini(pair<int, int> a, int b) {
    return a.first < b && b <= a.second;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefixes[i] = prefixes[i - 1] + a[i];
    }
    for (int i=0; i<MXN; i++) {
        ans[i] = INF;
    }
    
    for (int i=0; i<n; i++) {
        for (int j=i + 1; j<=n; j++) {
            subarrays.push_back(make_pair(i, j));
        }
    }
    
    sort(subarrays.begin(), subarrays.end(), by_sum());

    for (int i = 0; i < subarrays.size() - 1; i++) {
        long long sum1 = prefixes[subarrays[i].second] - prefixes[subarrays[i].first];
        long long sum2 = prefixes[subarrays[i + 1].second] - prefixes[subarrays[i + 1].first];
        for (int j = 1; j <= n; j++) {
            if (ini(subarrays[i], j) != ini(subarrays[i + 1], j))
                ans[j] = min(ans[j], abs(sum1 - sum2));
        }
    }

    for (int i=1; i<=n; i++) {
        cout << ans[i] << endl;
    }
}
