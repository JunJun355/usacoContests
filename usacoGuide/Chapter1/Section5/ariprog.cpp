/*
ID: 06jajun
TASK: ariprog
LANG: C++17
*/

// * ->

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_set>

using namespace std;

#define MXN 125000
#define INF 1000000000
bool bisquares[MXN+1];
unordered_set<int> done;
int n, m;
vector<pair<int, int>> ans;

bool check(int s, int d) {
  for (int i=0; i<n; i++) {
    if (!bisquares[s + i*d]) return false;
  }
  return true;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

int main()
{
  ifstream fin ("ariprog.in");
  ofstream fout ("ariprog.out");
  fin >> n >> m;
  int top = 2 * m * m + 1;

  for (int p=0; p<=m; p++)
    for (int q=p; q<=m; q++)
      bisquares[p*p + q*q] = true;
  for (int p=0; p<=m; p++) for (int q=p; q<=m; q++) {
    int start = p*p + q*q;
    if (done.find(start) != done.end()) continue;
    done.insert(start);
    for (int diff=1; start + (n - 1) * diff < top; diff++) {
      if (check(start, diff)) ans.push_back({start, diff});
    }
  }
  sort(ans.begin(), ans.end(), cmp);
  for (auto x: ans) fout << x.first << ' ' << x.second << endl;
  if (ans.empty()) fout << "NONE" << endl;
}
