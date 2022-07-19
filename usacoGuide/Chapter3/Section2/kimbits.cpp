/*
ID: 06jajun
TASK: kimbits
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#define MXN 32
#define MXL 32

int n, r, k;
int grid[MXN][MXL];
ifstream fin ("kimbits.in");
ofstream fout ("kimbits.out");

int main() {
  // Get inputs
  fin >> n >> r >> k;

  // Create prefices
  int i, j;
  for (i=0; i<MXN; i++) {
    grid[0][i] = 1;
    grid[i][0] = 1;
  }
  for (i=1; i<MXN; i++) for (j=1; j<MXN; j++) {
    grid[i][j] = grid[i - 1][j - 1] + grid[i][j - 1];
  }

  // for (int i=0; i<r+1; i++) {
  //   for (int j=0; j<n+1; j++) {
  //     cout << grid[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << grid[MXL-1][MXN-1];
  j=r;
  for (i=n; i>0; i--) {
    fout << ((i == 1 && j == 1) || (j>0 && grid[j][i - 1] < k));
    if (grid[j][i - 1] < k) {
      k -= grid[j][i - 1];
      j--;
    }
    // if (i == 1 && j == 1) {
    //   fout << "1";
    //   continue;
    // }
    // if (j == 0) {
    //   fout << "0";
    //   continue;
    // }
    // if (grid[j][i - 1] < k) {
    //   fout << "1";
    //   k -= grid[j][i - 1];
    //   j--;
    // } else {
    //   fout << "0";
    // }
  }
  fout << endl;
}
