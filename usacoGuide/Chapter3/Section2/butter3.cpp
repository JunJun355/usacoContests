/*
ID: 06jajun
TASK: butter
LANG: C++17
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MXN 500
#define MXP 800
#define MXC 1450
#define INF 1000000

int n, p, c;
int dists[MXP];
int cowps[MXN];
int paths[MXP][MXP];
vector<int> edges[MXP];
ifstream fin ("butter.in");
ofstream fout ("butter.out");

struct cmpA {
  bool operator() (pair<int, int> a, pair<int, int> b) const {
    if (paths[a.first][a.second] == paths[b.first][b.second]) {
      if (a.first == b.first) {
        return a.second < b.second;
      }
      return a.first < b.first;
    }
    return paths[a.first][a.second] < paths[b.first][b.second];
  }
};

int main() {
    // Get inputs
    fin >> n >> p >> c;
    for (int i=0; i<n; i++) {
      int ne;
      fin >> ne;
      cowps[i] = ne-1;
    }
    for (int i=0; i<MXP; i++) for (int j=0; j<MXP; j++) {
      paths[i][j] = INF;
    }
    for (int i=0; i<MXP; i++) {
      dists[i] = 0;
      paths[i][i] = 0;
    }
    for (int i=0; i<c; i++) {
      int a, b, d;
      fin >> a >> b >> d;
      a--; b--;
      paths[a][b] = d;
      paths[b][a] = d;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }

    // find dists between
    for (int i=0; i < n; i++) {
      set<pair<int, int>> sedges;
      int cdists[MXP];
      for (int i=0; i<MXP; i++) cdists[i] = INF;
      // memset(cdists, INF, sizeof(cdists));
      cdists[cowps[i]] = 0;
      sedges.insert({0, cowps[i]});
      while (!sedges.empty()) {
        int ne = sedges.begin()->second;
        sedges.erase(sedges.begin());
        for (auto nv : edges[ne]) {
          // cout << nv << endl;
          if (cdists[ne] + paths[ne][nv] < cdists[nv]) {
            // cout << nv << endl;
            sedges.erase({cdists[nv], nv});
            cdists[nv] = cdists[ne] + paths[ne][nv];
            sedges.insert({cdists[nv], nv});
          }
        }
      }
      for (int i=0; i<p; i++) {
        dists[i] += cdists[i];
      }
    }
    int m=INF;
    for (int i=0; i<p; i++) {
      if (dists[i] < m) m = dists[i];
    }

    fout << m << endl;
}
