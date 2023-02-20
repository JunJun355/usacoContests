/*
ID: 06jajun
TASK: talent
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 250
#define MXW 1000
#define INF 1000000000000000000

int n, w;
long long dp[MXW + 1];
int weights[MXN], talents[MXN];
ifstream fin ("talent.in");
ofstream fout ("talent.out");

bool doable(int y) {
  for (int i=0; i<MXW+1; i++) {
    dp[i] = -INF;
  }
  dp[0] = 0;
  for (int i=0; i<n; i++) {
    long long value = (1000 * (long long)talents[i] - y * (long long)weights[i]);
    for (int j=w; j>=0; j--) {
      int ne = min(j+weights[i], w);
      if (dp[j] != -INF) dp[ne] = max(dp[ne], dp[j] + value);
    }
  }
  return dp[w] >= 0;
}

int main() {
  fin >> n >> w;
  for (int i=0; i<n; i++) {
    fin >> weights[i] >> talents[i];
  }

  int lo=0;
  int hi=(1000*250*1000) + 1;
  while (lo+1<hi) {
    int mid=(lo+hi) / 2;
    if (doable(mid)) lo = mid;
    else hi = mid;
  }
  fout << lo << endl;
}
