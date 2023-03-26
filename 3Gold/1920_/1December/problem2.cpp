/*
ID: 06jajun
TASK: milkvisits
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

const int MXN = 1e5+1;
const int MXM = 1e5+1;
const int INF = 1e9;

int n, m;
int types[MXN];
vector<int> adj[MXN];
int queries[MXM][2], query_type[MXM];
vector<int> to_search[MXN];
pair<int, int> ancestor_ranges[MXN];
int ans[MXN];
vector<pair<int, int>> prevs[MXN];

ifstream fin ("milkvisits.in");
ofstream fout ("milkvisits.out");

int cnt = 0;
void find_ancestor_ranges(int cur=1, int par=0) {
    ancestor_ranges[cur].first = cnt++;
    for (int ne : adj[cur]) if (ne != par) {
        find_ancestor_ranges(ne, cur);
    }
    ancestor_ranges[cur].second = cnt;
}

bool is_anc(int x, int y) {
    return ancestor_ranges[x].first <= ancestor_ranges[y].first && ancestor_ranges[y].second <= ancestor_ranges[x].second;
}

vector<int> cache;
void search(int cur=1, int par=0) {
    prevs[types[cur]].push_back({cur, cache.size()});
    cache.push_back(cur);
    for (int to_check : to_search[cur]) if (!prevs[query_type[to_check]].empty()) {
        pair<int, int> cprev = prevs[query_type[to_check]].back();
        // for (pair<int, int> t : prevs[query_type[to_check]]) cout << t.first << '=' << t.second << ' ';
        // cout << endl;
        if (cprev.first == cur) {
            ans[to_check] = 1;
            // cout << cur << ' ' << to_check << '=' << cprev.first << ' ' << cprev.second <<  endl;
        }
        else {
            if (!is_anc(cache[cprev.second+1], queries[to_check][0] + queries[to_check][1] - cur)) {
                ans[to_check] = 1;
                // cout << cur << ' ' << to_check << '=' << cprev.first << ' ' << cprev.second <<  endl;
            }
        }
    }
    for (int ne : adj[cur]) if (ne != par) search(ne, cur);
    prevs[types[cur]].pop_back();
    cache.pop_back();
}

int main() {
    fin >> n >> m;
    for (int i=1; i<=n; i++) {
        fin >> types[i];
    }
    for (int i=0; i<n - 1; i++) {
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find_ancestor_ranges();

    // for (int i=0; i<=n; i++) {
    //     cout << i << '=' << ancestor_ranges[i].first << ' ' << ancestor_ranges[i].second << endl;
    // }
    
    for (int i=0; i<m; i++) {
        int a, b, c;
        fin >> a >> b >> c;
        queries[i][0] = a, queries[i][1] = b;
        query_type[i] = c;
        to_search[a].push_back(i);
        to_search[b].push_back(i);
    }

    search();
    
    for (int i=0; i<m; i++) {
        fout << ans[i];
    }
    fout << endl;
}
