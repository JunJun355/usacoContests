/*
ID: 06jajun
TASK: hamming
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 256
#define INF 1000000000

int n, b, d, top;
vector<int> ans;
int grid[MXN][MXN];
ifstream fin ("hamming.in");
ofstream fout ("hamming.out");

void recurse(int dep, int lo) {

  if (dep == n) {
    for (int j=0; j < n; j++) {
      fout << ans[j];
      if (j % 10 == 9) fout << endl;
      else if (j != n - 1) fout << ' ';
    }
    if (n % 10 != 0) fout << endl;
    exit(0);
  }
  bool gud;
  for (int ne=lo; ne < top; ne++) {
    gud = true;
    for (auto x: ans) {
      if (grid[x][ne] < d) {
        gud = false;
        break;
      }
    }
    if (gud) {
      ans.push_back(ne);
      recurse(dep + 1, ne + 1);
      ans.pop_back();
    }
  }
}

int main() {
  fin >> n >> b >> d;
  for (int i=0; i < MXN; i++) {
    for (int j=0; j < MXN; j++) {
      grid[i][j] = 0;
      for (int k=0; k < 8; k++) {
        grid[i][j] += ((i >> k) ^ (j >> k)) & 1;
        // cout << (((i << k) ^ (j << k)) & 1) << ' ' << (i >> k) << ' ' << (j >> k) << endl;
      }
    }
  }
  top = (1 << b);
  // for (int i=0; i < 10; i++) {
  //   for (int j=0; j < 10; j++) {
  //     cout << grid[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << grid[0][63];
  ans.push_back(0);
  recurse(1, 1);
}
