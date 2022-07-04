/*
ID: 06jajun
TASK: money
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 1e3+1
#define INF 1e9

int v, n;
vector<int> coins;
ifstream fin ("money.in");
ofstream fout ("money.out");

int recurse(int i=0, int tot=0) {
  if (tot == n) return 1;
  else if (tot > n) return 0;
  else if (i >= v) return 0;
  else if (i == v - 1) {
    if ((n - tot) % coins[i] == 0) return 1;
    else return 0;
  }

  int ans=0;
  while (tot <= n) {
    ans += recurse(i+1, tot);
    tot += coins[i];
  }
  return ans;
}

int main() {
  fin >> v >> n;
  for (int i=0; i<v; i++) {
    int ne;
    fin >> ne;
    coins.push_back(ne);
  }
  sort(coins.begin(), coins.end());
  reverse(coins.begin(), coins.end());
  fout << recurse() << endl;

}
