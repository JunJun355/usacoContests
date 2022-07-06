/*
ID: 06jajun
TASK: cowtour
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

#define MXN 150
#define INF 1000000000

struct Coor {
  int x, y;
};

int n, I=0;
bool edges[MXN][MXN];
double dists[MXN][MXN];
vector<Coor> coors;
double dias[MXN];
double mdias[MXN];
ifstream fin ("cowtour.in");
ofstream fout ("cowtour.out");

struct cmpA {
  bool operator()(int a, int b) const {
    return dists[I][a] < dists[I][b];
  }
};

double dist(Coor c1, Coor c2) {
  return sqrt((c1.x-c2.x)*(c1.x-c2.x) + (c1.y-c2.y)*(c1.y-c2.y));
}

int main() {
  // Get and format inputs
  fin >> n;
  for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
    if (i == j) {
      dists[i][j] = 0;
      continue;
    }
    dists[i][j] = INF;
  }
  for (int i=0; i<n; i++) {
    Coor ne;
    int x, y;
    fin >> x >> y;
    ne.x=x;ne.y=y;
    coors.push_back(ne);
    dias[i] = 0;
    mdias[i] = 0;
  }
  for (int i=0; i<n; i++) {
    string ne;
    fin >> ne;
    for (int j=0; j<n; j++) {
      edges[i][j] = ne[j] == '1';
      // cout << ne[j];
      if (edges[i][j]) {
        dists[i][j] = dist(coors[i], coors[j]);
        // cout << i << ' ' << j << ' ' << edges[i][j] << endl;
      }
    }
    // cout << endl;
  }

  // Dijk
  for (I=0; I<n; I++) {
    set<int, cmpA> to_search;
    set<int> searched;
    for (int i=0; i<n; i++) {
      to_search.insert(i);
    }
    // cout << *to_search.begin() << endl;
    while (dists[I][*to_search.begin()] < INF && !to_search.empty()) {
      int curr = *to_search.begin();
      // cout << curr << ' ' << dists[I][*to_search.begin()] << '-';
      to_search.erase(curr);
      searched.insert(curr);
      dias[I] = max(dias[I], dists[I][curr]);
      for (int j=0; j<n; j++) {
        if (edges[curr][j] && searched.find(j) == searched.end()) {
          if (dists[I][curr] + dists[curr][j] < dists[I][j]) {
            to_search.erase(j);
            dists[I][j] = dists[I][curr] + dists[curr][j];
            to_search.insert(j);
          }
        }
      }
    }
    // cout << endl;
  }

  for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
    if (dists[i][j] < INF || i == j) mdias[i] = max(mdias[i], dias[j]);
  }
  double ans = INF;
  for (int f=0; f<n; f++) for (int g=f+1; g<n; g++) {
    if (edges[f][g] || dists[f][g] < INF || f == g) continue;
    // cout << f << ' ' << g << endl;
    double nans = dias[f] + dist(coors[f], coors[g]) + dias[g];
    nans = max(nans, mdias[f]);
    nans = max(nans, mdias[g]);
    // cout << nans << ' ' << mdias[f] << ' ' << g << endl;
    ans = min(ans, nans);
  }
  fout << fixed;
  fout << setprecision(6);
  fout << ans << endl;
}
