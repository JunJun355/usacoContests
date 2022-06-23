/*
ID: 06jajun
TASK: holstein
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXV 25
#define MXG 15
#define INF 1000000000

int v, g;
ifstream fin ("holstein.in");
ofstream fout ("holstein.out");

int reqs[MXV];
int vits[MXG][MXV];
int best = MXV;
vector<int> ans;
vector<int> curr;

void recurse(int dep) {
  if (curr.size() == best) return;
  if (dep == g) {
    int t = 0;
    for (int i=0; i < v; i++) if (reqs[i] <= 0) t++;
    if (best > curr.size() && t == v) {
      best = curr.size();
      ans = curr;
    }
    return;
  }
  curr.push_back(dep);
  for (int i=0; i < v; i++)
    reqs[i] -= vits[dep][i];
  recurse(dep + 1);
  curr.pop_back();
  for (int i=0; i < v; i++)
    reqs[i] += vits[dep][i];
  recurse(dep + 1);
}

int main() {
  for (int i=0; i < MXV; i++) ans.push_back(i);

  fin >> v;
  for (int i=0; i < v; i++) {
    fin >> reqs[i];
  }
  fin >> g;
  for (int i=0; i < g; i++) for (int j=0; j < v; j++)
    fin >> vits[i][j];
  recurse(0);
  fout << best;
  for (int i=0; i < best; i++) {
    fout << ' ' << ans[i] + 1;
  }
  fout << endl;
}
