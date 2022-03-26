/*
ID: 06jajun
TASK: test
LANG: C++17
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#define MAXN 1000001
#define INF 1000000000
#define MOD 1000000007
#define FOR(i,b,t) for (int i=b; i<t; i++)

struct thing {
  int q, t, x, n, back, forward=INT_MAX;
};

struct cmpA {
  bool operator()(thing one, thing two) const
  {
    return one.forward < two.forward;
  }
};

int N;
thing things[MAXN + 1];
multiset<thing,cmpA> cows;

bool cmpB(thing A, thing B) {
  if (A.back == B.back) {
    if (A.q != B.q) return A.q < B.q;
    return A.x < B.x;
  }
  else return A.back < B.back;
}

int main() {
  cin >> N;
  FOR(i,0,N) {
    cin >> things[i].q >> things[i].t >> things[i].x >> things[i].n;
    things[i].back = things[i].x + things[i].t;
    things[i].forward = things[i].x - things[i].t;
  }
  sort(things, things + N, cmpB);
  // FOR(i,0,N) cout << things[i].t << endl;
  int ans = 0;
  FOR(i,0,N) {
    thing ne = things[i];
    if (ne.q == 1) cows.insert(ne);
    else {
      while (ne.n > 0 and cows.size() > 0) {
        multiset<thing,cmpA>::iterator itC = cows.lower_bound(ne);
        if (itC == cows.end()) break;
        thing cow = *itC;
        // cout << cows.size() << ' ' << cow.n << ' '  << ne.n << endl;
        if (cow.forward >= ne.forward) {
          int lo = cow.n < ne.n ? cow.n : ne.n;
          // cout << lo << endl;
          cow.n -= lo;
          ne.n -= lo;
          ans += lo;
          if (cow.n == 0) cows.erase(itC);
        }
        else break;
      }
    }
  }
  cout << ans;
  return 0;
}
