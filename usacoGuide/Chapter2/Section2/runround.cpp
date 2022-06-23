/*
ID: 06jajun
TASK: runround
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

int m;
ifstream fin ("runround.in");
ofstream fout ("runround.out");

bool check(int x) {
  string xs = to_string(x);
  bool there[9];
  int tot = 0;
  for (int i=0; i < 9; i++) there[i] = true;
  int curr = 0;
  int currc = xs[0] - 48;
  while (there[curr]) {
    curr = (curr + currc) % xs.length();
    currc = xs[curr] - 48;
    tot++;
  }
  if (curr == 0 && tot == xs.length()) {
    return true;
  }
  return false;
}

vector<int> roundnums(int x=0) {
  vector<int> ret;
  if (x > m) {
    if (check(x))
      ret.push_back(x);
    return ret;
  }
  x = x * 10;
  for (int i=1; i < 10; i++) {
    x++;
    for (auto r : roundnums(x)) ret.push_back(r);
  }
  return ret;
}

int main() {
  fin >> m;
  vector<int> ans = roundnums();
  sort(ans.begin(), ans.end());
  int bot = 0, top = ans.size() - 1;
  int end = top;
  int middle;
  while (bot <= top) {
    middle = (bot + top) / 2;
    if (ans[middle] < m) {
      bot = middle + 1;
    }
    else if (ans[middle] >= m) {
      end = middle;
      top = middle - 1;
    }
  }
  fout << ans[end] << endl;
}
