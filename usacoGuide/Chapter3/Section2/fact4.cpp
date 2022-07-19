/*
ID: 06jajun
TASK: fact4
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 1000
#define INF 1000000000

int n;
ifstream fin ("fact4.in");
ofstream fout ("fact4.out");

int main() {
  fin >> n;
  int a=1;
  int t=0;
  int m=n;
  while (m >= 5) {
    t += m / 5;
    m /= 5;
  }
  for (int i=2; i<=n; i++) {
    a *= i;
    if (t && i % 2 == 0) {
      a /= 2;
      t--;
    }
    while (a % 5 == 0) a /= 5;
    a %= 10;
  }
  fout << a << endl;
}
