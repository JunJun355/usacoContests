/*
ID: 06jajun
TASK: concom
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <string>

using namespace std;

#define MXN 101
#define INF 1e9

int m;
int direct_ownership[MXN][MXN];
int indirect_ownership[MXN][MXN];
ifstream fin ("concom.in");
ofstream fout ("concom.out");

int main() {
  fin >> m;
  for (int i=0; i<m; i++) {
    int f, s, p;
    fin >> f >> s >> p;
    if (p > 50) {
      direct_ownership[f][s] = 101;
      indirect_ownership[f][s] = p;
      continue;
    }
    direct_ownership[f][s] = p;
    indirect_ownership[f][s] = p;
  }
  for (int holder=0; holder<MXN; holder++) {
    for (int i=0; i<MXN; i++) {
      for (int j=0; j<MXN; j++) {
        if (indirect_ownership[j][i] > 50 && indirect_ownership[j][i] <= 100) {
          indirect_ownership[j][i] = 101;
          for (int k=0; k<MXN; k++) {
            indirect_ownership[j][k] += indirect_ownership[i][k];
          }
        }
      }
    }
  }
  for (int i=0; i<MXN; i++) {
    for (int j=0; j<MXN; j++) {
      if ((indirect_ownership[i][j] > 50 || direct_ownership[i][j] > 50) && (i != j)) fout << i << ' ' << j << endl;
    }
  }
}
