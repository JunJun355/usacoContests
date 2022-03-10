#include <iostream>
#include <unordered_map>
#include <tuple>
#include <array>
#include <vector>
using namespace std;

int n, px, py;
int m;
unordered_map<long, vector<int>> all;
vector<int> res;

void recursea(int i, int x, int y, int k, int instructions[40][2]) {
  if (i == m) {
    long check = (px - x) * 1000000000 + py - y;
    all[check].push_back(k);
  }
  else {
    int nx = instructions[i][0];
    int ny = instructions[i][1];
    recursea(i + 1, x + nx, y + ny, k + 1, instructions);
    recursea(i + 1, x, y, k, instructions);
  }
}

void recurseb(int i, int x, int y, int k, int instructions[40][2]) {
  if (i == n) {
    long check = 1000000000 * x + y;
    for (auto j: all[check]) res[j + k] += 1;
  }
  else {
    int nx = instructions[i][0];
    int ny = instructions[i][1];
    recurseb(i + 1, x + nx, y + ny, k + 1, instructions);
    recurseb(i + 1, x, y, k, instructions);
  }
}

int main() {
  cin >> n >> px >> py;
  m = n / 2;
  int instructions[40][2];
  for (int i=0; i<n; i++) {
    cin >> instructions[i][0] >> instructions[i][1];
  }
  for (int i=0; i<n; i++) {
    res.push_back(0);
  }

  recursea(0, 0, 0, 0, instructions);

  recurseb(m, 0, 0, -1, instructions);
  for (auto x: res) {
    cout << x << endl;
  }
}
