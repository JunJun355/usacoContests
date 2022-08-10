/*
ID: 06jajun
TASK: highcard
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

int n, ans=0;
bool cards[MXN];
ifstream fin ("highcard.in");
ofstream fout ("highcard.out");

int main() {
  fin >> n;
  for (int i=0; i<MXN; i++) cards[i] = false;
  for (int i=0; i<n; i++) {
    int ne; fin >> ne;
    cards[ne-1] = true;
  }
  int b=2*n-1;
  int e=2*n-1;
  while (cards[b] && b>=0) b--;
  while (!cards[e] && e>=0) e--;
  cout << b << ' ' << e;
  while (e>=0) {
    if (b > e) {
      b--;
      while (cards[b] && b>=0) b--;
      ans++;
    }
    e--;
    while (!cards[e] && e>=0) e--;
  }
  fout << ans << endl;
}
