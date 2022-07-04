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

#define MXN 10001
#define INF 1e9

int v, n;
long long dp[MXN];
vector<int> coins;
ifstream fin ("money.in");
ofstream fout ("money.out");

int main() {
  fin >> v >> n;
  for (int i=0; i<v; i++) {
    int ne;
    fin >> ne;
    coins.push_back(ne);
  }
  dp[0] = 1;
  for (int coin:coins) {
    for (int i=coin; i<n+1; i++) {
      dp[i] += dp[i - coin];
    }
  }
  fout << dp[n] << endl;
}
