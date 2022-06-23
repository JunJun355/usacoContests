/*
ID: 06jajun
TASK: sprime
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

#define MXN 100001
#define INF 1000000000

int m;
ifstream fin ("sprime.in");
ofstream fout ("sprime.out");

bool is_prime(int x) {
  if (x == 1) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (int i=3; i*i <= x; i+=2) {
    if (x % i == 0) return false;
  }
  return true;
}

void recurse(int s=0, int dep=0) {
  if (dep == m) {
    if (is_prime(s)) fout << s << endl;
    return;
  }
  for (int c=0; c < 10; c++) {
    s = 10*s + c;
    if (is_prime(s)) recurse(s, dep + 1);
    s = s / 10;
  }
}

int main()
{
  fin >> m;
  recurse();
}
