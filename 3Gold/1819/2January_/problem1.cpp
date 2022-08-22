/*
ID: 06jajun
TASK: poetry
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 5000
#define MXM 100000
#define MXK 5000
#define INF 1000000000
#define MOD 1000000007

long long ans=1;
int n, m, k, x;
long long dp[MXK+1];
long long last[MXN];
int count_pat[26];
int count_len[MXK+1];
int count_syl[MXK+1][MXN];
long long curr[MXN];
unordered_map<int, int> conv;
unordered_map<char, int> conv_pat;
ifstream fin ("poetry.in");
ofstream fout ("poetry.out");

long long exp(int base, int power){
   if(power == 0) return 1;
   if(power == 1) return (base + MOD) % MOD;
   long long ans = exp(base,power/2);
   ans = (ans * ans + MOD) % MOD;
   if(power%2 == 1) ans = (ans*base + MOD) % MOD;
   return (ans + MOD) % MOD;
}

long long p(int a) {
  long long ba=0;
  for (int i=0; i<n; i++) {
    // for (int j=x; j<a; j++) {
    //   curr[i] *= (long long)last[i];
    //   curr[i] %= MOD;
    // }
    // ba += curr[i];
    ba += exp(last[i], a);
    ba %= MOD;
  }
  x = a;
  return ba;
}

int main() {
  fin >> n >> m >> k;
  int t=0;
  for (int i=0; i<n; i++) {
    int a, b; fin >> a >> b;
    if (a > k) continue;
    count_len[a]++;
    if (conv.find(b) == conv.end()) {
      conv[b] = t++;
    }
    count_syl[a][conv[b]]++;
    curr[i] = 1;
  }
  int s=0;
  for (int i=0; i<m; i++) {
    char a; fin >> a;
    if (conv_pat.find(a) == conv_pat.end()) {
      conv_pat[a] = s++;
    }
    count_pat[conv_pat[a]]++;
  }
  dp[0] = 1;
  for (int i=0; i<k; i++) {
    for (int j=0; i+j<k; j++) {
      dp[i+j] += (dp[i] * count_len[j]) % MOD;
      dp[i+j] %= MOD;
    }
    for (int j=0; j<n; j++) {
      last[j] += (dp[i] * count_syl[k-i][j]) % MOD;
      last[j] %= MOD;
    }
  }
  sort(count_pat, count_pat + s);
  x = 0;
  for (int i=0; i<s; i++) {
    ans *= p(count_pat[i]);
    ans %= MOD;
  }
  fout << ans << endl;
}
