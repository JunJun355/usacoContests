/*
ID: 06jajun
TASK: shortcut
LANG: C++17
*/

// * -> x5 * -> x9 * -> x11

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <set>

using namespace std;

#define MXN 10000
#define INF 1000000000

int n, m, t;
long long ans;
int cows[MXN], dists[MXN], preds[MXN];
map<int, int> edges[MXN];
vector<int> children[MXN];
ifstream fin ("shortcut.in");
ofstream fout ("shortcut.out");

struct cmpA {
  bool operator() (int a, int b) const {
    if (dists[a] == dists[b]) return a < b;
    return dists[a] < dists[b];
  }
};

long long dfs(int i=0, int d=0) {
  long long tot = (long long)cows[i];
  for (auto j : children[i]) {
    // cout << i << ' ' << j << endl;
    tot += (long long)dfs(j, d + edges[i][j]);
  }
  ans = max(ans, tot * (d - t));
  return tot;
}

int main() {
  // Get inputs
    fin >> n >> m >> t;
    for (int i=0; i<n; i++) {
      fin >> cows[i];
    }
    for (int i=0; i<m; i++) {
      int a, b, d; fin >> a >> b >> d; a--; b--;
      edges[a][b] = d;
      edges[b][a] = d;
    }
  cout << 0 << endl;
  // Dijkstra
    for (int i=1; i<n; i++) dists[i] = INF;
    set<int, cmpA> to_search; to_search.insert(0);
    while (!to_search.empty()) {
      int curr = *(to_search.begin()); to_search.erase(to_search.begin());
      for (auto ne : edges[curr]) {
        if (dists[curr] + ne.second < dists[ne.first]) {
          dists[ne.first] = dists[curr] + ne.second;
          to_search.erase(ne.first); to_search.insert(ne.first);
          preds[ne.first] = curr;
        }
        else if (dists[curr] + ne.second == dists[ne.first] && preds[ne.first] > curr) {
          dists[ne.first] = dists[curr] + ne.second;
          to_search.erase(ne.first); to_search.insert(ne.first);
          preds[ne.first] = curr;
        }
      }
    }
  cout << 0 << endl;
  // Establish children in shortest path tree
    for (int i=1; i<n; i++) {
      children[preds[i]].push_back(i);
    }
  cout << 0 << endl;
  // DFS to find cow traffic through each field
    dfs();
  cout << 0 << endl;
  // Print
    fout << ans << endl;
    return 0;
}
