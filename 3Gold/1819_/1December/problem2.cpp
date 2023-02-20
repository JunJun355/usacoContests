/*
ID: 06jajun
TASK: cowpatibility
LANG: C++17
*/

// * ->

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <string>

using namespace std;

#define MXN 50000
#define INF 1000000000

long long n;
int favs[MXN][5];
ifstream fin ("cowpatibility.in");
ofstream fout ("cowpatibility.out");

struct S5 {
  int n=0;
  int s[5];
};

bool operator< (const S5 &a, const S5 &b) {
  for (int i=0; i<5; i++) {
    if (a.s[i] < b.s[i]) return true;
    else if (a.s[i] > b.s[i]) return false;
  }
  return false;
}

int main() {
  // Get inputs
  fin >> n;
  for (int i=0; i<n; i++) {
    for (int j=0; j<5; j++) {
      fin >> favs[i][j];
    }
    sort(favs[i], favs[i]+5);
    // for (int j=0; j<5; j++) {
    //   cout << favs[i][j] << ' ';
    // }
    // cout << endl;
  }

  // Get subsets;
  map<S5, int> subs;
  for (int i=0; i<n; i++) {
    for (int j=1; j<32; j++) {
      S5 subset = {0, {0, 0, 0, 0, 0}};
      for (int k=0; k<5; k++) {
        if (j & (1 << k)) {
          subset.s[subset.n++] = favs[i][k];
        }
      }
      subs[subset]++;
    }
  }

  // Inclusion - Exclusion
  long long inc_ex[] = {+1, -1, +1, -1, +1, -1};
  long long ans = n * (n - 1) / 2;
  for (auto &x : subs) {
    // cout << x.second << ' ';
    // for (int i=0; i<x.first.n; i++) {
    //   cout << x.first.s[i] << ' ';
    // }
    // cout << endl;
    // int ne = x.second * (x.second - 1) / 2;
    // if (x.first.n % 2 == 0) {
    //   ans += ne;
    // } else {
    //   ans -= ne;
    // }
    ans += inc_ex[x.first.n] * x.second * (x.second - 1) / 2;
  }

  fout << ans << endl;
}
