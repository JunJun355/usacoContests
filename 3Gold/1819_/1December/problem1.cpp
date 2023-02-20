/*
ID: 06jajun
TASK: dining
LANG: C++17
*/

// * ->

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <queue>

using namespace std;

#define MXN 50001
#define MXM 100001
#define INF 1000000000

int n, m, k;
int dists[MXN];
int ydists[MXN];
bool ans[MXN]={false};
vector<pair<int, int>> edges[MXN];
vector<pair<int, int>> haybales;
ifstream fin ("dining.in");
ofstream fout ("dining.out");

struct cmpA {
  bool operator() (int a, int b) const {
    if (dists[a] == dists[b]) {
      return a < b;
    }
    return dists[a] < dists[b];
  }
};

struct cmpB {
  bool operator() (int a, int b) const {
    if (ydists[a] == ydists[b]) {
      return a < b;
    }
    return ydists[a] < ydists[b];
  }
};

int main() {
  // Get inputs
  fin >> n >> m >> k;
  for (int i=0; i<m; i++) {
    int a, b, d;
    fin >> a >> b >> d; a--; b--;
    edges[a].push_back({b, d});
    edges[b].push_back({a, d});
  }
  for (int i=0; i<k; i++) {
    int ne, del;
    fin >> ne >> del; ne--;
    haybales.push_back({ne, del});
  }

  // Initial Dijkstra's
  for (int i=0; i<MXN; i++) dists[i] = INF;
  dists[n-1] = 0;
  set<int, cmpA> to_search;
  to_search.insert(n-1);
  while (!to_search.empty()) {
    int curr = *to_search.begin();
    to_search.erase(to_search.begin());
    for (auto ne : edges[curr]) {
      int nv = ne.first; int d = ne.second;
      if (dists[nv] > dists[curr] + d) {
        dists[nv] = dists[curr] + d;
        to_search.insert(nv);
      }
    }
  }
  // for (int i=0; i<n; i++) {
  //   cout << dists[i] << ' ';
  // }
  // cout << endl;

  // New Dijkstra Setup
  for (int i=0; i<MXN; i++) ydists[i] = INF;
  // edges[n-1].clear();
  // cout << edges[n-1].size() << endl;
  // cout << 0 << endl;
  for (auto haybale : haybales) {
    int ne=haybale.first; int y=haybale.second;
    edges[n].push_back({ne, dists[ne] - y});
  }
  // // cout << 1 << endl;
  // for (int i=0; i<n-1; i++) {
  //   // cout << i << endl;
  //   if (edges[i].empty()) continue;
  //   vector<pair<int, int>> pl = edges[i];
  //   edges[i].clear();
  //   for (pair<int, int> ne : pl) {
  //     if (ne.first != n - 1) {
  //       edges[i].push_back(ne);
  //     }
  //   }
  // }
  // cout << 2 << endl;
  // New Dijkstra
  set<int, cmpB> yto_search;
  ydists[n] = 0;
  yto_search.insert(n);
  while (!yto_search.empty()) {
    int curr = *yto_search.begin(); yto_search.erase(yto_search.begin());
    // cout << curr << ' ';
    for (auto ne : edges[curr]) {
      int nv = ne.first; int d = ne.second;
      if (ydists[nv] > ydists[curr] + d) {
        ydists[nv] = ydists[curr] + d;
        if (ydists[nv] <= dists[nv]) ans[nv] = true;
        yto_search.insert(nv);
      }
    }
  }
  // for (int i=0; i<n; i++) cout << ydists[i] << ' ';
  for (int i=0; i<n-1; i++) {
    fout << ans[i] << endl;
  }
}
