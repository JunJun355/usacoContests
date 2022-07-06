/*
ID: 06jajun
TASK: comehome
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <string>

using namespace std;

#define MXN 52
#define INF 1000000000

int p;
int dists[MXN][MXN];
int from_barn[MXN];
ifstream fin ("comehome.in");
ofstream fout ("comehome.out");

int ci(char c) {
  if (c <= 90) return c-65;
  return c-71;
}

char ic(int i) {
  if (i <= 25) return i+65;
  return i+71;
}

struct cmpA {
  bool operator() (int a, int b) const {
    return from_barn[a] < from_barn[b];
  }
};

int main() {
  // Set-up
  for (int i=0; i<MXN; i++) {
    for (int j=0; j<MXN; j++) {
      dists[i][j] = INF;
    }
    from_barn[i] = INF;
  }
  fin >> p;
  for (int i=0; i<p; i++) {
    char a, b; int d;
    fin >> a >> b >> d;
    dists[ci(a)][ci(b)] = min(dists[ci(a)][ci(b)], d);
    dists[ci(b)][ci(a)] = min(dists[ci(b)][ci(a)], d);
    if (a == 'Z') from_barn[ci(b)] = min(from_barn[ci(b)], d);
    else if (b == 'Z') from_barn[ci(a)] = min(from_barn[ci(a)], d);
  }
  cout << 1 << endl;
  // BFS
  set<int, cmpA> to_search;
  set<int> searched;
  for (int i=0; i<MXN; i++) to_search.insert(i);
  searched.insert(25);
  cout << 2 << endl;
  while (!to_search.empty() && from_barn[*to_search.begin()] < INF) {
    int curr = *to_search.begin(); to_search.erase(curr); searched.insert(curr);
    if (curr < 25) {
      cout << 3 << endl;
      fout << ic(curr) << ' ' << from_barn[curr] << endl;
      return 0;
    }
    cout << curr << endl;
    for (int i=0; i<MXN; i++) {
      if (dists[curr][i] < INF && searched.find(i) == searched.end()) {
        to_search.erase(i);
        from_barn[i] = min(from_barn[i], from_barn[curr] + dists[curr][i]);
        to_search.insert(i);
      }
    }
  }
  return 0;
}
