/*
ID: 06jajun
TASK: humble
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

#define MXK 100
#define MXN 100000
#define INF 1e18

int k, n;
int primes[MXK];
long long curr, cap=INF;
set<long long> humbles;
ifstream fin ("humble.in");
ofstream fout ("humble.out");

int main() {
  fin >> k >> n;
  for (int i=0; i<k; i++) {
    fin >> primes[i];
    humbles.insert(primes[i]);
  }
  sort(primes, primes + k);
  for (int i=0; i<n; i++) {
    curr = *humbles.begin();
    humbles.erase(*humbles.begin());
    if (humbles.size() > n - i) cap = *humbles.rbegin();
    for (int j=0; j<k; j++) {
      if (curr * primes[j] > cap) break;
      humbles.insert(curr * primes[j]);
      if (humbles.size() > MXN) humbles.erase(*humbles.rbegin());
    }
  }
  fout << curr << endl;
}
