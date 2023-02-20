/*
ID: 06jajun
TASK: milkorder
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <queue>

using namespace std;

#define MXN 100000
#define INF 1000000000

int n, m;
int preds[MXN];
int order[MXN];
vector<int> succ[MXN];
vector<pair<int, int>> edges[MXN/2];
ifstream fin ("milkorder.in");
ofstream fout ("milkorder.out");

void showpq(priority_queue<int> gq)
{
    priority_queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

bool doable(int a) {
  priority_queue<int> q;
  // cout << a << endl;
  for (int i=0; i<n; i++) {
    preds[i] = 0;
    // cout << 0 << endl;
    succ[i].clear();
  }
  // cout << 1 << endl;
  for (int i=0; i<a; i++) {
    for (auto edge:edges[i]) {
      preds[edge.second]++;
      succ[edge.first].push_back(edge.second);
    }
  }
  // for (int i=0; i<n; i++) cout << preds[i] << ' ';
  // cout << endl;
  // for (int i=0; i<n; i++) {
  //   for (auto s:succ[i]) {
  //     cout << s << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // cout << 1 << endl;
  for (int i=0; i<n; i++) {
    if (preds[i] == 0) q.push(-i);
  }
  // cout << 1 << endl;
  for (int i=0; i<n; i++) {
    // showpq(q);
    if (q.empty()) return false;
    int ne = -q.top();
    q.pop();
    order[i] = ne;
    for (auto nv : succ[ne]) {
      preds[nv]--;
      if (preds[nv] == 0) q.push(-nv);
    }
    // for (int i=0; i<n; i++) cout << preds[i] << ' ';
  }
  // for (int i=0; i<n; i++) cout << order[i]+1 << ' ';
  // cout << endl;
  return true;
}

int main() {
  fin >> n >> m;
  for (int i=0; i<m; i++) {
    int k; fin >> k;
    int prev; fin >> prev; prev--;
    for (int j=0; j<k-1; j++) {
      int ne; fin >> ne; ne--;
      edges[i].push_back({prev, ne});
      prev = ne;
    }
  }
  // for (int i=0; i<m; i++) {
  //   for (auto edge:edges[i]) {
  //     cout << edge.first << ' ' << edge.second << endl;
  //   }
  // }
  // for (auto itr=edges.begin(); itr!= edges.end(); itr++) {
  //   auto edge = *itr;
  //   // cout << edge.first << ' ' << edge.second << endl;
  // }
  int lo=0;
  int hi=m+1;
  while (lo+1 < hi) {
    int mid = (lo+hi) / 2;
    if (doable(mid)) lo = mid;
    else hi = mid;
  }
  doable(lo);
  // cout << doable(lo);
  // cout << 2 << endl;
  for (int i=0; i<n-1; i++) fout << order[i]+1 << ' ';
  fout << order[n - 1] + 1 << endl;
}
