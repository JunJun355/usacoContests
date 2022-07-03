/*
ID: 06jajun
TASK: nocows
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MOD 9901

int n,k;
int dp[201][101];
ifstream fin ("nocows.in");
ofstream fout ("nocows.out");

int main() {
  fin >> n >> k;
  for (int i=0; i <= 200; i++) for (int j=0; j <= 100; j++) dp[i][j] = 0;
  dp[1][1] = 1;

  for (int i=1; i <= n; i+=2){
    for (int j=2; j <= k; j++) {
      dp[i][j] = dp[i][j - 1];
      for (int x=0, y=i-1; 0 < y; x++, y--) {
        dp[i][j] += (dp[y][j - 1]*(dp[x][j - 1] - dp[x][j - 2]))%MOD;
      }
      for (int x=0, y=i-1; 0 < y; x++, y--) {
        dp[i][j] += (dp[y][j - 2]*(dp[x][j - 1] - dp[x][j - 2]))%MOD;
      }
      dp[i][j] = dp[i][j] % MOD;
    }
  }
  for (int i=0; i <= n; i++) {
    for (int j=0; j <= k; j++) {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  fout << (MOD + dp[n][k] - dp[n][k - 1]) % MOD << endl;
  return 0;
}
