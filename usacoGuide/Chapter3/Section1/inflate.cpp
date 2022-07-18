/*
ID: 06jajun
TASK: inflate
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 10000
#define MXM 10000
#define INF 1e9

int m, n;
int points[MXM];
pair<int, int> cats[MXN];
ifstream fin ("inflate.in");
ofstream fout ("inflate.out");

int main() {
  fin >> m >> n;
  for (int i=0; i<n; i++) {
    fin >> cats[i].first >> cats[i].second;
  }
  int maxi=0;
  for (int i=0; i<=m; i++) points[i] = 0;
  for (int i=0; i<=m; i++) {
    if (points[i]==0 && i > 0) continue;
    maxi = max(maxi, points[i]);
    for (int j=0; j<n; j++) {
      if (i+cats[j].second <= m) {
        points[i+cats[j].second] = max(points[i+cats[j].second], points[i] + cats[j].first);
      }
    }
  }
  fout << maxi << endl;
}
