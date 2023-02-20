/*
ID: 06jajun
TASK: teamwork
LANG: C++17
*/

// * ->

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 10000
#define INF 1000000000

int n, k;
int lvls[MXN];
int dp[MXN];
ifstream fin ("teamwork.in");
ofstream fout ("teamwork.out");

int main() {
  // Get inputs
  fin >> n >> k;
  for (int i=0; i<n; i++) {
    fin >> lvls[i];
    // dp[i] = 0;
  }

  // dp
  // int dp[MXN];
  dp[0] = lvls[0];
  for (int i=1; i<n; i++) {
    int mx=lvls[i];
    for (int j=0; i-j >= 0 && j<k; j++) {
      mx = max(lvls[i-j], mx);
      if (i == j) dp[i] = max(dp[i], mx * (j + 1));
      else dp[i] = max(dp[i], dp[i - j - 1] + mx * (j + 1));
    }
    // cout << dp[i] << endl;
  }
  fout << dp[n - 1] << endl;
}
