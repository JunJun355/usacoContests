/*
ID: 06jajun
TASK: template
LANG: C++17
*/

#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define MXN 100001
#define INF 2000000000

int n, m;
unsigned long ans;
unordered_set<int> edges[MXN];
unordered_set<int> searched;

struct cmp {
    bool operator() (int a, int b) const {
        if (edges[a].size() == edges[b].size()) return a < b;
        return edges[a].size() < edges[b].size();
    }
};

set<int, cmp> ini;
unordered_set<int> it;

void dfs(int i) {
    if (searched.find(i) != searched.end()) return;
    searched.insert(i);
    ini.insert(i);
    it.insert(i);
    for (int j : edges[i]) dfs(j);
    return;
}

unordered_set<int> searched2;
vector<int> ini2;

void dfs2(int i) {
    // cout << i << endl;
    if (searched2.find(i) != searched2.end()) return;
    searched2.insert(i);
    ini2.push_back(i);
    for (int j : edges[i]) if (searched2.find(j) == searched2.end()) dfs2(j);
    return;
}

void prune() {
    int s = 0;
    while (!ini.empty()) {
        int curr = *next(ini.begin(), s);
        if (next(ini.begin(), s) == ini.end() || edges[curr].size() > edges[*ini.begin()].size()) {
            // cout << curr << *ini.begin() << s << endl;
            ini.clear();
            // cout << '-';
            break;
        }
        ans = max(ans, edges[curr].size() * ini.size());
        // cout << ans << edges[curr].size() << endl;
        ini.erase(curr);
        it.erase(curr);
        // searched2.insert(curr);
        // dfs2(*next(ini.begin(), s));
        // if (ini2.size() != ini.size()) {
        //     // cout << ini2.size();
        //     s++;
        //     ini.insert(curr);
        //     it.insert(curr);
        // }
        // else
            for (int i : it) {
                ini.erase(i);
                edges[i].erase(curr);
                ini.insert(i);
            }

        // searched2.clear();
        // ini2.clear();
    }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
    }

    for (int i=1; i<=n; i++) {
        if (searched.find(i) != searched.end()) continue;
        dfs(i);
        // for (int i : ini) cout << i << ' ';
        // cout << endl;
        prune();
        // ini.clear();
    }
    cout << ans;
}
