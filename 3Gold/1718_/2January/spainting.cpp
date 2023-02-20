#include <iostream>
#include <algorithm>
#include <set>
#include <fstream>
#include <iostream>

using namespace std;

#define MAXN 1000001
#define INF 1000000000
#define MOD 1000000007
#define FOR(i,b,t) for (int i=b; i<t; i++)

// * ->

int N,M,K;
long int dp[MAXN];



int main()
{
  ifstream fin ("spainting.in");
  ofstream fout ("spainting.out");
  fin >> N >> M >> K;
  long int curr = 1;
  long int acc = 0;
  FOR(i,0,K - 1) {
    curr *= M;
    curr %= MOD;
    dp[i] = curr;
    acc += curr;
    acc %= MOD;
  }
  acc *= (M - 1);
  acc %= MOD;
  FOR(i,K - 1,N) {
    dp[i] = acc % MOD;
    acc -= dp[i - K + 1] * (M - 1) % MOD;
    acc %= MOD;
    acc += dp[i] * (M - 1) % MOD;
    acc %= MOD;
  }
  long int tot = 1;
  FOR(i,0,N) {
    tot *= M;
    tot %= MOD;
  }
  fout << (tot - dp[N - 1]) % MOD;

}
