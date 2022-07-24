/*
ID: 06jajun
TASK: ratios
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;

#define MXN 1000
#define INF 1000000000

int Ds[4], Ms[4][3];
ifstream fin ("ratios.in");
ofstream fout ("ratios.out");

int my_min() {
  int m=Ds[0];
  for (int i=1; i<4; i++) {
    if (Ds[i] != 0) m = min(m, Ds[i]);
  }
  return m;
}

int det(int d=0) {
  // cout << endl;
  // Setup
  int ne[3][3];
  if (d == 0) {
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        ne[i][j] = Ms[i + 1][j];
      }
    }
  } else {
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        if (i == d - 1) {
          ne[i][j] = Ms[0][j];
          continue;
        }
        ne[i][j] = Ms[i + 1][j];
      }
    }
  }

  // for (int i=0; i<3; i++) {
  //   for (int j=0; j<3; j++) {
  //     cout << ne[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  // Find it
  int ans = 0;
   // Add
    for (int i=0; i<3; i++) {
      int a=1;
      for (int j=0; j<3; j++) {
        a *= ne[j][(i+j)%3];
        // cout << ne[j][(i+j)%3] << ' ';
      }
      ans += a;
      // cout << endl;
    }
   // Sub
    for (int i=0; i<3; i++) {
      int a=1;
      for (int j=0; j<3; j++) {
        a *= ne[j][(i-j+3)%3];
        // cout << ne[j][(i-j+3)%3] << ' ';
      }
      ans -= a;
      // cout << endl;
    }
  return ans;
}

int main() {
  // Get inputs
  for (int i=0; i<4; i++) {
    for (int j=0; j<3; j++) {
      fin >> Ms[i][j];
      // cout << Ms[i][j] << ' ';
    }
    // cout << endl;
  }

  // Find Determinants
  for (int i=0; i<4; i++) Ds[i] = det(i);

  // Reduce
  cout << Ds[1] << ' ' << Ds[2] << ' ' << Ds[3] << ' ' << Ds[0] << endl;
  int pos=0;
  int neg=0;
  for (int i=0; i<4; i++) {
    if (Ds[i] > 0) pos++;
    if (Ds[i] < 0) neg++;
  }
  if (pos == 0) {
    for (int i=0; i<4; i++) Ds[i] *= -1;
  } else if (neg != 0) {
    fout << "NONE" << endl;
    return 0;
  }
  for (int i=2; i<=my_min(); i++) {
    // cout << i << endl;
    bool t=true;
    for (int j=1; j<4; j++) {
      if (Ds[j] % i != 0) t = false;
    }
    if (t == true) {
      for (int j=0; j<4; j++) {
        Ds[j] /= i;
      }
      i = 1;
    }
    // cout << i << endl;
  }
  for (int i=1; i<4; i++) {
    if (Ds[i] >= 100) {
      fout << "NONE" << endl;
      return 0;
    }
  }
  fout << Ds[1] << ' ' << Ds[2] << ' ' << Ds[3] << ' ' << Ds[0] << endl;
}
