/*
ID: 06jajun
TASK: lightson
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <set>

using namespace std;

#define MXN 100
#define INF 1000000000

int n, m, ans=0;
bool on[MXN][MXN];
set<pair<int, int>> searched;
vector<pair<int, int>> to_search;
vector<pair<int, int>> control[MXN][MXN];
ifstream fin ("lightson.in");
ofstream fout ("lightson.out");

int main() {
  // Get inputs
  fin >> n >> m;
  for (int i=0; i<MXN; i++) for (int j=0; j<MXN; j++) {
    on[i][j] = false;
  }
  on[0][0] = true;
  to_search.push_back(make_pair(0, 0));
  searched.insert(make_pair(0, 0));
  for (int i=0; i<m; i++) {
    int x, y, a, b;
    fin >> x >> y >> a >> b;
    x--;y--;a--;b--;
    control[x][y].push_back(make_pair(a, b));
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cout << control[i][j].size() << ' ';
    }
    cout << endl;
  }
  while (!to_search.empty()) {
    ans++;
    pair<int, int> curr = to_search.back();
    to_search.pop_back();
    int x=curr.first; int y=curr.second;
    cout << x << ' ' << y << endl;
    if (x>0) {
      int na=x-1; int nb=y;
      if (on[na][nb] && searched.find({na, nb}) == searched.end()) {
        to_search.push_back({na, nb});
        searched.insert({na, nb});
      }
    } if (x<n-1) {
      int na=x+1; int nb=y;
      if (on[na][nb] && searched.find({na, nb}) == searched.end()) {
        to_search.push_back({na, nb});
        searched.insert({na, nb});
      }
    } if (y>0) {
      int na=x; int nb=y-1;
      if (on[na][nb] && searched.find({na, nb}) == searched.end()) {
        to_search.push_back({na, nb});
        searched.insert({na, nb});
      }
    } if (y<n-1) {
      int na=x; int nb=y+1;
      if (on[na][nb] && searched.find({na, nb}) == searched.end()) {
        to_search.push_back({na, nb});
        searched.insert({na, nb});
      }
    }
    cout << control[x][y].size() << endl;
    for (auto newon : control[x][y]) {
      if (searched.find(newon) != searched.end()) continue;
      int a=newon.first; int b=newon.second;
      cout << '\t' << a << ' ' << b << endl;
      on[a][b] = true;
      if (a>0) {
        int na=a-1; int nb=b;
        if (searched.find({na, nb}) != searched.end()) {
          to_search.push_back(newon);
          searched.insert(newon);
          continue;
        }
      } if (a<n-1) {
        int na=a+1; int nb=b;
        if (searched.find({na, nb}) != searched.end()) {
          to_search.push_back(newon);
          searched.insert(newon);
          continue;
        }
      } if (b>0) {
        int na=a; int nb=b-1;
        if (searched.find({na, nb}) != searched.end()) {
          to_search.push_back(newon);
          searched.insert(newon);
          continue;
        }
      } if (b<n-1) {
        int na=a; int nb=b+1;
        if (searched.find({na, nb}) != searched.end()) {
          to_search.push_back(newon);
          searched.insert(newon);
          continue;
        }
      }
    }
  }
  ans = 0;
  for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (on[i][j]) ans++;
  fout << ans << endl;
}
