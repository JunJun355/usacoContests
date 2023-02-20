/*
ID: 06jajun
TASK: walk
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define INF 2019201997
#define MXN 7501

int n, k;
bool vis[MXN];
long long c[MXN];
const long long f=2019201913LL;
const long long s=2019201949LL;
const long long mod=2019201997;
ifstream fin ("walk.in");
ofstream fout ("walk.out");

void get_inputs() {
  fin >> n >> k;
}

long long edge(int a, int b) {
  if (a == b) return INF;
  return ((f * min(a, b)) % mod + (s * max(a, b)) % mod + mod) % mod;
}

void get_mst() {
  for (int i=0; i<=n; i++) {
    c[i] = INF;
  }
  for (int i=0; i<n; i++) {
    int min_j = 0;
    for (int j=1; j<=n; j++) {
      if (!vis[j] && (min_j == 0 || c[j] < c[min_j])) {
        min_j = j;
      }
    }
    vis[min_j] = true;

    for (int j=1; j<=n; j++) {
      if (!vis[j]) {
        c[j] = min(c[j], edge(min_j, j));
      }
    }
  }
}

int main() {
  get_inputs();

  get_mst();

  sort(c+1, c+n+1);

  fout << c[n - k + 1] << endl;
}
