/*
ID: 06jajun
TASK: sleepy
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 100000
#define INF 1000000000

int n;
int ps[MXN];
int bi[MXN+1];
ifstream fin ("sleepy.in");
ofstream fout ("sleepy.out");

int inc(int i) { for (i++; i<=n; i+=(i&-i)) bi[i]++;}
int add(int i) { int sum=0; for (i++; i>0; i-=(i&-i)) sum+=bi[i]; return sum;}

int main() {
  fin >> n;
  for (int i=0; i<n; i++) {
    fin >> ps[i];
  }

  int j = n - 1;
  inc(ps[j]);
  while (j > 0 && ps[j] > ps[j - 1]) {
    j--;
    inc(ps[j]);
  }
  fout << j << endl;

  for (int i=0; i<j; i++) {
    fout << j - i - 1 + add(ps[i]);
    if (i != j - 1) fout << ' ';
    inc(ps[i]);
  }
  fout << endl;
  return 0;
}
