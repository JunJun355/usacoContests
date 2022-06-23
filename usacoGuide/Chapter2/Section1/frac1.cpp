/*
ID: 06jajun
TASK: frac1
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 50
#define INF 1000000000

int n;
ifstream fin ("frac1.in");
ofstream fout ("frac1.out");
vector<pair<int, int>> ans;

struct by_val {
  bool operator()(pair<int, int> const &a, pair<int, int> const &b) const {
    return static_cast<float>(a.first) / a.second < static_cast<float>(b.first) / b.second;
  }
};

int gcd(int a, int b) {
  int c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

int main() {
  fin >> n;
  ans.push_back({0, 1});
  ans.push_back({1, 1});
  for (int i=1; i <= n; i++) {
    for (int j=1; j < i; j++) {
      if (gcd(i, j) == 1) {
        ans.push_back({j, i});
      }
    }
  }
  // for (pair<int, int> x : ans) {
  //   cout << x.first << '/' << x.second << endl;
  // }
  sort(ans.begin(), ans.end(), by_val());
  for (pair<int, int> x : ans) {
    fout << x.first << '/' << x.second << endl;
  }
}
