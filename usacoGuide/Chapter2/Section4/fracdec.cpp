/*
ID: 06jajun
TASK: fracdec
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include <string>

using namespace std;

#define MXN 1e3+1
#define INF 1e9

ifstream fin ("fracdec.in");
ofstream fout ("fracdec.out");

int main() {
  int n, d;
  fin >> n >> d;
  string fans;
  string sans;
  map<int, int> visited;
  if (n>=d) fans = to_string(n/d) + ".";
  else fans = "0.";
  n %= d;
  string sn=to_string(n), sd=to_string(d);
  int pref = n*10;
  int add=0;
  int i=1;
  while (visited.find(pref) == visited.end() && pref > 0) {
    visited[pref] = i - 1; // 10 0 0
    add = pref / d;
    sans += add+'0';
    pref %= d;
    pref *= 10;
    i++;
  }
  if (pref == 0) {
    if (sans.length() == 0) {
      fout << fans << 0 << endl;
      return 0;
    }
    fout << fans << sans << endl;
  }
  else {
    int counter=1;
    for (auto x: fans) {
      fout << x;
      if (counter != 0 && counter % 76 == 0) fout << endl;
      counter ++;
    }
    for (int j=0; j<visited[pref]; j++) {
      fout << sans[j];
      if (counter != 0 && counter % 76 == 0) fout << endl;
      counter ++;
    }
    fout << '(';
    if (counter != 0 && counter % 76 == 0) fout << endl;
    counter ++;
    for (int j=visited[pref]; j<sans.length(); j++) {
      fout << sans[j];
      if (counter != 0 && counter % 76 == 0) fout << endl;
      counter ++;
    }
    fout << ')' << endl;
  }

}
