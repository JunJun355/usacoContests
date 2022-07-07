/*
ID: 06jajun
TASK: agrinet
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <string>

using namespace std;

#define MXN 100
#define INF 1000000000

int n;
int edges[MXN][MXN];
ifstream fin ("agrinet.in");
ofstream fout ("agrinet.out");

struct cmpA {
  bool operator() (pair<int, int> a, pair<int, int> b) const {
    if (edges[a.first][a.second] == edges[b.first][b.second]) {
      if (a.first == b.first) return a.second < b.second;
      return a.first < b.first;
    }
    return edges[a.first][a.second] < edges[b.first][b.second];
  }
};

int main() {
  fin >> n;
  set<pair<int, int>, cmpA> queue;
  for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
    fin >> edges[i][j];
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cout << edges[i][j] << ' ';
    }
    cout << endl;
  }

  bool done[MXN]; for (int i=0; i<MXN; i++) done[i] = false;
  done[0] = true;
  set<int> searched;
  for (int j=1; j<n; j++) queue.insert(make_pair(0, j));
  int d=1, ans = 0;
  // if (n > 5) queue.insert(make_pair(2, 5));
  // if (n > 5) queue.insert(make_pair(3, 4));

  while (!queue.empty() && d < n) {
    // for (auto itr=queue.begin(); itr != queue.end(); itr++) cout << itr->first << '-' << itr-> second << ' ';
    // cout << endl;
    // for (int i=0; i<n; i++) cout << done[i] << ' ';
    // cout << endl;
    pair<int, int> curr = *queue.begin(); queue.erase(queue.begin());
    if (done[curr.second]) continue;
    ans += edges[curr.first][curr.second];
    done[curr.second] = true;
    d++;
    for (int j=0; j<n; j++) if (curr.second != j && !done[j]) {queue.insert(make_pair(curr.second, j));}
  }
  cout << (d < n) << endl;
  fout << ans << endl;
}
