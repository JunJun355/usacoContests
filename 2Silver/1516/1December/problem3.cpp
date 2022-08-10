/*
ID: 06jajun
TASK: bcount
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 100000
#define INF 1000000000

int n, q;
int cows[MXN], prefix[MXN+1][3];
ifstream fin ("bcount.in");
ofstream fout ("bcount.out");

int main() {
  fin >> n >> q;
  for (int i=0; i<n; i++) {
    fin >> cows[i];
    cows[i]--;
    for (int j=0; j<3; j++) prefix[i+1][j] = prefix[i][j];
    prefix[i+1][cows[i]]++;
  }
  for (int i=0; i<q; i++) {
    int a, b;
    fin >> a >> b;
    for (int j=0; j<3; j++) {
      fout << prefix[b][j] - prefix[a-1][j];
      if (j!=2) fout << ' ';
      else fout << endl;
    }
  }
}
