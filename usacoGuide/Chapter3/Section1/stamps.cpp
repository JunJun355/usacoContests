/*
ID: 06jajun
TASK: stamps
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
#define INF 2010001

int k, n;
int stamps[MXN];
bool ms[INF];
int cs[INF];
ifstream fin ("stamps.in");
ofstream fout ("stamps.out");

int main() {
  fin >> k >> n;
  for (int i=0; i<n; i++) fin >> stamps[i];
  for (int i=0; i<INF; i++) {
    cs[i] = INF;
    ms[i] = false;
  }
  ms[0] = true;
  cs[0] = 0;
  for (int i=0; i<INF; i++) {
    // cout << i << ' ' << ms[i] << ' ' << cs[i] << endl;
    if (!ms[i]) {
      fout << i - 1 << endl;
      return 0;
    }
    if (cs[i] == k) continue;
    for (int j=0; j<n; j++) {
      ms[i + stamps[j]] = true;
      cs[i + stamps[j]] = min(cs[i] + 1, cs[i + stamps[j]]);
    }
  }
}
