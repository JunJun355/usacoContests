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
#include <vector>
#include <array>

using namespace std;

#define MAXN 2000
#define INF 1000000000
#define MOD 1000000007
#define FOR(i,b,t) for (int i=b; i<t; i++)

int T, B, N;
int ans = 0;
int ansarr[MAXN];


struct node {
  int lower, upper, lowup, uplow;
  vector<int> children = {};
};

node nodes[MAXN];

array<int,2> recurse(int r) {
  node root = nodes[r];
  int low = root.lower, high = root.upper;
  for (auto x: root.children) {
    array<int,2> ne = recurse(x);
    low = ne[0] > low ? ne[0] : low;
    high = high > ne[1] ? ne[1] : high;
    // cout << low << ' ' << high << endl;
  }
  if (high < low) {
    int middle = (high + low) / 2;
    if (middle < root.lower) {
      ans = ans < root.lower - high ? root.lower - high : ans;

    }
    else if (middle > root.upper) {
      ans = ans < low - root.upper ? low - root.upper : ans;
    }
    else {
      ans = ans < middle ? middle : ans;
    }
  }
  nodes[r].lowup = low;
  nodes[r].uplow = high;
  array<int,2> res = {low, high};
  return res;
}

int main() {
  cin >> T >> B;
  FOR(i,0,T) {
    cin >> N;
    FOR(j,1,N) {
      int par;
      cin >> par;
      nodes[par - 1].children.push_back(j);
    }
    FOR(j,0,N) {
      int low, high;
      cin >> low >> high;
      nodes[j].lower = low;
      nodes[j].upper = high;
      nodes[j].lowup = low;
      nodes[j].uplow = high;
    }
    // FOR(j,0,N) {
    //   cout << nodes[j].lower << ' ' << nodes[j].upper << ", ";
    //   for (auto x: nodes[j].children) cout << x << ' ';
    //   cout << endl;
    // }
    recurse(0);
    // cout << nodes[0].lowup << ' ' << nodes[0].uplow << ' ';
    if (nodes[0].lowup > nodes[0].uplow) {
      int middle = (nodes[0].lowup + nodes[0].uplow) / 2;
      if (middle < nodes[0].lower) {
        cout << nodes[0].lower - nodes[0].uplow;
      }
      else if (middle > nodes[0].upper) {
        cout << nodes[0].lowup - nodes[0].upper;
      }
      else {
        cout << nodes[0].lowup - middle;
      }
    }
    else cout << 0;
    cout << endl;

    FOR(i,0,N) {
      node ne;
      nodes[i] = ne;
    }
  }
  return 0;
}
