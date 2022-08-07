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
int cdists[MXP] = {0};
int dists[MXP];
int cowps[MXN];
int paths[MXP][MXP];
vector<int> edges[MXP];
ifstream fin ("butter.in");
ofstream fout ("butter.out");

struct cmpA {
  bool operator() (int a, int b) const {
    if (cdists[a] == cdists[b]) return a < b;
    return cdists[a] < cdists[b];
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
      set<int, cmpA> sedges;
      for (int i=0; i<p; i++) cdists[i] = INF;
      cdists[cowps[i]] = 0;
      sedges.insert(cowps[i]);
      while (!sedges.empty()) {
        int nv = *(sedges.begin());
        sedges.erase(sedges.begin());
        for (auto ne : edges[nv]) {
          // cout << ne << endl;
          if (cdists[nv] + paths[nv][ne] < cdists[ne]) {
            sedges.erase(ne);
            cdists[ne] = cdists[nv] + paths[nv][ne];
            // cout << cdists[ne] << endl;
            sedges.insert(ne);
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
