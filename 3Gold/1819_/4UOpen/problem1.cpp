/*
ID: 06jajun
TASK: snakes
LANG: C++17
*/

// * ->

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define INF 1000000000
#define MXN 400
#define MXK 399

int n, k, tot;
int snakes[MXN], dp[MXK+2][MXN+1];
ifstream fin ("snakes.in");
ofstream fout ("snakes.out");

int main() {
  // Get inputs
  fin >> n >> k;
  for (int i=0; i<n; i++) {
    fin >> snakes[i];
    tot += snakes[i];
  }

  // DP
  for (int i=1; i<=n; i++) dp[0][i] = INF;
  for (int i=1; i<=k+1; i++) {
    for (int j=0; j<=n; j++) {
      int mx = 0;
      dp[i][j] = INF;
      for (int k=j; k>=0; k--) {
        dp[i][j] = min(dp[i-1][k] + (j - k) * mx, dp[i][j]);
        if (k != 0) mx = max(snakes[k-1], mx);
      }
      // cout << dp[i][j] << ' ';
    }
    // cout << endl;
  }

  // Output
  fout << dp[k+1][n] - tot << endl;
  return 0;
}

/*
int n, k, tot;
int snakes[MXN], dp[MXK+3][MXN+1];
ifstream fin ("snakes.in");
ofstream fout ("snakes.out");

int main() {
  fin >> n >> k;
  for (int i=0; i<n; i++) {
    fin >> snakes[i];
  }
  for (int i=1; i<=n; i++) dp[0][i] = INF;
  for (int i=1; i<=k+2; i++) {
    for (int j=1; j<=n; j++) {
      dp[i][j] = dp[i - 1][j];
      cout << dp[i][j] << ' ';
      int mx = 0;
      for (int m=j; m>0; m--) {
        mx = max(mx, snakes[m - 1]);
        dp[i][j] = min(dp[i][j], dp[i - 1][m - 1] + mx * (j - m + 1));
      }
    }
    cout << endl;
  }
  int adj = 0;
  for (int i=0; i<n; i++) adj += snakes[i];
  fout << dp[k+1][n] - adj << endl;
}
*/
