/*
ID: 06jajun
TASK: fence
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 500
#define INF 1000000000

int f;
vector<int> stack;
vector<int> circuit;
vector<int> edges[MXN];
ifstream fin ("fence.in");
ofstream fout ("fence.out");

void recurse(int location) {
  while (!edges[location].empty()) {
    int ne = edges[location].back();
    edges[location].pop_back();
    edges[ne].erase(find(edges[ne].begin(), edges[ne].end(), location));
    recurse(ne);
  }
  circuit.push_back(location);
  return ;
}

int main() {
  fin >> f;
  for (int i=0; i<f; i++) {
    int a, b;
    fin >> a >> b;
    a--; b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  int start = 0;
  for (int i=MXN-1; i>-1; i--) {
    if (edges[i].size() % 2 == 1) {
      start = i;
    }
    sort(edges[i].rbegin(), edges[i].rend());
  }
  recurse(start);
  reverse(circuit.begin(), circuit.end());
  for (auto x : circuit) {
    fout << x+1 << endl;
  }
}
