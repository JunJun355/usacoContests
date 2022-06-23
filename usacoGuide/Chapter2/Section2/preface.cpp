/*
ID: 06jajun
TASK: preface
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

int n;
int Ig = 0, Vg = 0, Xg = 0, Lg = 0, Cg = 0, Dg = 0, Mg = 0;

void count(int x) {
    int I = 0, V = 0, X = 0, L = 0, C = 0, D = 0, M = 0;
    for ( ; x >= 1000; ++M, x -= 1000);
    for ( ; x >= 500; ++D, x -= 500);
    for ( ; x >= 100; ++C, x -= 100);
    for ( ; x >= 50; ++L, x -= 50);
    for ( ; x >= 10; ++X, x -= 10);
    for ( ; x >= 5; ++V, x -= 5);
    for ( ; x >= 1; ++I, x -= 1);

    while (D > 0 && (C / 4) > 0) {
	     --D; C -= 4;
       ++M;
       ++C;
    }
    while (C >= 4) {
    	C -= 4;
      ++C;
      ++D;
    }
    while (L > 0 && (X / 4) > 0) {
	     --L; X -= 4; ++C; ++X;
    }
    while (X >= 4) {
	     X -= 4; ++L; ++X;
    }
    while (V > 0 && (I / 4) > 0) {
	     --V; I -= 4; ++X; ++I;
    }
    while (I >= 4) {
	     I -= 4; ++V; ++I;
    }
    Ig += I;
    Vg += V;
    Xg += X;
    Lg += L;
    Cg += C;
    Dg += D;
    Mg += M;
    return;
}

int main() {
  ifstream fin ("preface.in");
  ofstream fout ("preface.out");
  fin >> n;

  for (int loop = 1; loop <= n; ++loop) {
    count(loop);
  }

  if (Ig != 0) {
    fout << 'I' << ' ' << Ig << endl;
  }
  if (Vg != 0) {
    fout << 'V' << ' ' << Vg << endl;
  }
  if (Xg != 0) {
    fout << 'X' << ' ' << Xg << endl;
  }
  if (Lg != 0) {
    fout << 'L' << ' ' << Lg << endl;
  }
  if (Cg != 0) {
    fout << 'C' << ' ' << Cg << endl;
  }
  if (Dg != 0) {
    fout << 'D' << ' ' << Dg << endl;
  }
  if (Mg != 0) {
    fout << 'M' << ' ' << Mg << endl;
  }
  fout.close();
}
