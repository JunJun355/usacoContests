#include <iostream>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

#define MAXN 100000
#define INF 1000000000
#define FOR(i,b,t) for (int i=b; i<t; i++)

// * ->

long n, m;
long bales[MAXN][2];


int main() {
  ifstream fin ("hayfeast.in");
  ofstream fout ("hayfeast.out");
  fin >> n >> m;
  FOR(i,0,n) {
    fin >> bales[i][0] >> bales[i][1];
  }
  long res = INF;
  multiset<long> spices;
  int back = 0, front = 0;
  long sum = 0;
  while (1) {
    // for (multiset<long>::iterator itr=spices.begin(); itr != spices.end(); itr++)
    //   cout << *itr;
    if (sum < m) {
      if (front == n) break;
      sum += bales[front][0];
      spices.insert(bales[front][1]);
      front++;
    }
    else {
      if (res > *spices.rbegin()) {
        res = *spices.rbegin();
      }
      else cout << *spices.rbegin() << endl;
      sum -= bales[back][0];
      spices.erase(spices.lower_bound(bales[back][1]));
      back++;
    }
  }
  cout << sum;
  fout << res << endl;
}
