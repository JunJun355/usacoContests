/*
ID: 06jajun
TASK: numtri
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

#define MXN 1001
#define INF 101

int n;
int triangle[MXN][MXN];
int ans[MXN][MXN];

int main() {
  ifstream fin ("numtri.in");
  ofstream fout ("numtri.out");
  fin >> n;
  for (int i=0; i< n; i++) {
    for (int j=0; j <= i; j++) {
      fin >> triangle[i][j];
    }
  }

  for (int i=n - 1; i >= 0; i--) {
    for (int j=0; j <= i; j++) {
      ans[i][j] = triangle[i][j] + max(ans[i + 1][j], ans[i + 1][j + 1]);
    }
  }
  for (int i=0; i< n; i++) {
    for (int j=0; j <= i; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
  fout << ans[0][0] << endl;
}
