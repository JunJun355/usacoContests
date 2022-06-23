/*
ID: 06jajun
TASK: lamps
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 101
#define INF 1000000000

int n, c;
vector<bool> lights;
vector<int> on, off;
vector<vector<bool>> ans;
ifstream fin ("lamps.in");
ofstream fout ("lamps.out");

bool check() {
  for (int x : on) {
    if (lights[x] == false) return false;
  }
  for (int x : off) {
    if (lights[x] == true) return false;
  }
  return true;
}

void recurse(int d=0, int nf=0) {
  if (d == 0) {
    recurse(d + 1, nf);
    for (int i=0; i < MXN; i++) {
      lights[i] = not lights[i];
    }
    recurse(d + 1, nf + 1);
    for (int i=0; i < MXN; i++) {
      lights[i] = not lights[i];
    }
  }
  else if (d == 1) {
    recurse(d + 1, nf);
    for (int i=1; i < MXN; i+=2) {
      lights[i] = not lights[i];
    }
    recurse(d + 1, nf + 1);
    for (int i=1; i < MXN; i+=2) {
      lights[i] = not lights[i];
    }
  }
  else if (d == 2) {
    recurse(d + 1, nf);
    for (int i=0; i < MXN; i+=2) {
      lights[i] = not lights[i];
    }
    recurse(d + 1, nf + 1);
    for (int i=0; i < MXN; i+=2) {
      lights[i] = not lights[i];
    }
  }
  else if (d == 3) {
    recurse(d + 1, nf);
    for (int i=1; i < MXN; i+=3) {
      lights[i] = not lights[i];
    }
    recurse(d + 1, nf + 1);
    for (int i=1; i < MXN; i+=3) {
      lights[i] = not lights[i];
    }
  }
  else {
    // for (int i=0; i < MXN; i++) cout << lights[i];
    // cout << endl;
    if (nf <= c && (nf - c) % 2 == 0 && check()) {
      ans.push_back(lights);
    }
  }
}

bool cmp(vector<bool> lights1, vector<bool> lights2) {
  if (lights1[1] < lights2[1]) return true;
  else if (lights1[1] > lights2[1]) return false;
  else if (lights1[2] < lights2[2]) return true;
  else if (lights1[2] > lights2[2]) return false;
  else if (lights1[3] < lights2[3]) return true;
  else if (lights1[3] > lights2[3]) return false;
  else if (lights1[4] < lights2[4]) return true;
  else if (lights1[4] > lights2[4]) return false;
  return true;
}

int main() {
  fin >> n >> c;
  int ne;
  fin >> ne;
  while (ne > 0) {
    on.push_back(ne);
    fin >> ne;
  }
  fin >> ne;
  while (ne > 0) {
    off.push_back(ne);
    fin >> ne;
  }
  for (int i=0; i < MXN; i++) lights.push_back(true);
  recurse();
  if (ans.size() == 0) fout << "IMPOSSIBLE" << endl;
  sort(ans.begin(), ans.end(), cmp);
  for (auto line: ans) {
    for (int i=1; i < n + 1; i++) {
      fout << line[i];
    }
    fout << endl;
  }
  return 0;
}
