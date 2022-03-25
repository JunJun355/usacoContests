#include <iostream>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

#define MAXN 100000
#define MAXB 100000
#define INF 1000000000
#define FOR(i,b,t) for (int i=b; i<t; i++)
#define ROR(i,t,b) for (int i=t; i>b; i--)

// * ->

int N,B;
int tiles[MAXN], depths[MAXN];
int boots[MAXB], b_depths[MAXB], b_steps[MAXB];

bool t_cmp(int a, int b) {
  return depths[a] > depths[b];
}

bool b_cmp(int a, int b) {
  return b_depths[a] > b_depths[b];
}

int nxt[MAXN + 2], prv[MAXN + 2];
int ans[MAXB];

int main()
{
  ifstream fin ("snowboots.in");
  ofstream fout ("snowboots.out");
  fin >> N >> B;
  int depth;
  FOR(i,0,N) {
    tiles[i] = i;
    fin >> depth;
    depths[i] = depth;
    nxt[i] = i + 1;
    prv[i + 2] = i + 1;
  }
  int bd, bs;
  FOR(i,0,B) {
    boots[i] = i;
    fin >> bd >> bs;
    b_depths[i] = bd, b_steps[i] = bs;
  }
  sort(tiles, tiles + N, t_cmp);
  sort(boots, boots + B, b_cmp);
  // FOR(i,0,N) cout << tiles[i] << ' ';
  // cout << endl;
  // FOR(i,0,B) cout << boots[i] << ' ';
  // cout << endl;
  // FOR(i,0,B) cout << b_depths[i] << ' ';
  // cout << endl;
  // FOR(i,0,N + 2) cout << nxt[i] << ' ';
  // cout << endl;
  // FOR(i,0,N + 2) cout << prv[i] << ' ';
  // cout << endl;
  int max_steps = 1;
  int boot;
  int j = 0;
  FOR(i,0,B) {
    boot = boots[i];
    // cout << boot << ' ' << b_depths[boot] << ' ' << b_steps[boot] << ' ' << j << ' ' << max_steps << endl;
    // FOR(i,0,N + 2) cout << nxt[i] << ' ';
    // cout << endl;
    // FOR(i,0,N + 2) cout << prv[i] << ' ';
    // cout << endl;
    while (depths[tiles[j]] > b_depths[boot]) {
      nxt[prv[tiles[j] + 1]] = nxt[tiles[j] + 1];
      prv[nxt[tiles[j] + 1]] = prv[tiles[j] + 1];
      if (max_steps < nxt[tiles[j] + 1] - prv[tiles[j] + 1]) max_steps = nxt[tiles[j] + 1] - prv[tiles[j] + 1];
      j++;
    }
    if (b_steps[boot] < max_steps) ans[boot] = 0;
    else ans[boot] = 1;
  }
  FOR(i,0,B) {
    fout << ans[i] << endl;
  }
}
